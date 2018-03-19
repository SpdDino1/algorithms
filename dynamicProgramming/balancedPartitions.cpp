//balancedPartitions

#include<bits/stdc++.h>
using namespace std;

//input.......
int arr[] = {5,1,7,11};
//............
int size = sizeof(arr)/sizeof(arr[0]);

int sum = 0;
int midSum;

vector <vector<bool> > partitionTable;

void printPartitionTable(){
	for(int i=0;i<partitionTable.size();i++){
		for(int j=0;j<partitionTable[i].size();j++){
			cout<<partitionTable[i][j]<<" ";
		}
		cout<<endl;
	}
}

void findMinImbalance(){
	int maxPartitionSum=0;

	for(int i=0;i<partitionTable[partitionTable.size()-1].size();i++){
		if(partitionTable[partitionTable.size()-1][i]){
			maxPartitionSum = i;
		}
	}

	int otherPartitionSum = sum - maxPartitionSum;

	cout<<"Min. Difference = "<<abs(maxPartitionSum - otherPartitionSum)<<endl;
}

void fillPartitionTable(int index){
	if(index >= size){
		findMinImbalance();
		return;
	}
	else if(index==0){ //First row of table
		for(int i=0;i<partitionTable[index].size();i++){
			if(arr[index]==i){
				partitionTable[index][i] = true;
				break;
			}		
		}
	}
	else{ //other table rows
		for(int i=0;i<partitionTable[index].size();i++){
			if(arr[index]==i){
				partitionTable[index][i] = true;
			}
			else if((i-arr[index])>=0){
				partitionTable[index][i] = max(partitionTable[index][i],partitionTable[index-1][i-arr[index]]);
				partitionTable[index][i] = max(partitionTable[index][i],partitionTable[index-1][i]);
			}
			else{
				partitionTable[index][i] = max(partitionTable[index][i],partitionTable[index-1][i]);	
			}
		}
	}
	fillPartitionTable(++index);
}

int main(){

	//finding sum
	for(int i=0;i<size;i++){
		sum = sum+arr[i];
	}
	midSum = sum/2;

	//initializing partitionTable
	vector <bool> temp;
	for(int i=0;i<=midSum;i++){
		temp.push_back(false);
	}

	for(int i=0;i<size;i++){
		partitionTable.push_back(temp);
	}

	fillPartitionTable(0);
}