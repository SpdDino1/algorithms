/*

Algorithm

>This is a divide and conquer approach. Here the alrgest area is decided by the max(leftArea,rightArea,overlappingMidArea)

To find the overlapping mid area, you store the mid index's height [You would have found mid to perform the recursive left and right call] 
and iterate leftwards till you reach the leftmost index or you encounter a bar with height lower than mid. Store this extreme left value.

Similarly find extreme right value. 

midArea = midHeight * (extremeRight-extremeLeft+1)

The idea is to set the height of the rectangle to mid's height and try to find the largest length possible by moving left and right.

>>This approach works as every node is given a chance to be a mid at some point of time. So it's like DynamicProgramming...except that you
don't store all intermediate results

*/

#include<bits/stdc++.h>
using namespace std;

//Input
int heights[]={6,2,5,4,5,1,6};
//............
int heightsSize=sizeof(heights)/sizeof(heights[0]);

int findMaxAreaRectangle(int l,int r){

	//Only 1 bar
	if(l==r){
		return heights[l];
	}

	int mid=(l+r)/2;
	
	//Left, right recursive calls
	int leftArea=findMaxAreaRectangle(l,mid);
	int rightArea=findMaxAreaRectangle(mid+1,r);

	//Overlapping/Boundary case
	int leftBoundaryLimit=mid,rightBoundaryLimit=mid;

		//Finding leftBoundaryLimit
	for(int i=mid-1;i>=l;i--){
		if(heights[mid]<=heights[i]){
			leftBoundaryLimit=i;
		}
		else{
			break;
		}
	}

		//Finding rightBoundaryLimit
	for(int i=mid+1;i<=r;i++){
		if(heights[mid]<=heights[i]){
			rightBoundaryLimit=i;
		}
		else{
			break;
		}
	}

	int midArea=heights[mid]*(rightBoundaryLimit-leftBoundaryLimit+1);

	return max(leftArea,max(rightArea,midArea));

} 

int main(){
	cout<<findMaxAreaRectangle(0,heightsSize-1)<<endl;
	return 0;
}