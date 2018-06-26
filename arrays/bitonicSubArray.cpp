/*

https://www.geeksforgeeks.org/maximum-length-bitonic-subarray

>>Algorithm<<

>Start traversing the array from left to right from index 1. Have a flag called 'isIncreasing' set to true. Let global start and end be
initialized to index 0.

>As long as arr[i-1]<arr[1], localEnd++ as the sequence is increasing. The moment the condition fails, set isIncreasing = false.
As long as the sequence is decreasing now, keep localEnd++

>The momen the condition fails,
	>Update global vars
	>Reset localEnd and localStart to current violated index of i
	>set isIncreasing = true
	>Start next loop from this violating index itself

*/

#include<bits/stdc++.h>
using namespace std;

//Input
int arr[]={40,30,20,10};
//.....
int size=sizeof(arr)/sizeof(arr[0]);

int start=0,end=0;

void findMaxBitonic(){

	bool isIncreasing=true;

	int localStart=0,localEnd=0;

	for(int i=1;i<size;i++){

		if(isIncreasing){
			if(arr[i-1]<=arr[i]){
				localEnd++;
			}
			else{
				isIncreasing=false;
				localEnd++;
			}
		}
		else{
			if(arr[i-1]<=arr[i]){ //Bitonic range broken
				isIncreasing=true; 

				if((localEnd-localStart)>(end-start)){ //Updating global vars
					end=localEnd;
					start=localStart;
				}

				i--; //Start from same i next round

				localStart=i; //Reset local variables for next range
				localEnd=i;
			}
			else{
				localEnd++;
			}
		}

	}

	if((localEnd-localStart)>(end-start)){ //Updating global vars [After loop break]
		end=localEnd;
		start=localStart;
	}

}

int main(){
	
	findMaxBitonic();
	cout<<"Start= "<<start<<" end= "<<end<<" size= "<<(end-start+1)<<endl;
	return 0;
}