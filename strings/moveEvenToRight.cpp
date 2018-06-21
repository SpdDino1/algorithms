#include<bits/stdc++.h>
using namespace std;

//Input
string inputWord="a1b2c3d4e5f6g7h8i9j1k2l3m4";
//.....

void transform(){
	int end=inputWord.length()-1;

	string temp;

	for(int i=1;i<=end;i++){
		temp=inputWord[i]; //Store Char
		inputWord=inputWord.substr(0,i)+inputWord.substr(i+1); //Remove char
		inputWord=inputWord+temp;//Append char to end

		end--;
	}
}

int main(){
	
	transform();
	cout<<inputWord<<endl;

	return 0;
}