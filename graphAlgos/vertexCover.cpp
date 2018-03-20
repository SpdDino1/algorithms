#include<bits/stdc++.h>
using namespace std;

//Input........
/*int graph[][6]={
	{0,1,0,0,1,1},
	{1,0,1,0,0,0},
	{0,1,0,1,0,0},
	{0,1,1,0,1,0},
	{1,0,0,1,0,1},
	{1,0,0,0,1,0}
};*/
int graph[][4]={
	{0,1,1,1},
	{1,0,1,1},
	{1,1,0,1},
	{1,1,1,0}
};
//.............
int size = sizeof(graph)/sizeof(graph[0]);
vector <struct vertex> sortedVertices;
map <int,int> coveredVertices;

struct vertex{
	int index;
	int edgeCount;
};

bool sortMech(struct vertex a,struct vertex b){
	return a.edgeCount>b.edgeCount;
}

int coveredVerticesCount=0;

void findVertexCover(){
	if(coveredVerticesCount>=size){
		cout<<endl;
		return;
	}

	struct vertex currentVertex = sortedVertices[0];
	sortedVertices.erase(sortedVertices.begin(),sortedVertices.begin()+1);

	int isVertexCovering=false;

	for(int i=0;i<size;i++){
		if((graph[currentVertex.index][i]==1)&&(coveredVertices[i]==-1)){
			isVertexCovering=true;
			coveredVertices[i]=1;
			coveredVerticesCount++;
		}
	}
	if(isVertexCovering){
		coveredVertices[currentVertex.index]=1;
		coveredVerticesCount++;
		cout<<currentVertex.index<<" ";
	}

	findVertexCover();
}

int main(){
	//Initializing sortedVertices + coveredVertices
	int count;
	struct vertex temp;
	for(int i=0;i<size;i++){

		coveredVertices[i]=-1;

		count =0;
		temp.index = i;
		for(int j=0;j<size;j++){
			if(graph[i][j]==1){
				count++;
			}
		}
		temp.edgeCount = count;
		sortedVertices.push_back(temp);
	}

	sort(sortedVertices.begin(),sortedVertices.end(),sortMech);

	cout<<"Vertex Cover Set :"<<endl;
	findVertexCover();
}