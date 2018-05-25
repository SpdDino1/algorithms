/*
	Logic

Max profit from chainLength of n = max(pick leftmost +max of remaining, pick rightmost+ max of remaining)
Hence i need to know the max profits of all possible sub lengths from 1 to n

	Table Structure

Table is of size chainLength*chainLength
chainLength[i][j] = Max profit from i to j in chain
*/

#include<bits/stdc++.h>
using namespace std;

//Input
int arr[] = {8, 15, 3, 7};
//.......
int size;

vector < vector<int> > computeMatrix; 

void initializeComputeMatrix(){
	size = sizeof(arr)/sizeof(arr[0]);

	vector <int> temp;

	for(int i=0;i<size;i++){
		temp.push_back(0); 
	}
	
	for(int i=0;i<size;i++){
		computeMatrix.push_back(temp);
	}
}

void findMaxMoney(int coinLength){

	if((coinLength%2)==1){//Odd length length => Enemy's turn to pick
		for(int l=0,r=l+coinLength-1;r<size;l++,r++){//Creates sets of size coinLength
			//Assume coin change to be 'a b c d e' 
			//Max profit from l to r for me= min(b c d e, a b c d); 
			//The 3 chained length was already pre computed. bcde is if enemy picks leftmost and abcd if he picks rightmost coin.
			//I get min as enemy is also said to be smart and i have to print 'guaranteed' min 
			computeMatrix[l][r]=min(computeMatrix[l+1][r],computeMatrix[l][r-1]);
		}
	}
	else{ //Even length => My turn to pick
		//Assume coin change to be 'a b c d' 
		//Max profit from l to r = max(a+'b c d','a b c' + d)
		//The 3 chain length was already precomputed and i get max as this is my turn.
		for(int l=0,r=l+coinLength-1;r<size;l++,r++){//Creates sets of size coinLength
			computeMatrix[l][r]=max(arr[l]+computeMatrix[l+1][r],computeMatrix[l][r-1]+arr[r]);
		}
	}

	if((++coinLength)!=size+1){
		findMaxMoney(coinLength);
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

	findMaxMoney(2);

	cout<<"Max Guaranteed = "<<computeMatrix[0][size-1]<<endl;

	printComputeMatrix();

	return 0;
}