#include<bits/stdc++.h>
using namespace std;

//Input
char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
int freq[] = { 5, 9, 12, 13, 16, 45 };
//......
int size=sizeof(arr)/sizeof(arr[0]);

struct heapElement{
	bool isInternalNode=false;
	char letter;
	int frequency;
	struct heapElement* left;
	struct heapElement* right;
};

vector <struct heapElement*> huffmanTree;

void swapElements(int indexA,int indexB){
	struct heapElement* temp=huffmanTree[indexA];
	huffmanTree[indexA]=huffmanTree[indexB];
	huffmanTree[indexB]=temp;
}

void minHeapify(int pos){

	int leftChildPos=(2*pos),rightChildPos=leftChildPos+1;
	int leftChildValue,rightChildValue,currentValue=huffmanTree[pos]->frequency;

	if(rightChildPos<huffmanTree.size()){ //Both children exist
		leftChildValue=huffmanTree[leftChildPos]->frequency;
		rightChildValue=huffmanTree[rightChildPos]->frequency;

		if((leftChildValue<rightChildValue)&&(leftChildValue<currentValue)){ //leftChildValue <currentValue
			swapElements(pos,leftChildPos);
			minHeapify(leftChildPos);
		}
		else if((leftChildValue>rightChildValue)&&(rightChildValue<currentValue)){ //rightChildValue <currentValue
			swapElements(pos,rightChildPos);
			minHeapify(rightChildPos);
		}
	}
	else if((leftChildPos<huffmanTree.size())&&(leftChildValue<currentValue)){ //Left child only
		swapElements(pos,leftChildPos);
		minHeapify(leftChildPos);
	}

	return;
}

void buildMinHeap(){

	struct heapElement* temp;

	for(int i=0;i<size;i++){
		temp=new struct heapElement;
		temp->letter=arr[i];
		temp->frequency=freq[i];

		huffmanTree.insert(huffmanTree.begin(),temp);

		minHeapify(0);
	}	

}

void startCompression(){

	struct heapElement* firstLeast;
	struct heapElement* secondLeast;
	struct heapElement* temp;

	while(huffmanTree.size()!=1){
		firstLeast=huffmanTree[0]; //Extract first least freq letter
		huffmanTree.erase(huffmanTree.begin(),huffmanTree.begin()+1);
		minHeapify(0);

		secondLeast=huffmanTree[0]; //Extract second least freq letter
		huffmanTree.erase(huffmanTree.begin(),huffmanTree.begin()+1);

		temp=new struct heapElement; //Creating new internalNode comprising of both first and second least
		temp->isInternalNode=true;
		temp->frequency=firstLeast->frequency + secondLeast->frequency; //Add up frequencies of firstLeast + secondLeast
		temp->left=	firstLeast;
		temp->right=secondLeast;

		huffmanTree.insert(huffmanTree.begin(),temp); //Insert new node as root
		minHeapify(0); //Reorganize heap	
	}
}

void traverseTree(struct heapElement* currentNode,string huffmanCode){

	if(currentNode->isInternalNode){ //Has left and right children && No code for internal node
		traverseTree(currentNode->left,huffmanCode+"0");
		traverseTree(currentNode->right,huffmanCode+"1");
	}
	else{ // Has no children && Has code for itself
		cout<<currentNode->letter<<" : "<<huffmanCode<<endl;
	}

}

int main(){
	
	buildMinHeap();

	startCompression();

	traverseTree(huffmanTree[0],"");
	
	return 0;
}