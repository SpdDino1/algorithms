/*
Algo

>Find the greatest descendant for a given node. Set that as left child [Or NULL if none found]. 
	>>Recursively call buildTree() for left node

	>>Find second largest descendant for a given node. Set that as right child[Or NULL if none found]
		>>>Recursively call buildTree() for right child

**If there is no left child => there is no right child as left child will not be there only if no descendants are present =>leaf**

*/

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* globalRoot;

//Input.........................................
int ancestorMatrix[6][6]= {{ 0, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 0 }
};
//..............................................
int ancestorMatrixSize=sizeof(ancestorMatrix)/sizeof(ancestorMatrix[0]);

vector < vector<int> > globalSortedDescendants;

//Utility Function
void printInorder(struct node* currentNode){
	if(currentNode->left!=NULL){
		printInorder(currentNode->left);
	}

	cout<<currentNode->data<<" ";
	
	if(currentNode->right!=NULL){
		printInorder(currentNode->right);
	}
}
//..........................................

bool customSort(vector <int> a, vector <int> b){
	if(a[1]>b[1]){
		return true;
	}
	return false;

}

void prepareGlobalSortedDescendants(){

	vector <int> temp; //matrixIndex, noOfDescendants
	int count=0;

	for(int i=0;i<ancestorMatrixSize;i++){
		count=0;
		temp.clear();
		for(int j=0;j<ancestorMatrixSize;j++){
			if(ancestorMatrix[i][j]==1){
				count++;
			}
		}
		temp.push_back(i);
		temp.push_back(count);
		globalSortedDescendants.push_back(temp);
	}	

	sort(globalSortedDescendants.begin(),globalSortedDescendants.end(),customSort);

}

int findHighestDescendant(int descendants[]){

	for(int i=0;i<globalSortedDescendants.size();i++){
		if(descendants[globalSortedDescendants[i][0]]){// check if matrixIndex is a descendant
			return globalSortedDescendants[i][0]; //return matrixIndex of that descendant
		}
	}
	return -1;
}

struct node* buildTree(int currentNodeIndex, int descendants[]){
	struct node* newNode=new struct node;
	newNode->data=currentNodeIndex;

	int leftChildMatrixIndex=findHighestDescendant(descendants);
	if(leftChildMatrixIndex==-1){ //No descendants found
		newNode->left=NULL;
		newNode->right=NULL;
	}
	else{
		newNode->left=buildTree(leftChildMatrixIndex,ancestorMatrix[leftChildMatrixIndex]);

		descendants[leftChildMatrixIndex]=0;

		int rightChildMatrixIndex=findHighestDescendant(descendants);
		if(rightChildMatrixIndex==-1){
			newNode->right=NULL;
		}
		else{
			newNode->right=buildTree(rightChildMatrixIndex,ancestorMatrix[rightChildMatrixIndex]);
		}
	}

	return newNode;

}

int main(){

	prepareGlobalSortedDescendants();

	globalRoot=buildTree(globalSortedDescendants[0][0],ancestorMatrix[globalSortedDescendants[0][0]]);

	printInorder(globalRoot);
	cout<<endl;

}