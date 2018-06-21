/*

'a'=97
'A'=65

=> 'a'-'A'=32

Hence by adding 32 to any capital alphabet, you can get it's small letter

*/

#include<bits/stdc++.h>
using namespace std;

string convertToLower(string input){

	for(int i=0;i<input.length();i++){
		if(('A'<=input[i])&&(input[i]<='Z')){ //Capital to small range
			input[i]=input[i]+32; //Convert to small
		}
	}
	return input;
}

int caseInsensitiveStrCmp(string s1,string s2){

	if(s1.length()<s2.length()){
		return 1;
	}
	else if(s1.length()>s2.length()){
		return -1;
	}

	s1=convertToLower(s1);
	s2=convertToLower(s2);

	for(int i=0;i<s1.length();i++){
		if(s1[i]<s2[i]){
			return -1;
		}
		else if(s1[i]>s2[i]){
			return 1;
		}

	}

	return 0;

}

int main(){
	
	cout<<caseInsensitiveStrCmp("GeeksforGeeks", "geeksforgeeks")<<endl;
	return 0;
}