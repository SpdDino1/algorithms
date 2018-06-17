#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct stackElement{
	struct node* treeNode;
	int points;
};

struct node* root;

//Input
int targetNode=15;
//....

vector < struct stackElement* > postOrderStack;

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

void initializeStack(){
	struct node* currentNode=root;

	while(currentNode!=NULL){
		struct stackElement* temp= new stackElement;
		temp->treeNode=currentNode;
		temp->points=1;

		postOrderStack.push_back(temp);

		currentNode=currentNode->left;
	}
}

void findAncestors(){

	initializeStack();

	struct stackElement* currentStackElement;

	struct node* tempNode;

	while(postOrderStack.size()!=0){

		currentStackElement=postOrderStack[postOrderStack.size()-1];

		if(currentStackElement->treeNode->data==targetNode){
			//Node Found
			break;
		}
		else if((currentStackElement->treeNode->right!=NULL)&&(currentStackElement->points==1)){
			//Node has unvisited right child

			currentStackElement->points=2;
			tempNode=currentStackElement->treeNode->right;

			while(tempNode!=NULL){
				struct stackElement* tempStackElement= new stackElement;
				tempStackElement->treeNode=tempNode;
				tempStackElement->points=1;

				postOrderStack.push_back(tempStackElement);

				tempNode=tempNode->left;
			}

		}
		else{
			//Remove leaf node OR Has visited right node 
			postOrderStack.pop_back();
		}

	}

	//Print Stack Contents => Ancestors
	for(int i=postOrderStack.size()-2;i>=0;i--){
		cout<<postOrderStack[i]->treeNode->data<<" ";
	}
	cout<<endl;

}

int main(){

	//Build Tree
	insertNode(10);
	insertNode(5);
	insertNode(20);
	insertNode(3);
	insertNode(6);
	insertNode(15);
	insertNode(2);
	insertNode(7);
	insertNode(18);
	//..........

	findAncestors();

}