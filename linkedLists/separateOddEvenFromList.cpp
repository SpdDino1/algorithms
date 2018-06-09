#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* nextNode;
};

struct node* head;
struct node* lastEvenNode;


//UtilityFunctiom
void pushNode(int val){
	struct node* newNode= new struct node;
	struct node* traverser= head;

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
	cout<<endl;
}
//.................

void segregate(){
	struct node* traverser= head;
	struct node* temp;

	while((traverser!=NULL)&&(traverser->nextNode!=NULL)){

		if(traverser->nextNode->data%2==0){
			temp=traverser->nextNode;

			traverser->nextNode=traverser->nextNode->nextNode;
			temp->nextNode=lastEvenNode->nextNode;
			lastEvenNode->nextNode=temp;
			lastEvenNode=temp;
		}
		else{
			traverser=traverser->nextNode;
		}
	}
}

int main(){

	//Initialize head
	head = new struct node;
	head->nextNode=NULL;
	lastEvenNode=head;
	//..............

	pushNode(17);
	pushNode(15);
	pushNode(8);
	pushNode(12);
	pushNode(10);
	pushNode(5);
	pushNode(4);
	pushNode(1);
	pushNode(7);
	pushNode(6);


	segregate();

	printList();

	return 0;
}
