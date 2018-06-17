#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root;

int diameter=0;

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

int findDiameter(struct node* currentRoot){
	int leftHeight=0,rightHeight=0;

	if(currentRoot->left!=NULL){
		leftHeight=findDiameter(currentRoot->left);
	}

	if(currentRoot->right!=NULL){
		rightHeight=findDiameter(currentRoot->right);
	}

	diameter=max(diameter,leftHeight+1+rightHeight);
	return 1+max(leftHeight,rightHeight);
}

int main(){

	//Build Tree
	insertNode(20);
	insertNode(10);
	insertNode(30);
	insertNode(8);
	insertNode(25);
	insertNode(5);
	//..........
	
	findDiameter(root);
	cout<<"Tree Diameter= "<<diameter<<endl;
}