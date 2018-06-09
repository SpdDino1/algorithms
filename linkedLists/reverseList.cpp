#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* nextNode;
};

struct node* head;

void pushNode(int val){
	struct node* traverser= head;

	struct node* newNode= new struct node;
	newNode->data=val;
	newNode->nextNode=NULL;


	while(traverser->nextNode!=NULL){
		traverser=traverser->nextNode;
	}

	traverser->nextNode=newNode;
}

void printList(){
	struct node* currentNode=head->nextNode;

	while(currentNode->nextNode!=NULL){
		cout<<currentNode->data<<" ";
		currentNode=currentNode->nextNode;
	}
	cout<<currentNode->data<<" ";


	cout<<"NULL"<<endl;
}

void reverseList(){

	struct node* a=head->nextNode;
	struct node* b=head->nextNode->nextNode;
	struct node* c=b->nextNode;

	a->nextNode=NULL;

	while(c!=NULL){
		b->nextNode=a;

		a=b;
		b=c;
		c=b->nextNode;
	}

	b->nextNode=a;
	head->nextNode=b;

}


int main(){

	//Initialize head
	head = new struct node;
	head->nextNode=NULL;
	//..............

	pushNode(1);
	pushNode(2);
	pushNode(3);
	pushNode(4);

	printList();

	reverseList();

	printList();

	return 0;
}