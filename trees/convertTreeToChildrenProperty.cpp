//Convert an arbitrary Binary Tree to a tree that holds Children Sum Property

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root;
vector < struct node* > levelOrderStack;

//Utility
void buildTreeManually(){
	struct node* node1=new struct node;
	node1->data=3;
	node1->left=NULL;
	node1->right=NULL;

	struct node* node2=new struct node;
	node2->data=5;
	node2->left=NULL;
	node2->right=NULL;

	struct node* node3=new struct node;
	node3->data=1;
	node3->left=NULL;
	node3->right=NULL;

	struct node* node4=new struct node;
	node4->data=30;
	node4->left=NULL;
	node4->right=NULL;

	struct node* node5=new struct node;
	node5->data=7;
	node5->left=node1;
	node5->right=node2;

	struct node* node6=new struct node;
	node6->data=2;
	node6->left=node3;
	node6->right=node4;

	root=new struct node;
	root->data=50;
	root->left=node5;
	root->right=node6;
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

bool createChildrenSumProperty(struct node* currentNode){

	//Leaf
	if(currentNode->left==NULL && currentNode->right==NULL){
		return false;
	}

	//Computing Children Sum
	int sum=0;
	if(currentNode->left!=NULL){
		sum=sum+currentNode->left->data;
	}
	if(currentNode->right!=NULL){
		sum=sum+currentNode->right->data;
	}

	bool isCurrentNodeDataChanged=false;

	//Diff adding mech
	if(sum<=currentNode->data){
		//No issue. Add diff to child and keep going down
		if(currentNode->left!=NULL){
			currentNode->left->data=currentNode->left->data+(currentNode->data-sum);
		}
		else{
			currentNode->right->data=currentNode->right->data+(currentNode->data-sum);
		}
	}
	else{
		//Add diff to currentNode and raise flag. Then contiue down
		isCurrentNodeDataChanged=true;
		currentNode->data=currentNode->data+(sum-currentNode->data); 
	}

	//Recursive call mech 
	bool isChildChanged=false;

	if(currentNode->left!=NULL){
		isChildChanged=createChildrenSumProperty(currentNode->left);
	}
	if(currentNode->right!=NULL){
		isChildChanged=createChildrenSumProperty(currentNode->right);
	}

	if(isChildChanged){

		//Re-Computing Children Sum
		sum=0;
		if(currentNode->left!=NULL){
			sum=sum+currentNode->left->data;
		}
		if(currentNode->right!=NULL){
			sum=sum+currentNode->right->data;
		}

		//initially the level was balanced (Compared to parent). Now if the level has been added with something, obviously the sum will 
		//be greater than parent => Simply raise flag and add diff to currentNode (parent)
		isCurrentNodeDataChanged=true;
		currentNode->data=currentNode->data+(sum-currentNode->data); 
	}

	return isCurrentNodeDataChanged;

}

int main(){

	buildTreeManually();

	createChildrenSumProperty(root);

	levelOrder();

}