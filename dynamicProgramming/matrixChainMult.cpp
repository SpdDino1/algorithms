#include<bits/stdc++.h>
using namespace std;

//Input
int arr[] = {1, 2, 3, 4};
int size = (sizeof(arr)/sizeof(arr[0]));
//......

vector <int> matrixIndexVector; //[0,1,2] 

vector < vector<int> > computeMatrix; 

void initializeComputeMatrix(){
	vector <int> temp;

	for(int i=0;i<size-1;i++){
		temp.push_back(INT_MAX); 
	}
	
	for(int i=0;i<size-1;i++){
		computeMatrix.push_back(temp);
	}

	for(int i=0;i<size-1;i++){
		computeMatrix[i][i]=0;
	}
}

void initializeMatrixIndex(){
	for(int i=0;i<size-1;i++){
		matrixIndexVector.push_back(i);
	}
}

void findMinMultChain(int chainLength){
	int partitionTill,localCost;

	for(int i=0;i<matrixIndexVector.size();i++){//Forming sets of chainLength
		partitionTill=i+chainLength-1;

		if(partitionTill<matrixIndexVector.size()){	//Finding all possible possibilities within the formed set

			for(int j=i;j<partitionTill;j++){

				// [a,b,c,d,e,f]
				//  a=i[Left boundary]   ;   d=partitionTill[Right boundary]   j=a,b,c [Iterates and helps form all cases]

				//cost = cost of left partition(already found) + cost of right partition(already found) + currentMultCost
						//currentMultCost = m1(m of left partition matrix) * n1(n of left) * n2 (n of right)
				localCost=computeMatrix[i][j]+computeMatrix[j+1][partitionTill]+(arr[i]*arr[j+1]*arr[partitionTill+1]);
				computeMatrix[i][partitionTill] = min(computeMatrix[i][partitionTill],localCost);
			}

		}

	}

	if(chainLength!=(size-1)){
		findMinMultChain(++chainLength);
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
	initializeMatrixIndex();

	findMinMultChain(2); //Start with chain length 2 => 2 matrices at a time

	cout<<"Min Operations = "<<computeMatrix[0][computeMatrix.size()-1]<<endl;
	printComputeMatrix();
	return 0;
}