#include<bits/stdc++.h>
using namespace std;

//Input
vector < vector<int> > subVectors;
//....
vector <int> sortedAnswer;

struct heapElement{
	int subVectorIndex;
	int valueIndex;
};

vector <struct heapElement*> minHeap;

void minHeapify(int pos){

	int leftChildPos = 2*pos;
	int rightChildPos = leftChildPos+1;

	int leftChildValue,rightChildValue;
	int currentValue=subVectors[minHeap[pos]->subVectorIndex][minHeap[pos]->valueIndex];

	struct heapElement* temp;

	if(rightChildPos<minHeap.size()){ //Both children present
		leftChildValue=subVectors[minHeap[leftChildPos]->subVectorIndex][minHeap[leftChildPos]->valueIndex];
		rightChildValue=subVectors[minHeap[rightChildPos]->subVectorIndex][minHeap[rightChildPos]->valueIndex];

		if(leftChildValue<rightChildValue){	
			if(currentValue>leftChildValue){ //Replace root with leftChild

				temp=minHeap[pos];
				minHeap[pos]=minHeap[leftChildPos];
				minHeap[leftChildPos]=temp;

				minHeapify(leftChildPos);
			}
		}
		else{
			if(currentValue>rightChildValue){ //Replace root with rightChild

				temp=minHeap[pos];
				minHeap[pos]=minHeap[rightChildPos];
				minHeap[rightChildPos]=temp;

				minHeapify(rightChildPos);
			}
		}	

	}
	else if((leftChildPos<minHeap.size())&&(currentValue>leftChildValue)){ //Only left present and currentValue>leftChildValue
		temp=minHeap[pos];
		minHeap[pos]=minHeap[leftChildPos];
		minHeap[leftChildPos]=temp;
		minHeapify(leftChildPos);
	}

	return;
}

void buildMinHeap(){

	//Pushes first element of all subVectors and 'builds'  the minHeap

	struct heapElement* temp;

	for(int i=0;i<subVectors.size();i++){//Iterate through subVectors
		temp=new struct heapElement;

		temp->subVectorIndex=i;
		temp->valueIndex=0; //First value pushed

		minHeap.insert(minHeap.begin(),temp); //Add as root of heap

		minHeapify(0); //heapify from root
	}

}

void updateRootOfHeap(){

	minHeap[0]->valueIndex++; //Get next value from sub vector

	if(minHeap[0]->valueIndex == subVectors[minHeap[0]->subVectorIndex].size()){ //subVector exhausted
		minHeap.erase(minHeap.begin(),minHeap.begin()+1); //Delete heap node
	}

	minHeapify(0); //reorder heap with new root
	
}

void startKWayMerge(){

	int rootValue;

	while(minHeap.size()!=0){

		rootValue=subVectors[minHeap[0]->subVectorIndex][minHeap[0]->valueIndex]; //Extracting root from minHeap
		sortedAnswer.push_back(rootValue);

		updateRootOfHeap();

	}

}

int main(){
	
	vector <int> temp;
	//initializing vectors
	temp.push_back(30);
	temp.push_back(40);
	temp.push_back(50);
	subVectors.push_back(temp);
	temp.clear();

	temp.push_back(35);
	temp.push_back(45);
	subVectors.push_back(temp);
	temp.clear();

	temp.push_back(10);
	temp.push_back(60);
	temp.push_back(70);
	temp.push_back(80);
	temp.push_back(100);
	subVectors.push_back(temp);
	temp.clear();
	//...................

	buildMinHeap();
	startKWayMerge();

	for(int i=0;i<sortedAnswer.size();i++){
		cout<<sortedAnswer[i]<<" ";
	}	
	cout<<endl;

	return 0;
}