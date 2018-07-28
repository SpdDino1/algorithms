/*

Given a string, tell if it is possible to make a single swap and convert it into a pallindrome => By swapping 2 letters, the string should
become a pallindrome

This means that if a pallindrome were taken and the ith and jth index letter were swapped,

	i and length()-i
	j and length()-j indices woud be the only conflicting indices. Hence if we remove these 4 indices, the remaining string should be
	a pallindrome

	And if the letter count occupying these indices are actually 2 => We can swap one of the pairs to get a pallindrome!

What we do is iterate from left and right simultaneously and count the number of conflicting indices and the lettersInvolved. We use a hash
map to keep track of letters involved and a count to count the number of conflicts.

If conflictCount = 4 and letterCount=2 => Swap possible

>>Special Case<<

Consider an odd length pallindrome abcba => cbaba (first a and middle c have been swapped). In this case you have only 2 conflicting indices.
So at the end add a check for this case too [Check if the centre letter has already been seen if the conflictCount == 2 => Swap possble]

*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(string in){

	unordered_map <char,bool> isCharacterSeen;
	int lettersInvolved=0,conflicedIndices=0;

	int l=0,r=in.length()-1;

	while(l<=r){

		if(in[l]!=in[r]){
			if(isCharacterSeen[in[l]]==false){
				isCharacterSeen[in[l]]=true;
				lettersInvolved++;
			}
			if(isCharacterSeen[in[r]]==false){
				isCharacterSeen[in[r]]=true;
				lettersInvolved++;
			}
			conflicedIndices=conflicedIndices+2;
		}

		l++;
		r--;
	}

	if((lettersInvolved==2)&&(conflicedIndices==4)){ //Odd case without center + Even case
		return true;
	}

	if((lettersInvolved==2)&&(conflicedIndices==2)&&(isCharacterSeen[in[in.length()/2]])){ //Odd case with center
		return true;
	}

	return false;

}

int main(){
	

	if(isPossible("bbccaa")){ //Pass input here
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}

	return 0;
}