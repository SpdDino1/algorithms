/*

>>Problem<<

https://www.geeksforgeeks.org/detect-cycle-undirected-graph/

>>Algorithm<<

We use DFS here too to find the cycle. But since this is an undirected graph => if there exists an edge form A to B, while performing DFS
there will obviously be a back edge from B to A. This musn't be interpreted as a cycle. 

Hence we push a struct into the dfs stack, rather then just a mere node number. The struct holds the currentNode it points to and the node's
parent. So while iterating for connections of this node, we exclude the parent and don't consider it a cycle.

*/

#include<bits/stdc++.h>
using namespace std;

//Input
int graph[][5]={
	{0,1,1,1,0},
	{1,0,1,0,0},
	{1,1,0,0,0},
	{1,0,0,0,1},
	{0,0,0,1,0}
};
//......
int nodeCount=sizeof(graph)/sizeof(graph[0]);

struct stackElement{
	int currentNode;
	int fromNode;
};

map <int,bool> isVisited;

void runUndirectedDfs(int startNode){
	vector <struct stackElement*> dfsStack;
	struct stackElement* pushTemp;

	struct stackElement* currentTemp;

	isVisited[startNode]=true; //Mark startNode as visited

	//Push startNode's connections to stack
	for(int i=0;i<nodeCount;i++){
		if(graph[startNode][i]!=0){
			pushTemp=new struct stackElement;
			pushTemp->currentNode=i;
			pushTemp->fromNode=startNode;
			dfsStack.push_back(pushTemp);
		}	
	}

	while(dfsStack.size()!=0){
		currentTemp=dfsStack[dfsStack.size()-1];
		isVisited[currentTemp->currentNode]=true; //Mark visited
		dfsStack.pop_back();

		//Iterate through currentTemp's connections
		for(int i=0;i<nodeCount;i++){
			if(graph[currentTemp->currentNode][i]!=0){
				if(isVisited[i]){ //Already visited connection
					if(currentTemp->fromNode==i){ 
						continue; //It's okay....it was just the parent
					}
					else{
						cout<<"Cycle present"<<endl;
						return;
					}
				}
				else{ //Not visited connection => Push to stack
					pushTemp=new struct stackElement;
					pushTemp->currentNode=i;
					pushTemp->fromNode=currentTemp->currentNode;
					dfsStack.push_back(pushTemp);
				}
			}	
		}		
	}

	cout<<"No cycles"<<endl;

}

int main(){
	
	runUndirectedDfs(4);

	return 0;
}