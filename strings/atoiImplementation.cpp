#include<bits/stdc++.h>
using namespace std;

int parseInt(string input){

	bool isNegative=false;

	if(input[0]=='-'){
		isNegative=true;
		input=input.substr(1); //Remove -ve sign
	}

	int ans=0;

	for(int i=0,j=pow(10,input.length()-1);i<input.length();i++,j=j/10){	//j is the place variable. Hundreds, tens, ones..
		ans=ans+((input[i]-'0')*j);	//input[i]-'0' helps convert char to int
	}

	if(isNegative){
		ans=ans*-1;
	}

	return ans;

}

int main(){

	cout<<parseInt("123")+1<<endl;
	return 0;
}