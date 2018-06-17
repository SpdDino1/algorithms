#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root;

//Utility Function
void manuallyBuildTree(){

	root=new struct node;
	root->data=50;

	struct node* node1=new struct node;
	node1->data=30;

	struct node* node2=new struct node;
	node2->data=60;

	struct node* node3=new struct node;
	node3->data=5;

	struct node* node4=new struct node;
	node4->data=20; 

	struct node* node5=new struct node;
	node5->data=45; 

	struct node* node6=new struct node;
	node6->data=70;

	struct node* node7=new struct node;
	node7->data=65;

	struct node* node8=new struct node;
	node8->data=80;

	root->left=node1;
	root->right=node2;

	node1->left=node3;
	node1->right=node4;

	node2->left=node5;
	node2->right=node6;

	node6->left=node7;
	node6->right=node8;

}
//................

void morrisTraverse(){

	struct node* currentNode=root;

	struct node* traverser;

	while(currentNode!=NULL){

		if(currentNode->left!=NULL){
			//Find greatest element in left sub tree

			traverser=currentNode->left;

			while(traverser->right!=NULL){
				if(traverser->right == currentNode){
					break;
				}
				traverser=traverser->right;
			}

			if(traverser->right == currentNode){
				//Left sub tree complete

				cout<<currentNode->data<<" ";
				traverser->right=NULL; //Breaking link to get back original tree

				//Enter right sub tree
				currentNode=currentNode->right;
			}
			else{
				traverser->right=currentNode; //Establish Link

				//Enter left sub tree
				currentNode=currentNode->left;

			}

		}
		else{
			cout<<currentNode->data<<" ";
			currentNode=currentNode->right;
		}
	}

}

int main(){
	
	manuallyBuildTree();

	morrisTraverse();
	cout<<endl;
}