/*

>>Algorithm<<

>We append the leftmost point (wrt to x axis) to the hull array. This point has to be part of the hull...in fact all extreme points must
This point is then removed from points array

>We then pick index 0 of the points array and check whether all other points lie to the left of it. We do this by creating 2 vectors. One 
from the last picked hull point to index 0, and the other from the last picked hull point to whichever point you want to check if is on
the left. Upon performing a cross product, if the product is positive => it is on the left [Recall left hand thumb rule].
If for all points this is positive => index 0 is a hull point. Remove it from points[] and push it to hullPoints[]
If it isn't a hull point, go to the next index and do the same process....

>After a search iteration, we should check if the end can be reached. The end of the hull is the last edge that connects the last picked
hull point to the start point of the hull. So to check if an end is possible, we must set the target point to the start point and check
if all the remaining points in the points[] lie to the left of start point's vector [from last picked hull point]. If yes => Hull complete
Else, increment search index and continue searching 

*/

#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

//Input
vector <struct Point*> points;
//.....

vector <struct Point*> partOfHull;

void findAndAddLeftMostPoint(){

	//Adds the leftmost point to the hull

	int leftMost=INT_MAX;
	int leftMostIndex;

	for(int i=0;i<points.size();i++){
		if(points[i]->x < leftMost){  
			leftMost=points[i]->x;
			leftMostIndex=i;
		}
	}


	partOfHull.push_back(points[leftMostIndex]); //Add left most point to vector
	points.erase(points.begin()+leftMostIndex,points.begin()+leftMostIndex+1); //remove from points
}

bool isOnLeftOfTarget(struct Point* targetPoint, struct Point* otherPoint){

	//Performs a cross product to check if otherPoint is on left or right of targetPoint

	struct Point* prevHullPoint = partOfHull[partOfHull.size()-1];

	struct Point* targetVector = new struct Point; //Vector from prevHull Point to targetPoint
	targetVector->x = targetPoint->x - prevHullPoint->x;
	targetVector->y = targetPoint->y - prevHullPoint->y;

	struct Point* otherVector = new struct Point; //Vector from prevHull Point to otherPoint
	otherVector->x = otherPoint->x - prevHullPoint->x;
	otherVector->y = otherPoint->y - prevHullPoint->y;

	// Angle from targetVector to other vector => If otherVector is on left of targeVector, according to right hand thumb rule, vector is 
	// out of page => positive answer
	int crossProduct = (targetVector->x * otherVector->y)-(otherVector->x * targetVector->y); 


	if(crossProduct>=0){
		return true;
	}
	return false;
	
}

bool checkIfHullComplete(){

	//Purposely checks if startPoint can be the target now. This is only possible if the rest of the hull is complete as the last
	// edge connects the start point to the hull 

	if(partOfHull.size()<3){ //hull needs minumum 3 points
		return false;
	}

	struct Point* startPoint = partOfHull[0];

	for(int i=0;i<points.size();i++){
		if(!isOnLeftOfTarget(startPoint,points[i])){ //Point on right => Target cannot be part of Hull
			return false;
		}
	}

	return true;

}

void findConvexHull(){

	bool isHullComplete = false,isTargetPartOfHull;

	int targetPointIndex=0; 

	while(!isHullComplete){

		isTargetPartOfHull=true;

		//Iterating through 'other' points
		for(int i=0;i<points.size();i++){
			if(!isOnLeftOfTarget(points[targetPointIndex],points[i])){ //Point on right => Target cannot be part of Hull
				isTargetPartOfHull=false;
				break;
			}
		}

		if(isTargetPartOfHull){ //All points lie on left
			partOfHull.push_back(points[targetPointIndex]); //Add to hull
			points.erase(points.begin()+targetPointIndex,points.begin()+targetPointIndex+1); //Remove from points[]
			targetPointIndex=0; //Restart search
		}
		else{
			targetPointIndex++;
		}

		isHullComplete = checkIfHullComplete();
	}
}

int main(){

	struct Point* temp=new struct Point;
	//Initializing vector
	temp->x=0;
	temp->y=3;
	points.push_back(temp);
	temp=new struct Point;
	temp->x=2;
	temp->y=2;
	points.push_back(temp);
	temp=new struct Point;
	temp->x=1;
	temp->y=1;
	points.push_back(temp);
	temp=new struct Point;
	temp->x=2;
	temp->y=1;
	points.push_back(temp);
	temp=new struct Point;
	temp->x=0;
	temp->y=0;
	points.push_back(temp);
	temp=new struct Point;
	temp->x=3;
	temp->y=3;
	points.push_back(temp);
	temp=new struct Point;
	temp->x=3;
	temp->y=0;
	points.push_back(temp);
	//...............

	findAndAddLeftMostPoint();
	findConvexHull();

	//Print hull points
	for(int i=0;i<partOfHull.size();i++){
		cout<<"("<<partOfHull[i]->x <<","<<partOfHull[i]->y <<")"<<endl; 
	}
}