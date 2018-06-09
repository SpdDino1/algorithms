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

void deleteList(){
	struct node* currentNode=head->nextNode;
	struct node* temp;

	while(currentNode->nextNode!=NULL){
		temp = currentNode->nextNode;
		delete currentNode;		//This is how you delete
		currentNode=temp;
	}
	delete currentNode;
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

	printList();

	deleteList();
}