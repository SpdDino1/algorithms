#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* globalRoot;

//Input
int postorder[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
int preorder[]= {1, 2, 4, 8, 9, 5, 3, 6, 7};
//....

int postOrderSize=sizeof(postorder)/sizeof(postorder[0]);

int preOrderPointer=0;

//Utility Function
void printInorder(struct node* currentNode){
	if(currentNode->left!=NULL){
		printInorder(currentNode->left);
	}

	cout<<currentNode->data<<" ";
	
	if(currentNode->right!=NULL){
		printInorder(currentNode->right);
	}
}
//..........................................

bool isNextNodeChildOfNewNode(int parent,int child){

	if(child==postOrderSize){//Last element of preOrderList == Lead
		return false;
	}

	bool isParentFound=false;

	for(int i=0;i<postOrderSize;i++){
		if(postorder[i]==child && isParentFound){
			return false;
		}
		else if(postorder[i]==parent){
			isParentFound=true;
		}
	}

	return true;

}

struct node* buildTree(){

	struct node* newNode=new struct node;

	newNode->data=preorder[preOrderPointer];

	if(isNextNodeChildOfNewNode(preorder[preOrderPointer],preorder[preOrderPointer+1])){
		preOrderPointer++;
		newNode->left=buildTree();
		newNode->right=buildTree();
	}
	else{
		preOrderPointer++;
		newNode->left=NULL;
		newNode->right=NULL;
	}

	return newNode;

}

int main(){
	
	globalRoot=buildTree();

	printInorder(globalRoot);
	cout<<endl;

	return 0;
}