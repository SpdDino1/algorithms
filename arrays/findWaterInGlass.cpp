/*

>>Problem<<

https://www.geeksforgeeks.org/find-water-in-a-glass/

>>Algorithm<<

>Similar to pascal's triangle. Maintain 2 vectors, out of which one is temp. For every entry in mainVector, add an (overflow amount/2) to 
temp[i] and temp[i+1]

*/

#include<bits/stdc++.h>
using namespace std;

//Inputs start from 0
int row=2; 
int glass=2;
int netWaterPoured=5;
//......

vector <float> prevRow;
vector <float> temp;

void findWater(){

	int currentRowindex=1; //Starting from row 2 (index 1)
	bool isNoMoreWater=false;

	float overflowAmount;

	while((!isNoMoreWater)&&(currentRowindex!=(row+1))){
		isNoMoreWater=true;

		//Appending 0 to temp
		for(int i=0;i<=currentRowindex;i++){
			temp.push_back(0);
		}

		for(int i=0;i<prevRow.size();i++){
			overflowAmount=prevRow[i]-1; // netWater - 1 litre glass capacity = overflow amount

			if(overflowAmount!=0){ //Water present in next level => don't break loop
				isNoMoreWater=false;
			}

			temp[i]=temp[i]+overflowAmount/2;
			temp[i+1]=temp[i+1]+overflowAmount/2;
		}

		prevRow=temp;
		temp.clear();

		currentRowindex++;

	}

	if(currentRowindex!=(row+1)){//prevRow != 'row' => 'row' is never reached
		cout<<"Water Amount= 0"<<endl;
	}
	else{ //prevRow is 'row'
		if(prevRow[glass]>1){ //Water still left to overflow from 'row'
			cout<<"Water Amount= 1"<<endl;
		}
		else{
			cout<<"Water Amount= "<<prevRow[glass]<<endl;
		}
	}

}

int main(){
	
	prevRow.push_back(netWaterPoured); //First glass of row 1
	findWater();

	return 0;
}