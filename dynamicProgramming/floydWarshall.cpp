//floydWarshall

//Assume 999 = INF

#include<bits/stdc++.h>
using namespace std;

//Input ...........
int arr[][4]={{0,5,999,10},
{999,0,3,999},
{999,999,0,1},
{999,999,999,0} 
};
//.................
int size = sizeof(arr)/sizeof(arr[0]);

void printGraph(){
	cout<<"Shortest Path Matrix: "<<endl;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

void runFloydWarshall(int index){
	if(index>=size){
		printGraph();
		return;
	}

	for(int i=0;i<size;i++){
		if(i==index){
			continue;
		}

		for(int j=0;j<size;j++){
			if(j==index){
				continue;
			}

			arr[i][j] = min(arr[i][j],arr[i][index]+arr[index][j]);
		}
	}
	runFloydWarshall(++index);
}

int main(){
	runFloydWarshall(0);
}