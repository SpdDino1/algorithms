/*
	
	Given a sorted array, if we keep a pointer to teh left and right, we can find a sum pair on O(n)

	If arr[L]+arr[R]<sum => L++
	If arr[L]+arr[R]>sum => R--


	Hence we here have manually controlled inorder and Reverse indorder loops running (With the help of stacks) that enable us to apply
	the same logic

*/

//Find a pair with given sum in a Balanced BST

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root;

//Input
int sumToGet=28;
//....

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
				//cout<<"Node Inserted to the left of "<<currentNode->data<<endl;
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
				//cout<<"Node Inserted to the right of "<<currentNode->data<<endl;
				return;
			}
			else{
				currentNode=currentNode->right;
			}
		}
	}
}
//..........................................

vector <struct node*> inorderStack;

void initializeInorderLoop(){

	struct node* currentNode=root;

	while(currentNode!=NULL){
		inorderStack.push_back(currentNode);
		currentNode=currentNode->left;
	}

}

struct node* inorderLoopStep(){

	if(inorderStack.size()==0){
		return NULL;
	}

	struct node* nodeToReturn= inorderStack[inorderStack.size()-1];

	inorderStack.pop_back();

	struct node* currentNode=nodeToReturn->right;

	while(currentNode!=NULL){
		inorderStack.push_back(currentNode);
		currentNode=currentNode->left;
	}	

	return nodeToReturn;
}

vector <struct node*> reverseInorderStack;

void initializeReverseInorderLoop(){

	struct node* currentNode=root;

	while(currentNode!=NULL){
		reverseInorderStack.push_back(currentNode);
		currentNode=currentNode->right;
	}

}

struct node* reverseInorderLoopStep(){

	if(reverseInorderStack.size()==0){
		return NULL;
	}

	struct node* nodeToReturn= reverseInorderStack[reverseInorderStack.size()-1];

	reverseInorderStack.pop_back();

	struct node* currentNode=nodeToReturn->left;

	while(currentNode!=NULL){
		reverseInorderStack.push_back(currentNode);
		currentNode=currentNode->right;
	}	

	return nodeToReturn;
}


int main(){

	//Build Tree
	insertNode(15);
	insertNode(10);
	insertNode(20);
	insertNode(8);
	insertNode(12);
	insertNode(16);
	insertNode(25);	
	//..........

	initializeInorderLoop();
	initializeReverseInorderLoop();

	struct node* temp=inorderLoopStep();
	struct node* reverseTemp=reverseInorderLoopStep();

	int sum;

	while((temp->data < reverseTemp->data)&&(temp!=NULL)&&(reverseTemp!=NULL)){

		sum=temp->data+reverseTemp->data;

		if(sum==sumToGet){
			cout<<temp->data<<" + "<<reverseTemp->data<<endl;
			return 1;
		}

		if(sum<sumToGet){
			temp=inorderLoopStep();
		}
		else{
			reverseTemp=reverseInorderLoopStep();
		}
	}

	cout<<"No Pair Found"<<endl;

}