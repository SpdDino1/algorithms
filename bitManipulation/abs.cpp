#include<bits/stdc++.h>
using namespace std;

int main(){
	int a=-1;

	// residue = -1(-ve nos) or 0(+ve nos)
	int residue=a>>31;

	//2's complement on residue
	int minusOne=-1;
	int toAdd= (residue ^ minusOne)+1; //1 (-ve nos) or 0 (+ve nos)

	int absAns=(a ^ residue)+toAdd;

	cout<<absAns<<endl;

	return 0;
}