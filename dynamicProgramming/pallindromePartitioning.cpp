/*
	
	Logic

A pallindrome is of the form a.....a. So if you give me a string a....a, the terminal letters are same. Hence i'll check if the middle 
string's partition count ==1. If it is 1 => middle is also a pallindrome => Whole string is a pallindrome.

If not, i'll try to find min (all possible sub partitions). abcd => a/bcd , ab/cd , abc/d

Hence for this approach i reaqure the partition count of all possible substrings. 

	Table Structure

Table is of wordLength-1 x wordLength-1 size

table[i][j] => Max length of pallindromic subsequence from i to j

*/

#include<bits/stdc++.h>
using namespace std;

//Input
string word = "ababbbabbababa";
//......

int wordLength;

vector < vector<int> > computeMatrix; 

void initializeComputeMatrix(){
	wordLength=word.length();

	vector <int> temp;

	for(int i=0;i<wordLength;i++){
		temp.push_back(INT_MAX); 
	}
	
	for(int i=0;i<wordLength;i++){
		computeMatrix.push_back(temp);
	}

	for(int i=0;i<wordLength;i++){
		computeMatrix[i][i]=1; //The same letter is a pallindrome of length 1 itself
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

void findMinPartitions(int substringLength){

	if(substringLength==2){

		for(int l=0,r=l+1;r<wordLength;r++,l++){
			if(word[l]==word[r]){
				//If l==r for 2 letter word =>Pallindrome
				computeMatrix[l][r]=1;
			}
			else{
				//If l!=r for 2 letter word => Not Pallindrome
				computeMatrix[l][r]=2;
			}
		}

	}
	else{

		for(int l=0,r=l+substringLength-1;r<wordLength;r++,l++){ //Creates all sub strings of given length substringLength

			if((word[l]==word[r])&&(computeMatrix[l+1][r-1]==1)){
				//If l==r and the middle section's partition count =1 (Middle already computed and is a pallindrome) => full string is a 
				// pallindrome
				//Hence the whole thing can be a single partition
				computeMatrix[l][r]=1;
			}
			else{
				//If l!=r => Full string cannot be a pallindrome
				//Hence here all sub partitions are considered to find the one that causes least partitioning of full string

				// Ex string = abcd => a/bcd , ab/cd , abc/d . Substrings of length <4 are already computed in previous iterations
				for(int subPartitionTill=l;subPartitionTill<r-1;subPartitionTill++){
					computeMatrix[l][r]=min(computeMatrix[l][r],computeMatrix[l][subPartitionTill]+computeMatrix[subPartitionTill+1][r]);
				}

			}
		}

	}

	if((++substringLength)!=(wordLength+1)){
		findMinPartitions(substringLength);
	}

}


int main(){
	initializeComputeMatrix();

	findMinPartitions(2);

	cout<<"Min Partitions Needed = "<<computeMatrix[0][wordLength-1]<<endl;

	printComputeMatrix();
}