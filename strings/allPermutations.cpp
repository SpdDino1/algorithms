#include<bits/stdc++.h>
using namespace std;

//Input
string inputWord="ABC";
//.....

string stringStack="";

string getSubString(string currentWord,int excluding){
	string toSend="";

	for(int i=0;i<currentWord.length();i++){
		if(i==excluding){
			continue;
		}

		toSend+=currentWord[i];
	}

	return toSend;
}

void permute(string word){

	if(word.length()==0){
		cout<<stringStack<<endl;
	}

	for(int i=0;i<word.length();i++){
		stringStack=stringStack+word[i];	//Append last char
		permute(getSubString(word,i));
	}

	stringStack=getSubString(stringStack,stringStack.length()-1); //Remove last char

}

int main(){
	
	permute(inputWord);
	return 0;
}