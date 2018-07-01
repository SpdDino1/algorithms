/*

>>Problem<<

https://www.geeksforgeeks.org/stable-marriage-problem/

>>Algorithm<<

>Iterate till there are free men. Find a free man.

>go through his preference list. If the first choice woman is free, match them. Else check if he is preferred higher than the current
match by the woman. If yes, replace and set the former match free. Else this woman cannot be taken, and go to the next preferred woman
by the man.

>Keep doing the above till all men are paired

*/

#include<bits/stdc++.h>
using namespace std;

// MEN INDEX STARTS FROM 1 !!

//Input
map <int,string> menPref;
map <char,string> womenPref;
//.....
int size=0;

map <int,char> manMatchedTo;
map <char,int> womanMatchedTo;

bool isFreeManLeft(){
	for(int i=1;i<=size;i++){
		if(manMatchedTo[i]==NULL){
			return true;
		}
	}
	
	return false;
}

bool canManReplace(int newMan,char targetWoman){

	string womanPreferenceString = womenPref[targetWoman];

	int oldMan = womanMatchedTo[targetWoman];

	for(int i=0;i<womanPreferenceString.length();i++){
		if((womanPreferenceString[i]-'0')==newMan){
			return true;
		}
		else if((womanPreferenceString[i]-'0')==oldMan){
			return false;
		}
	}
}

void matchMan(int man){

	int temp;

	string preferenceString=menPref[man];

	for(int i=0;i<preferenceString.length();i++){ //Iterating though man's preference string
		if(womanMatchedTo[preferenceString[i]]==0){ //Preferred Woman is free => Match
			manMatchedTo[man]=preferenceString[i];
			womanMatchedTo[preferenceString[i]]=man;

			//cout<<man<<" matched to "<<manMatchedTo[man]<<endl;

			return;
		}
		else{ //Preferred woman already matched
			if(canManReplace(man,preferenceString[i])){ //Check if man is more preffered by woman than current match. If yes => Replace
				temp=womanMatchedTo[preferenceString[i]]; //Save old man 
				manMatchedTo[temp]=NULL; //Match for oldMan broken

				manMatchedTo[man]=preferenceString[i]; //New match replaced
				womanMatchedTo[preferenceString[i]]=man;

				//cout<<man<<" matched to "<<manMatchedTo[man]<<endl;

				return;
			}
		}
	}


}

void stableMarriage(){
	while(isFreeManLeft()){

		for(int i=1;i<=size;i++){ //Iterating through men
			if(manMatchedTo[i]==NULL){ //Free Man
				matchMan(i);
			}	
		}

	}
}

int main(){

	//Initialize manPref
	menPref[1]="CBEAD";
	menPref[2]="ABECD";
	menPref[3]="DCBAE";
	menPref[4]="ACDBE";
	menPref[5]="ABDEC";

	//Initialize womenPref
	womenPref['A']="35214";
	womenPref['B']="51243";
	womenPref['C']="43512";
	womenPref['D']="12345";
	womenPref['E']="23415";

	//Initialize Size
	for(map<int,string>::iterator i=menPref.begin();i!=menPref.end();i++){
		size++;
	}

	stableMarriage();

	for(int i=1;i<=size;i++){
		cout<<i<<" : "<<manMatchedTo[i]<<endl;
	}

}