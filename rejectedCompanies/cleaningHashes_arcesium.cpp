#include<bits/stdc++.h>
using namespace std;

unordered_map < char,char > cleanedHash;
vector <char> first;
vector <char> second;


void cleanHash(){

	for(int i=0;i<first.size();i++){
		cleanedHash[first[i]]=second[i];
	}

	vector <char> stacker;
	stacker.push_back('\n'); //Stacker starts from index 1
	unordered_map <char,int> isSeen;

	char out;

	for(int i=0;i<first.size();i++){ //Iterate through all input chars

		stacker.push_back(first[i]);
		isSeen[first[i]]=stacker.size()-1;
		out=cleanedHash[first[i]];

		while(out!=NULL && isSeen[out]==0){ //build stack
			stacker.push_back(out);
			isSeen[out]=stacker.size()-1;
			out=cleanedHash[out];
		}
		if(out==NULL){ //Reached NULL => Point all stack elements to stackSize()-1 th element
			for(int j=1;j<stacker.size()-1;j++){
				cleanedHash[stacker[i]]=stacker[stacker.size()-1];
			}
		}
		else if(isSeen[out]!=0){ //Loop detected 
			for(int j=isSeen[out];j<stacker.size();j++){ //Delete all hashes of elements in the loop
				cleanedHash[stacker[j]]=NULL;
			}

			for(int j=1;j<isSeen[out];j++){ //Point all pre loop elements to first loop elements
				cleanedHash[stacker[j]]=stacker[isSeen[out]];
			}
		}

		stacker.clear();
		stacker.push_back('\n');
		isSeen.clear();
	}

}

void printHash(){
	for(int i=0;i<first.size();i++){
		cout<<first[i]<<" : "<<cleanedHash[first[i]]<<endl;
	}
}

int main(){

	//Input
	first.push_back('a');
	first.push_back('b');
	first.push_back('c');

	second.push_back('b');
	second.push_back('c');
	second.push_back('b');

	cleanHash();
	printHash();
}