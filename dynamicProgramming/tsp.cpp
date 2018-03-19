//tsp

#include<bits/stdc++.h>
using namespace std;

//Input .......
int costMat[][4]={
	{1,2,3,4},
	{5,6,7,8},
	{3,4,5,6},
	{9,8,4,3}
};
//.............
int size = sizeof(costMat)/sizeof(costMat[0]);
vector <int> minPath;
int minCost=9999;

vector <int> localPath;
int localMinCost;

void findMinPath(vector <int> cities){
	if(cities.size()==0){
		if((localMinCost+costMat[localPath[localPath.size()-1]][localPath[0]])<minCost){
			minPath.clear();
			minPath = localPath;
			minPath.push_back(localPath[0]);
			minCost = localMinCost+costMat[localPath[localPath.size()-1]][localPath[localPath[0]]];
		}
		/*for(int i=0;i<localPath.size();i++){ //Debug
			cout<<localPath[i]<<" ";
		}
		cout<<"Cost = "<<localMinCost+costMat[localPath.size()-1][localPath[0]]<<endl;*/
		return;	
	}

	for(int i=0;i<cities.size();i++){
		localPath.push_back(cities[i]);
		cities.erase(cities.begin()+i,cities.begin()+i+1);
		if(localPath.size()==1){
			localMinCost=0;
		}
		else{
			localMinCost+=costMat[localPath[localPath.size()-2]][localPath[localPath.size()-1]];
		}

		/*cout<<"Forward"<<" "; //Debug
		for(int z=0;z<localPath.size();z++){ 
			cout<<localPath[z]<<" ";
		}
		cout<<"Cost = "<<localMinCost<<endl;
		//..................................*/

		findMinPath(cities);

		//Reverting Changes
		if(localPath.size()!=1){
			localMinCost-=costMat[localPath[localPath.size()-2]][localPath[localPath.size()-1]];
		}
		cities.insert(cities.begin()+i,localPath[localPath.size()-1]);
		localPath.pop_back();

		/*cout<<"Backward"<<" "; //Debug
		for(int z=0;z<localPath.size();z++){ 
			cout<<localPath[z]<<" ";
		}
		cout<<"Reverted Cost = "<<localMinCost<<endl; //Debug
		//..................................*/
	}
}

int main(){
	vector <int> allCities;
	for(int i=0;i<size;i++){
		allCities.push_back(i);
	}

	findMinPath(allCities);

	cout<<"Min. Path :"<<endl;
	for(int i=0;i<minPath.size();i++){
		cout<<minPath[i]<<" ";
	}
	cout<<endl;	

	cout<<"\nMin Cost = "<<minCost<<endl;
}