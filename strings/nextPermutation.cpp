/*

>>std helper function next_permutation helps generate all permutations of any given datastructure that supports iterators

>>You'll have to sort the DS first beofre using the function.

*/

#include<bits/stdc++.h>
using namespace std;

//Input
string inputWord="ABC";
//.....

void permute(string word){

	sort(word.begin(),word.end());

	cout<<word<<endl;

	while(next_permutation(word.begin(),word.end())){
		cout<<word<<endl;
	}
}

int main(){
	
	permute(inputWord);
	return 0;
}