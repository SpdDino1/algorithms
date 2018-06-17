#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root;

int maxDepthVisited=-1;

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

int printLeftView(struct node* currentNode,int nodeDepth){

	if(nodeDepth>maxDepthVisited){
		maxDepthVisited=nodeDepth;
		cout<<currentNode->data<<" ";
	}

	if(currentNode->left!=NULL){
		printLeftView(currentNode->left,nodeDepth+1);
	}
	if(currentNode->right!=NULL){
		printLeftView(currentNode->right,nodeDepth+1);
	}

}

int main(){

	//Build Tree
	insertNode(10);
	insertNode(5);
	insertNode(20);
	insertNode(15);
	insertNode(25);
	insertNode(12);
	insertNode(16);	
	//..........

	printLeftView(root,0);
	cout<<endl;
}