#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* nextNode;
};

struct node* head1;
struct node* head2;

struct node* unionHead;
struct node* intersectionHead;

map <int,int> valuesOfList1;

void pushNode(struct node* head,int val){
	struct node* newNode= new struct node;

	newNode->data=val;
	newNode->nextNode=head->nextNode;

	head->nextNode=newNode;
}

void printList(struct node* head){
	struct node* currentNode=head->nextNode;

	while(currentNode->nextNode!=NULL){
		cout<<currentNode->data<<" ";
		currentNode=currentNode->nextNode;
	}
	cout<<currentNode->data<<" ";


	cout<<endl;
}

void prepareMap(){
	struct node* currentNode=head1->nextNode;

	while(currentNode->nextNode!=NULL){
		valuesOfList1[currentNode->data]=1;
		currentNode=currentNode->nextNode;
	}
	valuesOfList1[currentNode->data]=1;
}

void findUnionIntersection(){

	//Simply append list 1 from map to intersectList
	for(map<int,int>::iterator i=valuesOfList1.begin();i!=valuesOfList1.end();++i){
		pushNode(unionHead,i->first);
	}

	//Intersection + Union
	struct node* currentNode=head2->nextNode;

	while(currentNode->nextNode!=NULL){

		if(valuesOfList1[currentNode->data]){
			pushNode(intersectionHead,currentNode->data);
		}
		else{
			pushNode(unionHead,currentNode->data);
		}

		currentNode=currentNode->nextNode;
	}
	if(valuesOfList1[currentNode->data]){
		pushNode(intersectionHead,currentNode->data);
	}
	else{
		pushNode(unionHead,currentNode->data);
	}

}

int main(){
	
	//Initialize heads
	head1 = new struct node;
	head1->nextNode=NULL;

	head2 = new struct node;
	head2->nextNode=NULL;

	unionHead = new struct node;
	unionHead->nextNode=NULL;

	intersectionHead = new struct node;
	intersectionHead->nextNode=NULL;
	//..............

	//Pushing Nodes
	pushNode(head1,10);
	pushNode(head1,15);
	pushNode(head1,4);
	pushNode(head1,20);
	printList(head1);

	pushNode(head2,8);
	pushNode(head2,4);
	pushNode(head2,2);
	pushNode(head2,10);
	printList(head2);

	prepareMap();

	findUnionIntersection();

	printList(unionHead);
	printList(intersectionHead);
}
