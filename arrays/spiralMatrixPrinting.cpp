#include<bits/stdc++.h>
using namespace std;

struct corner{
	int row;
	int col;
};

//Input
int const r=3;
int const c=6;
int arr[r][c]={
{1,  2,  3,  4,  5,  6},
{7,  8,  9,  10, 11, 12},
{13, 14, 15, 16, 17, 18}
};
//.........

void printSpirally(){

	struct corner* topLeft=new struct corner;
	topLeft->row=0;
	topLeft->col=0;

	struct corner* bottomRight=new struct corner;
	bottomRight->row=r-1;
	bottomRight->col=c-1;

	while((topLeft->row <= bottomRight->row)&&(topLeft->col <= bottomRight->col)){

		for(int i=topLeft->col;i <= bottomRight->col;i++){ //Top Edge
			cout<<arr[topLeft->row][i]<<" ";
		}

		for(int i=topLeft->row+1;i<=bottomRight->row;i++){ //Right edge
			cout<<arr[i][bottomRight->col]<<" ";
		}

		if(topLeft->row != bottomRight->row){
			for(int i=bottomRight->col-1;i >= topLeft->col;i--){ //Bottom Edge
				cout<<arr[bottomRight->row][i]<<" ";
			}
		}

		if(topLeft->col != bottomRight->col){
			for(int i=bottomRight->row-1;i>topLeft->row;i--){ //Left edge
				cout<<arr[i][topLeft->col]<<" ";
			}
		}

		topLeft->row++;
		topLeft->col++;

		bottomRight->row--;
		bottomRight->col--;

	}

	cout<<endl;	

}

int main(){
	
	printSpirally();

	return 0;
}