//Convert a BST to a Binary Tree such that sum of all greater keys is added to every key

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root;

vector < struct node* > levelOrderStack;

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

void levelOrder(){

	levelOrderStack.push_back(root);
	int i,lim;

	while(levelOrderStack.size()!=0){

		lim=levelOrderStack.size();

		for(i=0;i<lim;i++){

			if(levelOrderStack[i]->left!=NULL){
				levelOrderStack.push_back(levelOrderStack[i]->left);
			}

			if(levelOrderStack[i]->right!=NULL){
				levelOrderStack.push_back(levelOrderStack[i]->right);
			}

			cout<<levelOrderStack[i]->data<<" ";

		}
		cout<<endl;
		levelOrderStack.erase(levelOrderStack.begin(),levelOrderStack.begin()+i);
	}

}
//..........................................

int convertKeys(struct node* currentNode,int greaterKeySum){

	int fromLeft=0,fromRight=0,temp=currentNode->data;

	if(currentNode->right!=NULL){
		fromRight=convertKeys(currentNode->right,greaterKeySum);
	}

	if(currentNode->left!=NULL){
		fromLeft=convertKeys(currentNode->left,currentNode->data+greaterKeySum+fromRight);
	}

	currentNode->data=currentNode->data+fromRight+greaterKeySum;

	return temp+fromRight+fromLeft;

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

	convertKeys(root,0);

	levelOrder();
}