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

int main(){

	//Build Tree
	insertNode(7);
	insertNode(1);
	insertNode(2);
	insertNode(3);
	insertNode(4);
	insertNode(5);
	insertNode(6);
	insertNode(8);
	insertNode(9);
	insertNode(12);
	insertNode(10);
	//..........

	levelOrder();

}