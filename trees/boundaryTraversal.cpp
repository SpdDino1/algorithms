#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root;

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

void traverseLeftSkew(struct node* currentNode){
	if(currentNode->left==NULL && currentNode->right==NULL){
		return;
	}

	cout<<currentNode->data<<" ";

	if(currentNode->left!=NULL){
		traverseLeftSkew(currentNode->left);
	}
}

void traverseLeaves(struct node* currentNode){
	if(currentNode->left==NULL && currentNode->right==NULL){
		cout<<currentNode->data<<" ";
		return;
	}

	if(currentNode->left!=NULL){
		traverseLeaves(currentNode->left);
	}
	if(currentNode->right!=NULL){
		traverseLeaves(currentNode->right);
	}
}

void reverseTraverseRightSkew(struct node* currentNode){
	if(currentNode->left==NULL && currentNode->right==NULL){
		return;
	}

	if(currentNode->right!=NULL){
		reverseTraverseRightSkew(currentNode->right);
		if(currentNode!=root){
			cout<<currentNode->data<<" ";
		}
	}
}

int main(){

	//Build Tree
	insertNode(10);
	insertNode(5);
	insertNode(15);
	insertNode(3);
	insertNode(7);
	insertNode(20);
	insertNode(6);
	insertNode(8);
	//..........

	traverseLeftSkew(root);
	traverseLeaves(root);
	reverseTraverseRightSkew(root);
	
}