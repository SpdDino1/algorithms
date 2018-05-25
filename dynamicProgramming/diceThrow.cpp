/*
	Logic

Number of ways of reaching 6 with 5 dice can be found out if you tell me for what are the different ways of representing each 
value [1,2,3,4,5,6] using 5 dice. Hence there are overlapping problems and optimal sub structures.

Hence we require the different ways of representing all values from 1 to targetSum.

	Table Structure

The table has columns from 1 to targetSum.

The table has noOfFaces*noOfDice rows. Hence each row represents a face of die 'n'

die1 1
die1 2
die1 3
die1 4
die1 5
die1 6
die2 1
die2 2
die2 3
die2 4
die2 5
die2 6
....
*/

#include<bits/stdc++.h>
using namespace std;

//Input
int noOfDice =3; 
int noOfFaces=6;
int targetSum=8;
//.....

vector < vector<int> > computeMatrix; 

void initializeComputeMatrix(){
	vector <int> temp;
	vector <int> firstRow;

	//Preparing first row of die 1 = 1 1 1 1 1 1
	for(int i=0;i<targetSum;i++){
		temp.push_back(0);
		if(i<(noOfFaces)){
			firstRow.push_back(1);
		} 
		else{
			firstRow.push_back(0);
		}
	}


	//Pushes first row 'noOfFaces' times into compute matrix.
	//This is done to make finding startIndex of every other die easier
	for(int i=0;i<noOfFaces;i++){
		computeMatrix.push_back(firstRow);
	}
	
	for(int i=1;i<noOfDice;i++){
		for(int j=0;j<noOfFaces;j++){
			computeMatrix.push_back(temp);
		}
	}
}

void findNoOfWays(int dieNo){
	cout<<dieNo<<endl;

	int startIndex=(dieNo-1)*6;
	int currentFaceValue=1;

	//First Row of dice dieNo. This fills the row for its first face 1
	for(int i=0;i<targetSum;i++){
		if(i<(dieNo-1)){
			//If the value is less than the dieNo => There are more number of dice than the value => It is impossible to represent
			//that value

			//for example you can't represent 1 with 2 dice. The min you can represent is 2 and above

			//Hence you store as 0 ways
			computeMatrix[startIndex][i]=0;
		}
		else{
			//If you can represent a number with help from the other die (Showing the remaining number) => You have the other number
			// of ways of representing the current number. 

			// Die 5 can represent 3 in 3 ways.
			//Your currently being processed die 6 can represent 3 as 1(current die) + 2(Previous die) => there are 3 ways of representing
			// 3
			computeMatrix[startIndex][i]=computeMatrix[startIndex-1][i-currentFaceValue];
		}
	}

	cout<<"First Row Complete"<<endl;

	currentFaceValue++;

	for (int i=startIndex+1; i<(startIndex+6); i++,currentFaceValue++){

		for(int j=0;j<targetSum;j++){
			if(j<currentFaceValue){
				//If number<currentFaceValue =>Simply copy above cell's ways =>No change
				computeMatrix[i][j]=computeMatrix[i-1][j];
			}
			else{
				//Let's say your current die can represent 8 as 2(From current die)+6(Previous die) =>The net way depends on the ways 6
				//can be represented.

				//Hence your net ways of now representing 8 = Net ways for 6 from previous die + The answer in the above cell.
				
				//The above cell stores the ways of representing that number using another face. So now you add on to that number of ways
				//with your new way 

				computeMatrix[i][j]=computeMatrix[i-1][j]+computeMatrix[startIndex-1][j-currentFaceValue];
			}
		}
	}

	if((++dieNo)<=noOfDice){
		findNoOfWays(dieNo);
	}	

}

void printComputeMatrix(){
	for(int i=0;i<computeMatrix.size();i++){
		for(int j=0;j<computeMatrix[i].size();j++){
			cout<<computeMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	
	initializeComputeMatrix();

	findNoOfWays(2);

	cout<<"No of Ways = "<<computeMatrix[computeMatrix.size()-1][computeMatrix[0].size()-1]<<endl;

	printComputeMatrix();

	return 0;
}