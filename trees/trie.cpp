//DO NOT USE CAPITAL LETTERS FOR KEYS !!

#include<bits/stdc++.h>
using namespace std;

struct trieNode{
	vector < struct trieNode* > subNodes;
	bool isLeaf;
};

struct trieNode* root;

struct trieNode* createNode(){
	struct trieNode* temp=new struct trieNode;

	for(int i=0;i<26;i++){
		temp->subNodes.push_back(NULL);
	}

	temp->isLeaf=false;

	return temp;
}

void insertWord(string word){

	int i,index;
	struct trieNode* currentNode=root;

	//Traversing TRIE
	for(i=0;i<word.length();i++){	
		
		index=word[i]-'a'; // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Intelligent index access technique!!!!

		if(currentNode->subNodes[index]==NULL){
			break;
		}

		currentNode=currentNode->subNodes[index];

	}

	//Inserting new nodes for non existent letters
	for(i=i;i<word.length();i++){
		index=word[i]-'a';

		currentNode->subNodes[index]=createNode();		
		currentNode=currentNode->subNodes[index];
	}

	currentNode->isLeaf=true;

}

void searchTrie(string word){

	struct trieNode* currentNode=root;
	int index;

	for(int i=0;i<word.length();i++){
		index=word[i]-'a';

		if(currentNode->subNodes[index]==NULL){
			cout<<"Word not found!"<<endl;
			return;
		}

		currentNode=currentNode->subNodes[index];

	}

	if(!currentNode->isLeaf){
		cout<<"Word not found!"<<endl;
		return;
	}

	cout<<"Word found!"<<endl;
	return;

}

int main(){

	//Prep root
	root=createNode();
	//.........

	insertWord("the");
	insertWord("there");
	searchTrie("there");
}