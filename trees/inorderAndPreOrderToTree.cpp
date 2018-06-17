/*
Generally inorder will be required to build a tree, along with post or preorder. This is because we can identify the subtrees only with the 
help of inorder and the roots with the help of post or pre.

But here since the condition is a full tree, we can easily identify a leaf from an internal node that has a few missing children. Hence 
this mech works. Here the preorder helps find roots and the post order helps check if it is a leaf or an internal node (By checking if the 
next node is before it or not. If it is before it in the order => It is a descendant as post order is left,right then root).
*/


#include<bits/stdc++.h>
using namespace std;

struct node{
	string data;
	struct node* left;
	struct node* right;
};

struct node* globalRoot;

//Input
string inorder="DBEAFC";
string preorder="ABDECF";

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

struct node* buildTree(int start,int stop){

	struct node* root=new struct node;

	if(start==stop){
		//Only one node => Leaf
		root->data=inorder[start];
		root->left=NULL;
		root->right=NULL;
		return root;
	}

	//Finding Root in given inorder[start] to inorder[stop]
	int rootPosInInorder;

	for(int i=0;i<preorder.length();i++){//Iterating throught preorder

		for(int j=start;j<=stop;j++){//iterating through inorder
			if(preorder[i]==inorder[j]){
				root->data=preorder[i];
				rootPosInInorder=j;
				break;
			}
		}

		if(root->data !=""){//data has been set in inner loop => break outer loop
			break;
		}

	}

	//Left Recursive Call
	if((rootPosInInorder-1)<0){
		root->left=NULL;
	}
	else{
		root->left=buildTree(start,rootPosInInorder-1);
	}

	//Right recursive call
	if((rootPosInInorder+1)==inorder.length()){
		root->right=NULL;
	}
	else{
		root->right=buildTree(rootPosInInorder+1,stop);
	}

	return root;

}

int main(){

	globalRoot=buildTree(0,inorder.length()-1);

	printInorder(globalRoot);
	cout<<endl;

}