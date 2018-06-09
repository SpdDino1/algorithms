#include<bits/stdc++.h>
using namespace std;

map<int,int> testMap;

int main(){
	
	//Populating map
	testMap[1]=1;
	testMap[2]=2;
	testMap[3]=3;
	testMap[4]=4;
	testMap[5]=5;

	for(map<int,int>::iterator i=testMap.begin();i!=testMap.end();i++){
		cout<<i->first<<" => "<<i->second<<endl;
	}

	return 0;
}