#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root;
vector <struct node*> nodeQueue;

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

void zigZagTraverse(bool isForward){

	if(nodeQueue.size()==0){
		cout<<endl;
		return;
	}

	int lim=nodeQueue.size();

	if(isForward){
		for(int i=0;i<lim;i++){
			cout<<nodeQueue[i]->data<<" ";

			if(nodeQueue[i]->left!=NULL){
				nodeQueue.push_back(nodeQueue[i]->left);
			}
			if(nodeQueue[i]->right!=NULL){
				nodeQueue.push_back(nodeQueue[i]->right);
			}
		}
	}
	else{
		for(int i=lim-1;i>=0;i--){
			cout<<nodeQueue[i]->data<<" ";
		}
		for(int i=0;i<lim;i++){
			if(nodeQueue[i]->left!=NULL){
				nodeQueue.push_back(nodeQueue[i]->left);
			}
			if(nodeQueue[i]->right!=NULL){
				nodeQueue.push_back(nodeQueue[i]->right);
			}
		}
	}

	nodeQueue.erase(nodeQueue.begin(),nodeQueue.begin()+lim);

	zigZagTraverse(!isForward);

}

int main(){

	//Build Tree
	insertNode(10);
	insertNode(5);
	insertNode(15);
	insertNode(3);
	insertNode(7);
	insertNode(12);
	insertNode(20);
	//..........

	nodeQueue.push_back(root);
	zigZagTraverse(true);
	
}