/*

>>Problem<<

https://www.geeksforgeeks.org/find-number-of-islands/

>>Algorithm<<

>Have a hash map that maps between int (node) and bool (isVisited)

>Iterate through nodes and find the first unvisited node. Run a dfs on it and mark every visited node in the hash map.
Whenever the dfs breaks, check if all nodes have been visited. If not, then increment a global count and start dfs on the next unvisited 
node.

*/


#include<bits/stdc++.h>
using namespace std;

//Input
int graph[][6]={
	{0,1,1,0,0,0},
	{1,0,1,0,0,0},
	{1,1,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,1},
	{0,0,0,0,1,0},
};
//......
int nodeCount=sizeof(graph)/sizeof(graph[0]);

int componentCount=0;

map <int,bool> isVisited;

int getUnivisitedNode(){
	for(int i=0;i<nodeCount;i++){
		if(!isVisited[i]){
			return i;
		}
	}
	return -1;
}

void runDfs(int startNode){
	vector <int> dfsStack;
	int topOfStack;

	//Put connections of start node into stack
	for(int i=0;i<nodeCount;i++){
		if(graph[startNode][i]==1){
			dfsStack.push_back(i);
		}
	}

	//Mark start node visited
	isVisited[startNode]=true;

	while(dfsStack.size()!=0){
		topOfStack=dfsStack[dfsStack.size()-1];
		isVisited[topOfStack]=true; //Top of stack node marked visited
		dfsStack.pop_back();

		//Iterate through topOfStack's nodes to find connnections
		for(int i=0;i<nodeCount;i++){
			if((graph[topOfStack][i]==1)&&(!isVisited[i])){ //Check if connection is already visited
				dfsStack.push_back(i);
			}
		}

	}
}

void countComponentsInGraph(){
	int unvisitedNode=getUnivisitedNode();

	while(unvisitedNode!=-1){
		componentCount++;
		runDfs(unvisitedNode);
		unvisitedNode=getUnivisitedNode();
	}	

}

int main(){
	countComponentsInGraph();
	cout<<"Components= "<<componentCount<<endl;
	return 0;
}