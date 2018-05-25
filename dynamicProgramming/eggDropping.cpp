/*
	Logic

Min ways of dropping 2 eggs and 36 floors = min(Dropping 1 egg from floor1,egg 1 from floor2, .....)
Each of those cases would further break down into more cases

	Table Structure

Col = No. of floors [1,2,3.....]

Row = Egg no [1,2..]

Hence the table stores all min cases of dropping any number of eggs from any floor.

*/

#include<bits/stdc++.h>
using namespace std;

//Input
int eggs=2;
int floors=6;
//.....

vector < vector<int> > computeMatrix; 

void initializeComputeMatrix(){

	vector <int> temp;

	for(int i=0;i<floors+1;i++){
		temp.push_back(INT_MAX); 
	}

	temp[0]=0; //For any number of eggs, if floor=0 => 0 attempts required
	
	for(int i=0;i<eggs+1;i++){
		computeMatrix.push_back(temp);
	}

	for(int i=1;i<floors+1;i++){
		computeMatrix[1][i]=i; //Initializing first row. With 1 egg and n floors, min attempts = n
	}
}

void findMinWays(int eggNumber){

	for(int i=1;i<=floors;i++){
		//For a given egg, it creates all possible sets of floors
		// 1 floor, 2floors, 3 floors
		if(i<eggNumber){
			//If no. of eggs exceeds the number of floors, simply copy the above cell's ways
			computeMatrix[eggNumber][i]=computeMatrix[eggNumber-1][i];
			continue;
		}

		for(int j=1;j<=i;j++){//Chooses the floor to drop egg from [1,2,3....i]
			//If egg is dropped from floor j, it may break or not.
			//If egg breaks => Ans = 1+Min ways for 1 egg and j-1 floors
			//If egg doesnt break => Ans = 1+Min ways for 2 eggs and i-j
			//Net ans = min(Current Cell value, max(above 2 possibilities))
			
			//We take max inside as we choose the worst possible outcome from our decision to throw egg from floor j
			computeMatrix[eggNumber][i]=min(computeMatrix[eggNumber][i],max(1+computeMatrix[eggNumber-1][j-1],1+computeMatrix[eggNumber][i-j]));
		}

	}

	if((++eggNumber)<=eggs){
		findMinWays(eggNumber);
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

	findMinWays(2); //Finding with 2 eggs

	//cout<<"Min Ways = "<<computeMatrix[computeMatrix.size()-1][computeMatrix[0].size()-1]<<endl;

	printComputeMatrix();

	return 0;
}