#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root;
bool isAnsFound=false;

//Input
int successofFor=20;
//................

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

void findInorderSuccessor(struct node* currentNode){
	if(currentNode==NULL){
		return;
	}

	findInorderSuccessor(currentNode->left);

	if(!isAnsFound){
		cout<<"Successor= "<<currentNode->data<<endl;
		isAnsFound=true;
	}
}

void locateNode(struct node* currentNode){

	if(currentNode->data==successofFor){
		findInorderSuccessor(currentNode->right);
		return;
	}

	if(currentNode->data>successofFor){
		locateNode(currentNode->left);
	}
	else{
		locateNode(currentNode->right);
	}

	if(!isAnsFound){
		if(currentNode->data>successofFor){
			cout<<"Successor= "<<currentNode->data<<endl;
			isAnsFound=true;
		}
		else if(currentNode==root){
			cout<<"Successor= NULL"<<endl;
			isAnsFound=true;
		}
	}

	return;

}

int main(){

	//Build Tree
	insertNode(20);
	insertNode(8);
	insertNode(22);
	insertNode(4);
	insertNode(12);
	insertNode(10);
	insertNode(14);
	//..........

	locateNode(root);
}