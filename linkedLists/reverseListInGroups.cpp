#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* nextNode;
};

//Input
int k=3;
//.....

struct node* head;
vector <struct node*> nextNodes;

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

void groupedReverse(){
	int count=0;
	int blockCount=1;

	struct node* a=head->nextNode;
	struct node* b=a->nextNode;
	struct node* temp;

	while(true){
		count++;

		if(b==NULL){
			nextNodes[0]->nextNode=a;

			if(count==1){
				a->nextNode=NULL;
			}
			else{
				nextNodes.erase(nextNodes.begin(),nextNodes.begin()+1);
				nextNodes[0]->nextNode=NULL;
			}
			break;
		}

		cout<<"a= "<<a->data<<" b= "<<b->data<<" count= "<<count<<endl; //debug

		if(count==1){
			nextNodes.push_back(a);
		}
		else if(count==k){
			if(blockCount==1){
				head->nextNode=a;
				blockCount++;
				cout<<"Head planted"<<endl;
			}
			else{
				nextNodes[0]->nextNode=a;
				nextNodes.erase(nextNodes.begin(),nextNodes.begin()+1);
			}
			count=0;
		}

		temp=b->nextNode;

		b->nextNode=a;

		a=b;
		b=temp;
	}
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
	pushNode(5);
	pushNode(6);
	pushNode(7);
	pushNode(8);

	groupedReverse();

	printList();

	return 0;
}