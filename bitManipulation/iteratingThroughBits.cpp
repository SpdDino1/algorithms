#include<bits/stdc++.h>
using namespace std;

void iterateThroughBits(unsigned int num){

	unsigned int mask=1,temp;

	while(num){
		temp=num&mask;
		cout<<temp<<endl;
		num=num>>1;
	}
}

int main(){
	unsigned int a=7;
	iterateThroughBits(a);

	return 0;
}