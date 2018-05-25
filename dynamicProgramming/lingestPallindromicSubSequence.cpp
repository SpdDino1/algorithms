/*
	Logic

A pallindrome is of the form a.....a. So, if you ask me what is the max length of the pallindromic subsequence between a....a,
I know that the left and right 'a's alone form a pallindromic subsequence of length 2. 

Hence max length = 2 + max length of pallindromic subsequence in ..... [The middle portion]

But if teh string were a...b, then i know that a and b won't form a pallindromic sequence.

Here max length = Max (pallindromic sequence in a... , Pallindromic sequence in ...b )

So this approach requires me to find the max subsequences in all possible sub strings of all possible lengths from 1 to wordLength-1

	Table Structure

Table is of wordLength-1 x wordLength-1 size

table[i][j] => Max length of pallindromic subsequence from i to j

*/

#include<bits/stdc++.h>
using namespace std;

//Input
string word = "geeksforgeeks";
//......

int wordLength;

vector < vector<int> > computeMatrix; 

void initializeComputeMatrix(){
	wordLength=word.length();

	vector <int> temp;

	for(int i=0;i<wordLength;i++){
		temp.push_back(0); 
	}
	
	for(int i=0;i<wordLength;i++){
		computeMatrix.push_back(temp);
	}

	for(int i=0;i<wordLength;i++){
		computeMatrix[i][i]=1; //The same letter is a pallindrome of length 1 itself
	}
}

void findLongestSubSequence(int sequenceLength){

	for(int l=0,r=l+sequenceLength-1;r<wordLength;l++,r++){

		if(word[l]==word[r]){
			//If l==r => You have a pallindromice subsequence word[l]+word[r]
			// So you add 2 to the pallindromic sequence in between these letters
			//    a (Pallindromic Sequence Here already computed) a
			computeMatrix[l][r]= computeMatrix[l+1][r-1]+2;
		}
		else{
			//If l!=r => You don't have a pallindromic sub sequence that includes l and r
			//So you check the max pallindromic sequence with l and with r individually
			// max( l.... , .....r); Those 2 would have already been computed
			computeMatrix[l][r]=max(computeMatrix[l+1][r],computeMatrix[l][r-1]);
		}

	}

	if((++sequenceLength)!=(wordLength+1)){
		findLongestSubSequence(sequenceLength);
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

	findLongestSubSequence(2);

	cout<<"Length of Max Pallindromic Subsequence = "<<computeMatrix[0][wordLength-1]<<endl;

	printComputeMatrix();
}