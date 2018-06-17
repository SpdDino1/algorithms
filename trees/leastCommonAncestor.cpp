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
int nodeA=6,nodeB=20;
//.................

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

int findLeastAncestor(struct node* currentNode){

	int nodeCount1=0,nodeCount2=0;

	//Left and Right sub tree traversal
	if(currentNode->left!=NULL){
		nodeCount1=findLeastAncestor(currentNode->left);
	}	
	if(!isAnsFound && currentNode->right!=NULL){
		nodeCount2=findLeastAncestor(currentNode->right);
	}

	int nodeCount=nodeCount1+nodeCount2;

	//LCA Check
	if(!isAnsFound){
		if(currentNode->data==nodeA || currentNode->data==nodeB){
			nodeCount++;
		}

		if(nodeCount==2){
			cout<<currentNode->data<<endl;
			isAnsFound=true;
		}
	}

	return nodeCount;
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

	findLeastAncestor(root);
	
}