#include<iostream>
#include<vector>
using namespace std;

int findRotationPoint(vector<int> vect){
	int l = 0;
	int r = vect.size()-1;
	int mid = (l+r)/2;
	int midElement;

	while(mid!=0){
		midElement = vect[mid];

		if(midElement<vect[mid-1]){
			return mid;
		}

		if((vect[l]<midElement)&&(midElement<vect[r])){
			r =mid-1;
		}
		else{
			l = mid +1;
		}

		mid = (l+r)/2;
	}
	return -1;
}

int main(){
	vector<int> mainVect = {10,11,12,13,14,15,0};

	int rotationPoint = findRotationPoint(mainVect);
	cout<<"Point = "<<rotationPoint<<endl;
	return 1;
}