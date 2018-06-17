#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root;

map <int,int> verticalSums;
int minHorizontalDistance=0,maxHorizontalDistance=0;

//Utility Function
void insertNode(int val){

	if(root==NULL){
		//First node 
		root=new struct node;
		root->data=val;
		root->left=NULL;
		root->right=NULL;
		return;
	}

	struct node* currentNode=root;

	struct node* newNode=new struct node;
	newNode->data=val;
	newNode->left=NULL;
	newNode->right=NULL;

	while(true){

		if(val<currentNode->data){
			//Left sub tree
			if(currentNode->left==NULL){
				currentNode->left=newNode;
				cout<<"Node Inserted to the left of "<<currentNode->data<<endl;
				return;
			}
			else{
				currentNode=currentNode->left;
			}

		}
		else{
			//Right sub tree
			if(currentNode->right==NULL){
				currentNode->right=newNode;
				cout<<"Node Inserted to the right of "<<currentNode->data<<endl;
				return;
			}
			else{
				currentNode=currentNode->right;
			}
		}
	}
}
//..........................................

void computeVerticalSums(struct node* currentNode,int horizontalDistance){

	//Modified preOrder traversal

	minHorizontalDistance=min(minHorizontalDistance,horizontalDistance);
	maxHorizontalDistance=max(maxHorizontalDistance,horizontalDistance);

	verticalSums[horizontalDistance]=verticalSums[horizontalDistance]+currentNode->data;

	if(currentNode->left!=NULL){
		computeVerticalSums(currentNode->left,horizontalDistance-1);
	}
	if(currentNode->right!=NULL){
		computeVerticalSums(currentNode->right,horizontalDistance+1);
	}

}

void printSums(){
	for(int i=minHorizontalDistance;i<=maxHorizontalDistance;i++){
		cout<<verticalSums[i]<<" ";
	}
	cout<<endl;
}

int main(){
	
	//Build Tree
	insertNode(50);
	insertNode(20);
	insertNode(80);
	insertNode(10);
	insertNode(30);
	insertNode(60);
	insertNode(100);
	insertNode(15);
	insertNode(25);
	insertNode(70);
	insertNode(85);
	insertNode(28);
	insertNode(65);
	//..........

	computeVerticalSums(root,0);
	printSums();

	return 0;
}