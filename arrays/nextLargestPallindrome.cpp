#include<bits/stdc++.h>
using namespace std;

//Input
string input="94187978322";
//.....

vector <int> number;

void vectorify(){

	for(int i=0;i<input.length();i++){
		number.push_back(input[i]-'0');
	}

}

void findNextBigPallindrome(){

	bool incrementNext=false;
	int l,r,mid;

	if((number.size()%2)==1){ //Odd Length Case

		mid=number.size()/2;
		l=mid;
		r=mid;

		for(r=r,l=l;r<number.size();r++,l--){
			if(r==mid){
				if(number[mid]==9){
					number[mid]=0;
					incrementNext=true;
				}
				else{
					number[mid]++;
				}
			}
			else{
				if(incrementNext){
					incrementNext=false;

					if(number[l]==9){
						incrementNext=true;
						number[l]=0;
						number[r]=0;
					}
					else{
						number[l]++;
						number[r]=number[l]; //Copy left to right
					}

				}
				else{
					number[r]=number[l]; //copy left to right
				}
			}
		}

	}
	else{ //Even length case

		mid=number.size()/2;
		l=mid-1;
		r=mid;

		for(r=r,l=l;r<number.size();r++,l--){

			cout<<"r= "<<r<<" l= "<<l<<endl;

			if((l==mid-1)&&(r==mid)){//Both are max...make zero and set flag
				if((number[l]==9)&&(number[r]==9)){
					number[l]=0;
					number[r]=0;
					incrementNext=true;
				}
				else{//Simply make centre numbers max(centreLeft,centreRight)
					if(number[l]==number[r]){ 
						number[l]++;
						number[r]++;
					}
					else{
						number[l]=max(number[l],number[r]); 
						number[r]=max(number[l],number[r]);
					}
				}
			}
			else{
				if(incrementNext){
					incrementNext=false;
					
					if(number[l]==9){
						number[l]=0;
						number[r]=0;
						incrementNext=true;
					}
					else{
						number[l]++;
						number[r]=number[l];
					}
				}
				else{
					number[r]=number[l];
				}
			}
		}

	}

	if(incrementNext){
		incrementNext=false;
		number.insert(number.begin(),1);//Insert 1
		number[number.size()-1]=1;//Set last digit to 1
	}

}

int main(){

	vectorify();

	findNextBigPallindrome();

	for(int i=0;i<number.size();i++){
		cout<<number[i];
	}
	cout<<endl;

	return 0;
}