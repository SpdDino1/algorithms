#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root;
struct node* head; //Right child points to DLL's first element

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
				return;
			}
			else{
				currentNode=currentNode->right;
			}
		}
	}
}
//..........................................

void convertToDll(struct node* currentNode){

	if(currentNode==NULL){
		return;
	}

	//Find Greatest node in left sub tree
	struct node* greatestNodeInLeft = currentNode->left;

	if(greatestNodeInLeft!=NULL){
		while(greatestNodeInLeft->right!=NULL){
			greatestNodeInLeft=greatestNodeInLeft->right;
		} 
	}

	//Find Least node in Right sub tree
	struct node* leastNodeInRight = currentNode->right;

	if(leastNodeInRight!=NULL){
		while(leastNodeInRight->left!=NULL){
			leastNodeInRight=leastNodeInRight->left;
		}
	}

	//Recursive Calls
	convertToDll(currentNode->left);
	convertToDll(currentNode->right); 

	//Connect
	if(greatestNodeInLeft!=NULL){
		greatestNodeInLeft->right=currentNode;
		currentNode->left=greatestNodeInLeft;
	}
	if(leastNodeInRight!=NULL){
		currentNode->right=leastNodeInRight;
		leastNodeInRight->left=currentNode;
	}

}

void addHead(){
	struct node* traverser=root;

	while(traverser->left!=NULL){
		traverser=traverser->left;
	}

	head->right=traverser;
}

void traverseDll(){

	struct node* traverser=head->right;

	while(traverser!=NULL){
		cout<<traverser->data<<" ";
		traverser=traverser->right;
	}
	cout<<endl;
}

int main(){

	head=new struct node;

	//Build Tree
	insertNode(20);
	insertNode(10);
	insertNode(30);
	insertNode(5);
	insertNode(15);
	insertNode(25);	
	insertNode(35);	
	//..........

	addHead();
	convertToDll(root);

	traverseDll();


}