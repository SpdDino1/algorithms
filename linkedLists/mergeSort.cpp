#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* nextNode;
};

struct node* head;
int listLength=0;

//Utility Methods
void pushNode(struct node* head,int val){
	struct node* newNode= new struct node;
	newNode->data=val;
	newNode->nextNode=NULL;

	struct node* traverser = head;

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

void findListLength(){
	struct node* currentNode=head->nextNode;

	while(currentNode!=NULL){
		listLength++;
		currentNode=currentNode->nextNode;
	}
}

struct node* fetchNode(int index){
	if(index>=listLength){
		return NULL;
	}
	if(index==-1){
		return head;
	}

	struct node* currentNode=head->nextNode;
	int count=0;

	while(count!=index){
		currentNode=currentNode->nextNode;
		count++;
	}	

	return currentNode;
}

void mergeSort(int start,int end){
	if((end-start)==1){
		return;
	}

	//Breaking Mech
	int mid=(start+end)/2;

	mergeSort(start,mid);
	mergeSort(mid,end);


	//MergingMech
	struct node* tempList=new struct node;
	tempList->nextNode=NULL;

	struct node* leftTraverser= fetchNode(start);
	struct node* rightTraverser=fetchNode(mid);
	int l=start,r=mid;

	while((l<mid)&&(r<end)){
		if(leftTraverser->data < rightTraverser->data){
			pushNode(tempList,leftTraverser->data);
			leftTraverser=leftTraverser->nextNode;
			l++;
		}
		else{
			pushNode(tempList,rightTraverser->data);
			rightTraverser=rightTraverser->nextNode;
			r++;
		}
	}

	if(l==mid){//Append right
		while(r<end){
			pushNode(tempList,rightTraverser->data);
			rightTraverser=rightTraverser->nextNode;
			r++;
		}
	}
	else{ //Append left
		while(l<mid){
			pushNode(tempList,leftTraverser->data);
			leftTraverser=leftTraverser->nextNode;
			l++;
		}
	}

	//Fit to existing list
	struct node* leftNode=fetchNode(start-1);
	struct node* rightNode=fetchNode(end);

	struct node* tempListTraverser=tempList;
	while(tempListTraverser->nextNode!=NULL){
		tempListTraverser=tempListTraverser->nextNode;
	}

	leftNode->nextNode=tempList->nextNode;
	tempListTraverser->nextNode=rightNode;

}

int main(){
	
	//Initialize head
	head = new struct node;
	head->nextNode=NULL;
	//..............

	//Pushing Nodes
	pushNode(head,10);
	pushNode(head,2);
	pushNode(head,4);
	pushNode(head,6);

	findListLength();
	
	printList();

	mergeSort(0,listLength);

	printList();
}