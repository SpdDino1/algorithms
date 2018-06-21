/*

>>Problem<<

>This regex matcher only matches characters ("a","bcc" etc:) "*" and "?" (0 or 1 occurences).

>>Algorithm<<

>There are 2 modes this program may run under. Initially it will be in the create/extend group mode [isStartAnywhereAllowed==true]. In this
state operators can create new groups and extend existing groups. For example the operator a* run on "aaabaa" can first create a group "aaa"
and then create another group "aa". These groups are stored in a vector called dpStorage. 
dpStorage has an index for every char in the main string. The value of dpStorage[index] signifies the group size starting from that char
in the main string. So "aaa" would be stored as dpStorage[0]=2 {0-2 is a group}. All the elements in between would have dpStorage=-1. 
Initially too all would be -1.

>Operations such as * and ? don't change the isStartAnywhereAllowed variable and allow creation of groups anywhere as they allow ZERO or
more occurences. They also don't destroy groups as zero occurence is allowed.

>But letters alone "l","c" etc: change to program isStartAnywhereAllowed to false as they enforce strict rules. They only allow group 
extensions and not group creations. If isStartAnywhereAllowed==true => You may extend groups. For example a group 'aaa'b may be extended to
"aaab" if the current rule was "b". If the group can't be extended => destroy it by setting dpStorage[]=-1. And new groups of only the 
letter may be created too. But after this rule's loop is over, isStartAnywhereAllowed is set to false as now you may only extend 
these groups.

>>Keep iterating and applying rules till your pattern is fully exhausted.

>Remeber each rule has two possible modes. * and ? don't change the mode wheres individual letters change the mode to only extend.
* and ? also don't destroy groups in any mode, whereas only letters destroy in both modes if the group doesn't follow.

*/

#include<bits/stdc++.h>
using namespace std;

//Input
string mainString="baaaabcc";
string pattern="ba*b?c*";
//.......

int currentExtractIndex=0;

struct extractResult{
	char letter;
	char quantifier;
};

vector <int> dpStorage;

struct extractResult* extractNextPattern(){

	struct extractResult* returnValue= new struct extractResult;

	returnValue->letter=pattern[currentExtractIndex];
	currentExtractIndex++;

	if(currentExtractIndex<pattern.length()){	
		if(pattern[currentExtractIndex]=='?'){
			returnValue->quantifier='?';
			currentExtractIndex++;
		}
		else if(pattern[currentExtractIndex]=='*'){
			returnValue->quantifier='*';
			currentExtractIndex++;
		}
		else{
			returnValue->quantifier=NULL;
		}
	}
	else{
		returnValue->quantifier=NULL;
	}

	return returnValue;

}

void matchPattern(){
	bool isStartAnywhereAllowed=true;

	struct extractResult* nextRule= new struct extractResult;

	while(currentExtractIndex<pattern.length()){
		nextRule=extractNextPattern();

		if(nextRule->quantifier=='*'){

			if(isStartAnywhereAllowed){

				int j;

				for(int i=0;i<dpStorage.size();i++){

					if(dpStorage[i]!=-1){//A group already exists
						//Trying to extend group
						for(j=dpStorage[i]+1;j<mainString.length();j++){
							if(mainString[j]!=nextRule->letter){
								dpStorage[i]=j-1;
								break;
							}
							dpStorage[j]=-1;
							dpStorage[i]++;	 
						}	
						i=j-1; //Change main loop index
					}
					else{ //Group doesn't exist
						//Trying to create new group
						for(j=i;j<mainString.length();j++){
							if(mainString[j]!=nextRule->letter){
								break;
							}
						}

						//If j == i => nothing new found => no group created => don't change dp storage
						if(i!=j){
							dpStorage[i]=j-1;
						}

						i=j; //Change main loop index
					}
				}
			}
			else{

				int j;

				for(int i=0;i<dpStorage.size();i++){

					//Found a group
					if(dpStorage[i]!=-1){
						//Trying to extend existing group
						for(j=dpStorage[i]+1;j<mainString.length();j++){
							if(mainString[j]!=nextRule->letter){
								dpStorage[i]=j-1;
								break;
							}
							dpStorage[j]=-1;
							dpStorage[i]++;
						}	
						i=j-1; //Change main loop index
					}
				}
			}

		}
		else if(nextRule->quantifier==NULL){

			if(isStartAnywhereAllowed){

				for(int i=0;i<dpStorage.size();i++){

					//Not in group
					if((dpStorage[i]==-1)&&(mainString[i]==nextRule->letter)){
						dpStorage[i]=i; //Single element captured
						continue;
					}

					//Group
					if(dpStorage[i]!=-1){
						if(mainString[dpStorage[i]+1]==nextRule->letter){ //Group extended
							dpStorage[i]++;
							dpStorage[dpStorage[i]]=-1;
							i=dpStorage[i];
						}
						else{ //Group destroyed
							dpStorage[i]=-1;
						}
					}
		
				}

			}
			else{

				for(int i=0;i<dpStorage.size();i++){

					if((dpStorage[i]!=-1)&&(mainString[dpStorage[i]+1]==nextRule->letter)){//Group extended
						dpStorage[i]++;
						dpStorage[dpStorage[i]]=-1;
						i=dpStorage[i]; //Update loop index
					}
					else{
						dpStorage[i]=-1; //group destroyed
					}
		
				}
			}

			isStartAnywhereAllowed=false;
			
		}
		else if(nextRule->quantifier=='?'){

			if(isStartAnywhereAllowed){

				for(int i=0;i<dpStorage.size();i++){
					
					if((dpStorage[i]==-1)&&(mainString[i]==nextRule->letter)){//Creating single element groups
						dpStorage[i]=i;
						continue;
					}

					if((dpStorage[i]!=-1)&&(mainString[dpStorage[i]+1]==nextRule->letter)){ //extending group
						dpStorage[i]++;
						dpStorage[dpStorage[i]]=-1;
						i=dpStorage[i];
					}

				}	

			}
			else{

				for(int i=0;i<dpStorage.size();i++){
					
					if((dpStorage[i]!=-1)&&(mainString[dpStorage[i]+1]==nextRule->letter)){ //extending group
						dpStorage[i]++;
						dpStorage[dpStorage[i]]=-1;
						i=dpStorage[i];
					}

				}	

			}

		}
	
		for(int i=0;i<dpStorage.size();i++){
			cout<<mainString[i]<<" "<<dpStorage[i]<<endl;
		}
		cout<<endl<<endl;
	} 
}

int main(){

	//Initialize DP Storage (DP Matrix)
	for(int i=0;i<mainString.length();i++){
		dpStorage.push_back(-1);
	}

	matchPattern();
	return 0;
}