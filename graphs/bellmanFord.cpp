/*

>>Algorithm<<

>Have a hash map that stores distances to node i. distanceTo[startNode] must be 0

>Have a global flag called isChangeMade that will decide whether another iteration of bellman ford is required or not

>Iterate through all nodes. If node's distance is not infinite => Distance to this node had been computed. So go throught the connections
of this node. If distance to node + distance to connection < distanceTo[node's connection] => Update the hash map and set the flag to true,
indicating that a change has been made and that another bellman iteration is required

*/

#include<bits/stdc++.h>
using namespace std;

//Input
	//INT_MAX implies no edge exists
int graph[][5]={ 
	{INT_MAX,-1,2,INT_MAX,INT_MAX},
	{INT_MAX,INT_MAX,3,2,2},
	{INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
	{INT_MAX,1,5,INT_MAX,INT_MAX},
	{INT_MAX,INT_MAX,INT_MAX,-3,INT_MAX}
};
int startNode=0;
//......
int nodeCount=sizeof(graph)/sizeof(graph[0]);
bool isChangeMade=true;

map <int,int> distanceTo;

void runBellmanFord(){

	while(isChangeMade){
		isChangeMade=false;

		//Iterating through nodes
		for(int i=0;i<nodeCount;i++){
			if(distanceTo[i]==INT_MAX){ //Cost TO the current node itself not found => You can't process this node now
				continue;
			}

			//Iterating through the connections of node i
			for(int j=0;j<nodeCount;j++){

				//If an edge exists and the (distance to node i + edge weight)<distance to node j
				if((graph[i][j]!=INT_MAX)&&((distanceTo[i]+graph[i][j])<distanceTo[j])){
					isChangeMade=true; //Set flag
					distanceTo[j]=distanceTo[i]+graph[i][j]; //Update node j's distance
				}
			}

		}
	}

}

int main(){

	//Initialize all distances
	for(int i=0;i<nodeCount;i++){
		if(i==startNode){
			distanceTo[i]=0;
			continue;
		}
		distanceTo[i]=INT_MAX;
	}

	runBellmanFord();

	//View Distances
	for(int i=0;i<nodeCount;i++){
		cout<<"Distance to "<<i<<"= "<<distanceTo[i]<<endl;
	}
	
	return 0;
}