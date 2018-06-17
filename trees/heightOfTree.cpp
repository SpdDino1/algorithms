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

int findHeight(struct node* currentRoot){
	int overallHeight=1,leftHeight=0,rightHeight=0;

	if(currentRoot->left!=NULL){
		leftHeight=findHeight(currentRoot->left);
	}

	if(currentRoot->right!=NULL){
		rightHeight=findHeight(currentRoot->right);
	}

	return overallHeight+max(leftHeight,rightHeight);

}

int main(){

	//Build Tree
	insertNode(2);
	insertNode(3);
	insertNode(1);
	insertNode(4);
	insertNode(5);
	//..........

	cout<<"Tree Height= "<<findHeight(root)<<endl;
}