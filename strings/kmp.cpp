#include<bits/stdc++.h>
using namespace std;

//Input
string mainString="AABAACAADAABAABA";
string pattern="AABA";
//.........

vector <int> prefixArray;

void preparePrefixArray(){

	//Initializing Vector with Dummy elements
	for(int i=0;i<pattern.length();i++){
		prefixArray.push_back(0);
	}

	int l=0,r=1;

	while(r<pattern.length()){

		if(pattern[l]==pattern[r]){
			prefixArray[r]=l+1;
			l++;
			r++;
			continue;
		}

		if(l==0){
			prefixArray[r]=0;
			r++;
		}
		else{
			l=prefixArray[l-1];	
		}

	}
}

void printPrefixArray(){
	for(int i=0;i<prefixArray.size();i++){
		cout<<prefixArray[i]<<" ";
	}
	cout<<endl;
}

void matchPattern(){

	int mainStringPointer=0,patternPointer=0;

	while(mainStringPointer<mainString.length()){

		if(patternPointer==0){
			if(mainString[mainStringPointer]==pattern[patternPointer]){ //Match started
				patternPointer++;
			}
			mainStringPointer++;
		}
		else{
			if(mainString[mainStringPointer]==pattern[patternPointer]){
				if(patternPointer==(pattern.length()-1)){ //Match complete
					cout<<(mainStringPointer-pattern.length()+1)<<" "<<mainStringPointer<<endl;
					patternPointer=0;
				}
				else{	//Pattern building
					mainStringPointer++;
					patternPointer++;
				}
			}
			else{ //Pattern character mismatch => Check prefix Array
				patternPointer=prefixArray[patternPointer-1];
			}
		}

	}

}

int main(){
	
	preparePrefixArray();
	//printPrefixArray();
	matchPattern();

	return 0;
}