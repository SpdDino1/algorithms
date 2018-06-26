/*

>>Algorithm<<

>Find XOR of full array. Now this XOR has x^y, where x and y are the unpaired elements. This XOR has the bits set that are either in x or y
but not in both.

>Let's extract the rightmost high bit from the answer (num & ~(num-1)). Now separate the given arr into 2 groups, depending on whether
the found bit is set or not. Hence x and y get separated.

>Now once again find the xor of these 2 individual arrays and you get x and y separately


*/

#include<bits/stdc++.h>
using namespace std;

//Input
int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};
//......
int size=sizeof(arr)/sizeof(arr[0]);

void findSingleElements(){

	//Finding full XOR of array
	int fullXor=0;
	for(int i=0;i<size;i++){
		fullXor=fullXor^arr[i];
	}

	//Getting rightmost 1
	fullXor=fullXor & ~(fullXor-1);

	//Separating into 2 groups
	vector <int> rightmostUnset;
	vector <int> rightmostSet;

	for(int i=0;i<size;i++){
		if(fullXor & arr[i]){ //Bit set
			rightmostSet.push_back(arr[i]);
		}
		else{//Bit unset
			rightmostUnset.push_back(arr[i]);	
		}
	}

	//Finding x
	int element1=0;

	for(int i=0;i<rightmostUnset.size();i++){ //Contains 9
		element1=element1 ^ rightmostUnset[i];
	}

	//Finding y
	int element2=0;

	for(int i=0;i<rightmostSet.size();i++){
		element2=element2 ^ rightmostSet[i];
	}

	cout<<"Elements= "<<element1<<" "<<element2<<endl;

}

int main(){
		
	findSingleElements();
	return 0;
}