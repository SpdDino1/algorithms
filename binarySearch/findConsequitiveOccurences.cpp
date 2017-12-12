#include<iostream>
#include<vector>
using namespace std;

int findStart(vector<int>vect,int key){
	int mid;
	int r = vect.size()-1;
	int l=0;
	int store=-1;

	while(r>=l){
		mid=(l+r)/2;

		if(vect[mid]<key){
			l = mid+1;
		}
		else{
			r = mid-1;
		}

		if(vect[mid]==key){
			store = mid;
		}
	}

	if(store>=0){
		return store;
	}
	else{
		return -1;
	}
}

int findEnd(vector<int>vect,int key){
	int mid;
	int r = vect.size()-1;
	int l=0;
	int store = -1;

	while(r>=l){
		mid=(l+r)/2;

		if(vect[mid]<=key){
			l = mid+1;
		}
		else{
			r = mid-1;
		}

		if(vect[mid]==key){
			store = mid;
		}
	}

	if(store>=0){
		return store;
	}
	else{
		return -1;
	}
}



int main(){

	vector<int> mainVect = {1,2,3,3,3,4,4,5};

	int key;
	cout<<"Enter Key = ";
	cin>>key;
	cout<<endl;

	int start = findStart(mainVect,key);
	int end = findEnd(mainVect,key);

	if(start ==-1){
		cout<<"Occurences = "<<0;
	}
	else{
		cout<<"Occurences = "<<((end-start)+1);
	}
	return 1;
}