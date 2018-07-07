/*

>>Problem<<

https://www.geeksforgeeks.org/find-the-k-most-frequent-words-from-a-file/

>>Data Structures Needed<<

Trie Node [To store words in the most efficient manner possible]
	> heap node* [Pointer to easily find which heap element this node is linked to => Updation purposes]
	>26 child pointers
	>bool isWord flag 

Heap Node [We use a heap to keep track of the top k words at all times]
	>string word [Each node store's the word it represents] 
	>int frequency

>>Algorithm<<

>If a word is inserted in the trie, we insert a new heap node as root and Heapify()

>If a word is updated in terms of frequency, we update the trie node's frequency and use the trie node's heap node pointer to 
find the heap node. Then we pop this element off from its current position => The remaining array is still a heap! We then add 
the updated element as the heap's root and run Heapify()

>At the end extract the top k elements from the heap. Root is always the most frequently occuring word

*/

#include<bits/stdc++.h>
using namespace std;

//Input
string testText="Welcome to the world of Geeks This portal has been created to provide well written well thought and well explained solutions for selected questions If you like Geeks for Geeks and would like to contribute here is your chance You can write article and mail your article to contribute at geeksforgeeks org See your article appearing on the Geeks for Geeks main page and help thousands of other Geeks";
int k=5;
//

struct heapNode{
	string word;
	int frequency;
};

struct trieNode{
	bool isWord=false;
	struct heapNode* nodeInHeap;
	struct trieNode* nextTrieNode[26];
};

struct trieNode* trieHead;
vector <struct heapNode*> maxHeap;

//String extraction function
int extractionFrom=0;
string getNextWord(){
	if(extractionFrom>=testText.length()){
		return "";
	}

	string extractedText;

	while(true){
		if(testText[extractionFrom]==' '){ // \n or space encounterd ==> end of string
			extractionFrom++;
			return extractedText;
		}
		extractedText=extractedText+testText[extractionFrom];
		extractionFrom++;
	}
}
//............................

void maxHeapify(int pos){

	int leftChild = pos*2,rightChild=leftChild+1;

	if(leftChild>=maxHeap.size()){//No Children
		return;
	}
	else{

		struct heapNode* temp;

		if(rightChild>=maxHeap.size()){ //only left child
			if(maxHeap[pos]->frequency < maxHeap[leftChild]->frequency ){ 
				temp=maxHeap[pos];

				maxHeap[pos] = maxHeap[leftChild];

				maxHeap[leftChild]=temp;

				maxHeapify(leftChild);
			}
		}	
		else{ //Both children
			if(maxHeap[leftChild]->frequency > maxHeap[rightChild]->frequency){
				if(maxHeap[leftChild]->frequency > maxHeap[pos]->frequency){
					temp=maxHeap[pos];

					maxHeap[pos] = maxHeap[leftChild];

					maxHeap[leftChild]=temp;

					maxHeapify(leftChild);
				}
			}
			else{
				if(maxHeap[rightChild]->frequency > maxHeap[pos]->frequency){
					temp=maxHeap[pos];

					maxHeap[pos] = maxHeap[rightChild];

					maxHeap[rightChild]=temp;

					maxHeapify(rightChild);
				}
			}
		}
	}

}

int getNodeIndex(struct heapNode* targetNode){
	for(int i=0;i<maxHeap.size();i++){
		if(maxHeap[i]==targetNode){
			return i;
		}
	}
}

void buildHeapAndTrie(string currentWord){

	cout<<currentWord<<endl;

	int currentLetter;
	struct trieNode* currentTrieNode=trieHead;
	struct trieNode* temp;

	for(currentLetter=0;currentLetter<currentWord.length();currentLetter++){

		//Capital to lower conversion
		if(currentWord[currentLetter]<=90){ //A-Z range
			currentWord[currentLetter]=currentWord[currentLetter] + 'a'-'A'; //Conversion
		}

		if(currentTrieNode->nextTrieNode[currentWord[currentLetter]-'a']==NULL){ //Letter not in Trie => Add trie Node
			cout<<"Letter not found: "<<currentWord[currentLetter]<<endl;

			temp=new struct trieNode; //Adding trie node

			//Initializing all nextTrie to null
			for(int i=0;i<27;i++){
				temp->nextTrieNode[i]=NULL;
			}

			currentTrieNode->nextTrieNode[currentWord[currentLetter]-'a'] = temp;
			currentTrieNode=temp;
		}
		else{ //Letter in trie => Traverse
			cout<<"Letter found: "<<currentWord[currentLetter]<<endl;
			currentTrieNode=currentTrieNode->nextTrieNode[currentWord[currentLetter]-'a'];
		}
	}

	if(currentTrieNode->isWord){ //Letters present in trie, and is a word => Increase frequency
		currentTrieNode->nodeInHeap->frequency++;
		struct heapNode* storageHeapNode = currentTrieNode->nodeInHeap;

		int indexInVector = getNodeIndex(storageHeapNode);

		//Delete old node and add new updated node as root....then maxHeapify
		maxHeap.erase(maxHeap.begin()+indexInVector,maxHeap.begin()+indexInVector+1);
		maxHeap.insert(maxHeap.begin(),storageHeapNode); //insert node as root
		maxHeapify(0); 
	}
	else{ //Letters present in trie, but not a word => Create new heapNode 
		currentTrieNode->isWord=true;

		struct heapNode* tempHeapNode=new struct heapNode;
		tempHeapNode->word=currentWord; //Adding heapNode for currentWord
		tempHeapNode->frequency=1;

		currentTrieNode->nodeInHeap=tempHeapNode; //Linking trieNode to heapNode

		maxHeap.insert(maxHeap.begin(),tempHeapNode); //insert new heap node as root
		maxHeapify(0); 
	}

	cout<<endl<<endl;

}

int main(){

	trieHead=new struct trieNode;

	testText=testText+' '; //Helps word extraction

	string extractedText=getNextWord();
	while(extractedText!=""){
		buildHeapAndTrie(extractedText);
		extractedText=getNextWord();
	}

	for(int i=0;i<k;i++){ //Extracting top k words
		cout<<"Word= "<<maxHeap[0]->word<<" Frequency=  "<<maxHeap[0]->frequency<<endl;
		maxHeap.erase(maxHeap.begin(),maxHeap.begin()+1);
		maxHeapify(0);
	}

	return 0;
}