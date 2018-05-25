#include<bits/stdc++.h>
using namespace std;

struct Point{
    float x, y;
};

vector <struct Point> pointsSortedInX;
vector <struct Point> pointsSortedInY;

bool customSortBasedOnX(struct Point a,struct Point b){
	return a.x<b.x;
}
bool customSortBasedOnY(struct Point a,struct Point b){
	return a.y<b.y;
}

float findDistanceBetweenPoints(struct Point a,struct Point b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

float min(float a,float b){
	if(a<b){
		return a;
	}
	return b;
}

//Recursive Function
float findClosestPair(vector <struct Point> sortedInX,vector <struct Point> sortedInY){

	//Recursion Termination Condition
	if(sortedInX.size()==1){
		return 999.0; //Assume 999 = Infinity
	}

	//Divide
		//Preparing Params
	vector <struct Point> leftSideSortedInX,rightSideSortedInX;
	vector <struct Point> leftSideSortedInY,rightSideSortedInY;

	int mid=sortedInX.size()/2;
	float midX=sortedInX[mid].x;

	for(int i=0;i<mid;i++){	//Preparing left side x
		leftSideSortedInX.push_back(sortedInX[i]);
	}

	for(int i=mid;i<sortedInX.size();i++){ //preparing right side x
		rightSideSortedInX.push_back(sortedInX[i]);
	}

	for(int i=0;i<sortedInY.size();i++){	//Preparing left+right side y
		if(sortedInY[i].x<midX){
			leftSideSortedInY.push_back(sortedInY[i]);
		}
		else{
			rightSideSortedInY.push_back(sortedInY[i]);
		}
	}

		//Calls
	float leftSideLeastDistance=findClosestPair(leftSideSortedInX,leftSideSortedInY);
	float rightSideLeastDistance=findClosestPair(rightSideSortedInX,rightSideSortedInY);

	//Conquer [Find min(leftSide,RightSide,Across)]

		//Search for any dist that is less than min(leftSide,rightSide) that spans across mid point
	float minDistance = min(leftSideLeastDistance,rightSideLeastDistance);

		//Checking Across Mid 
	for(int i=0;i<sortedInY.size()-1;i++){

		//Check if Point falls within 'strip' [Only on the basis of y coordinate]
		if((sortedInY[i].x>(midX-minDistance))&&(sortedInY[i].x<(midX+minDistance))){

			int j=i+1;
			while((j<sortedInY.size())&&(abs(sortedInY[i].y-sortedInY[j].y)<minDistance)){
				minDistance=min(findDistanceBetweenPoints(sortedInY[i],sortedInY[j]),minDistance);
				j++;
			}

		}
	}

	return minDistance;
}

int main(){

	//Initializing Question
	struct Point temp;
	temp.x=2.0;
	temp.y=3.0;
	pointsSortedInX.push_back(temp);
	pointsSortedInY.push_back(temp);

	temp.x=12.0;
	temp.y=30.0;
	pointsSortedInX.push_back(temp);
	pointsSortedInY.push_back(temp);


	temp.x=40.0;
	temp.y=50.0;
	pointsSortedInX.push_back(temp);
	pointsSortedInY.push_back(temp);

	temp.x=5.0;
	temp.y=1.0;
	pointsSortedInX.push_back(temp);
	pointsSortedInY.push_back(temp);

	temp.x=12.0;
	temp.y=10.0;
	pointsSortedInX.push_back(temp);
	pointsSortedInY.push_back(temp);

	temp.x=3.0;
	temp.y=4.0;
	pointsSortedInX.push_back(temp);
	pointsSortedInY.push_back(temp);
	//...................

	sort(pointsSortedInX.begin(),pointsSortedInX.end(),customSortBasedOnX);
	sort(pointsSortedInY.begin(),pointsSortedInY.end(),customSortBasedOnY);

	cout<<findClosestPair(pointsSortedInX,pointsSortedInY)<<endl;;

	return 0;
}