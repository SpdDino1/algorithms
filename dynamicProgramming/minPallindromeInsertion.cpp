/*

>>Logic<<

>A pallindrome is essentially of the form a......a recursively. So if you ask me what is the min insertions to pallindromize abcde,
i'll break it into sub problems.

So i could either add an 'a' to the right [a.....a completed] and check the cost to pallindromize bcde, or i could add an 'e' to the left
[e.....e completed] and check cost to pallindromize abcd

So i need to find costs of pallindromizing all sub strings. 

>>Table Structure<<

>Table is of wordLength X wordLength size. 

computeMatrix[x][y] stores the number of insertions to pallindromize substring from x to y (Both included).

So you initialize all computeMatrix[a][a]=0 as cost of pallindromizing 1 letter =0

Then find all insertions required starting from substring length = 2,3,4.....

computeMatrix[0][lastIndex] = Answer

*/

#include<bits/stdc++.h>
using namespace std;

//Input
string word="abcde";
//
int wordLength;

vector < vector<int> > computeMatrix;

void initializeComputeMatrix(){
	vector <int>temp;

	wordLength = word.length();

	for(int i=0;i<wordLength;i++){
		temp.push_back(0);
	}

	for(int i=0;i<wordLength;i++){
		computeMatrix.push_back(temp);
	}	

	for(int i=0;i<wordLength;i++){
		computeMatrix[i][i]=0; //Insertions for one letter to be pallindrome =0 as 1 letter itself is a pallindrome
	}		
}

void computeMinInsertions(int subStringLength){
	int localInsertionCount;

	for(int l=0,r=l+subStringLength-1;r<wordLength;l++,r++){//Creates all possible substrings of length subStringLength in given word
		localInsertionCount=0;

		if(word[l]!=word[r]){
			//If the terminal letters [a.....b] are not same => You will have to add either an 'a' to the right or a 'b' to the left
			//So increase localCount by 1
			//If the terminal letters are same [a....a], then localCount remains 0.
			localInsertionCount=1;
		}
		//I can either add an 'a' to the right and add the insertions to pallindromize [.....b]
		//or i can add a 'b' to the left and add the insertions to pallindromize [a.....]

		//Net cost = min(Above 2 costs)+localInsertionCost
		computeMatrix[l][r]=min(computeMatrix[l+1][r],computeMatrix[l][r-1])+localInsertionCount;
	}

	if((++subStringLength)<=wordLength){
		computeMinInsertions(subStringLength);
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

	computeMinInsertions(2);
	printComputeMatrix();

	cout<<"Min Insertions = "<<computeMatrix[0][wordLength-1]<<endl;
}