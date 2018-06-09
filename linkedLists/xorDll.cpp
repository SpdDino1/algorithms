/*

xorAddress of node stores the address as a struct node* datatype. 

	struct node * = Memory location, which can be type casted to a long int.

You could store xorAddress as a long int data type too in the struct. 

For performing ^ operation however, you strictly require long int only. So type cast wherever needed.

*/

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* xorAddress;
};

struct node* head;
struct node* tail;

void insertNewNode(int val){
	struct node* newNode=new struct node;
	newNode->data=val;

	if(head->xorAddress==NULL){
		//First node

		newNode->xorAddress=NULL;

		head->xorAddress=(struct node*)((long)0^(long)newNode); //Head's next = newNode
		tail->xorAddress=(struct node*)((long)0^(long)newNode); //Tail's next = newNode
	}
	else{

		newNode->xorAddress=(struct node*)((long)0^(long)head->xorAddress); //Link newNode to NULL and head's next

		struct node* currentFirstNode = head->xorAddress;
		currentFirstNode->xorAddress=(struct node*)((long)currentFirstNode->xorAddress^(long)newNode);// Link currentFirst to newNode

		head->xorAddress=(struct node*)((long)0^(long)newNode); //Head's next = newNode
	}

	cout<<"Node inserted!"<<endl;

}

void traverseForward(){

	struct node* prevNode=NULL;
	struct node* currentNode= head->xorAddress;
	struct node* temp;

	while(currentNode!=NULL){
		cout<<" "<<currentNode->data;
		temp=currentNode;
		currentNode=(struct node*)((long)currentNode->xorAddress^(long)prevNode);
		prevNode= temp;
	}

	cout<<" NULL"<<endl;

}	

void traverseBackward(){
	struct node* prevNode=NULL;
	struct node* currentNode= tail->xorAddress;
	struct node* temp;	

	while(currentNode!=NULL){
		cout<<" "<<currentNode->data;
		temp=currentNode;
		currentNode=(struct node*)((long)currentNode->xorAddress^(long)prevNode);
		prevNode= temp;
	}

	cout<<" NULL"<<endl;

}

void deleteNode(int val){
	struct node* prevNode=NULL;
	struct node* currentNode= head->xorAddress;
	struct node* temp;	

	int isNodeFound=false;

	if(currentNode==NULL){
		cout<<"No Nodes in list!"<<endl;
		return;
	}
	struct node* nextNode=(struct node*)((long)currentNode->xorAddress^(long)prevNode);

	while(currentNode!=NULL){
		if(currentNode->data==val){
			isNodeFound=true;
			break;
		}
		temp=currentNode;
		currentNode=(struct node*)((long)currentNode->xorAddress^(long)prevNode);
		prevNode= temp;
		nextNode=(struct node*)((long)currentNode->xorAddress^(long)prevNode);
	}

	if(isNodeFound){

		if(prevNode==NULL && nextNode==NULL){ //only 1 node in list
			head->xorAddress=NULL;
			tail->xorAddress=NULL;
		}
		else if(prevNode==NULL){ //First node
			struct node* nextNextNode = (struct node*)((long)nextNode->xorAddress^(long)currentNode);
			nextNode->xorAddress=(struct node*)((long)NULL^(long)nextNextNode);
			head->xorAddress=nextNode;
		}
		else if(nextNode==NULL){//Last Node
			struct node* prevPrevNode= (struct node*)((long)prevNode->xorAddress^(long)currentNode);
			prevNode->xorAddress=(struct node*)((long)prevPrevNode^(long)NULL);
			tail->xorAddress=prevNode;
		}
		else{//Middle node
			struct node* nextNextNode = (struct node*)((long)nextNode->xorAddress^(long)currentNode);
			struct node* prevPrevNode= (struct node*)((long)prevNode->xorAddress^(long)currentNode);

			nextNode->xorAddress=(struct node*)((long)prevNode^(long)nextNextNode);
			prevNode->xorAddress=(struct node*)((long)prevPrevNode^(long)nextNode);
		}

		delete currentNode;
		cout<<"Node deleted!"<<endl;
		return;
	}

	cout<<"Node not found!"<<endl;
}

int main(){

	//Init head, tail
	head=new struct node;
	tail=new struct node;

	head->xorAddress=NULL;
	tail->xorAddress=NULL;
	//...............

	int choice,data;

	while(true){
		cout<<"1 = Insert New Node"<<endl;
		cout<<"2 = Traverse Forward"<<endl;
		cout<<"3 = Traverse Backward"<<endl;
		cout<<"4 = Delete Node"<<endl;

		cin>>choice;

		if(choice==1){
			cout<<"Data = ";
			cin>>data;

			insertNewNode(data);
		}
		else if(choice==2){
			traverseForward();
		}

		else if(choice==3){
			traverseBackward();
		}
		else if(choice==4){
			cout<<"Data to delete = ";
			cin>>data;

			deleteNode(data);
		}
	}

	return 0;
}