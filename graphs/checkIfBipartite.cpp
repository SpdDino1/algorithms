/*\

>>Problem<<

https://www.geeksforgeeks.org/bipartite-graph/

>>Algorithm<<

>Have 2 hash maps called isInSet1 and isInSet2. For every node that you are entering, check whether it fits into set1. To do this iterate
through its connections and ensure that none of its connections are in set1. If they are, then iterate again and check in set2. If they are 
in set2 too => Not Bipartite. 

>>!! This algo only works for undirectional graphs. For directional graphs, you'll have to run through the process again once the graph
has been split into 2 sets. This is because if A->B, then while processing A, B would not be in set1. And while processing B, B won't check
if A is in set1 as the edge is from A to B. 

>>Another solution is to convert directional graphs to undirectional graphs to force 2 way checks. This would allow you to not go through
the whole process again once split...

*/

#include<bits/stdc++.h>
using namespace std;

//Input
int graph[][4] = {{0, 1, 0, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 1, 0}
};
//.....
int nodeCount=sizeof(graph)/sizeof(graph[0]);

map <int,bool> isNodeInSet1;
map <int,bool> isNodeInSet2;

void checkIfBipartite(){

	bool isInSet1;

	for(int i=0;i<nodeCount;i++){

		isInSet1=true;

		for(int j=0;j<nodeCount;j++){
			if((graph[i][j]==1)&&(isNodeInSet1[j])){
				isInSet1=false;
				break;
			}
		}

		if(isInSet1){
			isNodeInSet1[i]=true;
			continue;
		}

		for(int j=0;j<nodeCount;j++){
			if((graph[i][j]==1)&&(isNodeInSet2[j])){
				cout<<"Not Bipartite"<<endl;
				return;
			}
		}

		isNodeInSet2[i]=true;

	}

	cout<<"Bipartite"<<endl;

}

int main(){
	
	checkIfBipartite();
	return 0;
}
