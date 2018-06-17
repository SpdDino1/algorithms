/*

This program only considers complete sub trees => 50 will not be the largest sub tree as 50's left sub tree's is not BST. It is not 
permitted to use the left child of 50 alone. You have to either attach or detach complete sub trees.

Algo

>Recursively descend left and right subtrees, each time returning the largest and least values of the BST below. The root of the 
overall tree must be greater than the largest value of the left sub tree and must be less than the least value of the right sub tree.

>In case the left sub tree fails => The current node shoukd not be included in the largest BST. But you can't skip recursing through
right as the sub BST might be there => Set a flag and move. 

>>Modified Question<<

>If you may take parts of a sub tree => Remove the flag condition and manipulate there. You may treat the left and right recursive
calls separately.

*/


#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct returnElement{
	int greatestData; 
	int leastData; 
	int nodeCount=0;	
};

struct node* root;

struct node* subTreeRoot;
int subTreeSize=0;

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

struct returnElement* findLargestBst(struct node* currentNode){

	bool isNotBst=false;

	struct returnElement* element= new struct returnElement;

	//Defualt initialization below helps when 1 child is NULL
	element->leastData=currentNode->data;
	element->greatestData=currentNode->data;

	//Leaf node
	if(currentNode->left==NULL && currentNode->right==NULL){

		element->nodeCount=1;
		element->leastData=currentNode->data;
		element->greatestData=currentNode->data;

		if(subTreeSize < element->nodeCount){
			subTreeSize=element->nodeCount;
			subTreeRoot=currentNode;
		}		

		return element;
	}

	//Left sub tree recursive call
	if(currentNode->left!=NULL){
		struct returnElement* leftTree=findLargestBst(currentNode->left);

		if(leftTree->greatestData <= currentNode->data){
			element->leastData=leftTree->leastData; //set current tree's least to left sub tree's left
			element->nodeCount=leftTree->nodeCount+1; //Left tree nodes + currentNode

		}
		else{
			//Left sub tree not satisfying BST
			isNotBst=true;
		}

	}

	//Right sub tree recursive call
	if(currentNode->right!=NULL){
		struct returnElement* rightTree=findLargestBst(currentNode->right);

		if(!isNotBst && currentNode->data <= rightTree->leastData){
			element->greatestData=rightTree->greatestData; //set current tree's greatest to right sub tree's greatest
			element->nodeCount=element->nodeCount + rightTree->nodeCount; 

			//Left + Right Pass bst => check global values
			if(subTreeSize < element->nodeCount){
				subTreeSize=element->nodeCount;
				subTreeRoot=currentNode;
			}		

		}
		else{
			//Right sub tree not satisfying BST
			isNotBst=true;
		}

	}

	if(isNotBst){
		element->nodeCount=1;
		element->leastData=currentNode->data;
		element->greatestData=currentNode->data;

		if(subTreeSize < element->nodeCount){
			subTreeSize=element->nodeCount;
			subTreeRoot=currentNode;
		}	
	}

	return element;

}

int main(){

	manuallyBuildTree();

	findLargestBst(root);

	cout<<"Largest BST Size= "<<subTreeSize<<endl;
	cout<<"BST Root= "<<subTreeRoot->data<<endl;
}