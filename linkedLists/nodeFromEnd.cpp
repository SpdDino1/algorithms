#include<bits/stdc++.h>
using namespace std;

struct node{
	string data;
	struct node* nextNode;
};

struct node* head;

void pushNode(string val){
	struct node* newNode= new struct node;

	newNode->data=val;
	newNode->nextNode=head->nextNode;

	head->nextNode=newNode;
}

void printList(){
	struct node* currentNode=head->nextNode;

	while(currentNode->nextNode!=NULL){
		cout<<currentNode->data<<" ";
		currentNode=currentNode->nextNode;
	}
	cout<<currentNode->data<<" ";


	cout<<endl;
}

void printFromEnd(int n){
	struct node* currentNode=head->nextNode;
	int count=1;

	while(currentNode->nextNode!=NULL){
		if(count==n){
			cout<<currentNode->data<<" ";
			return;
		}
		currentNode=currentNode->nextNode;
		count++;
	}
	if(count==n){
		cout<<currentNode->data<<" ";
	}
	else{
		cout<<"Out of bounds"<<endl;
	}

}

int main(){
	
	//Initialize head
	head = new struct node;
	head->nextNode=NULL;
	//..............

	//Pushing Nodes
	pushNode("A");
	pushNode("B");
	pushNode("C");
	pushNode("D");

	printFromEnd(5);
}