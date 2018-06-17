#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
	struct node* next; //Used to preserve the linked list while using getNode(). Can be avoided...read after code comment
};

struct node* root;
struct node* head; //next points to nextNode in list

int listSize=0;

vector < struct node* > levelOrderStack;

//Utility Function
void insertNode(int val){
	struct node* traverser=head;

	while(traverser->next!=NULL){
		traverser=traverser->next;
	}

	struct node* newNode=new struct node;
	newNode->data=val;
	newNode->next=NULL;

	traverser->next=newNode;
	listSize++;
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

void inorder(struct node* currentNode){
	if(currentNode->left!=NULL){
		inorder(currentNode->left);
	}

	cout<<currentNode->data<<" ";
	
	if(currentNode->right!=NULL){
		inorder(currentNode->right);
	}
}
//..........................................

struct node* getNode(int index){

	struct node* traverser=head;

	for(int i=0;i<=index;i++){
		traverser=traverser->next;
	}

	return traverser;
}

struct node* buildTree(int start,int stop){

	//Only one node
	if(start==stop){
		return getNode(start);
	}

	//Current node = root
	int rootIndex=(start+stop)/2;
	struct node* root=getNode(rootIndex);

	//Recursive call for left subtree
	struct node* leftSubRoot;
	if((rootIndex-1)<0){
		leftSubRoot=buildTree(start,0);	
	}
	else{
		leftSubRoot=buildTree(start,rootIndex-1);	
	}

	//Recursive call for right subtree
	struct node* rightSubRoot;
	if((rootIndex+1)>listSize){
		rightSubRoot=buildTree(listSize,stop);	
	}
	else{
		rightSubRoot=buildTree(rootIndex+1,stop);	
	}

	//Connecting currentNode with leftSubRoot
	if(leftSubRoot==root){
		root->left=NULL;
	}
	else{
		root->left=leftSubRoot;
	}

	//Connecting currentNode with rightSubRoot
	if(rightSubRoot==root){
		root->right=NULL;
	}
	else{
		root->right=rightSubRoot;
	}

	return root;
}

int main(){

	head=new struct node;
	head->next=NULL;

	//Build list
	insertNode(1);
	insertNode(2);
	insertNode(3);
	insertNode(4);
	insertNode(5);
	insertNode(6);
	listSize--;
	//.........
	
	root=buildTree(0,listSize);

	levelOrder();

	cout<<endl;
	inorder(root);
	cout<<endl;
}

/*
If you want to avoid using next in the node struct, you will have to an offset global variable and the head has to keep being pushed 
forward.

Everytime your left call is done => You left side of array (Including head) links will be broken. Hence within your recursive function
itself you'll have to push head forward and add the offset.

So in your getNode() loop you start with the offset and your newly positioned head. So your previously used indices still have meaning

[head]0 ,1 ,2, 3, 4

afterwards....

[head]2, 3, 4 (offset=2) 

*/