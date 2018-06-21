/*

>>Problem<<

https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/

>>Algorithm<<

>Keep dividing the string till you get a sub string of length less than the required letters. If you reach such a sub string simply
return saying there is no window and all the letters are required to get a complete Window.

>In case both, your left and right calls have no window => Both were too small. So now left+right is the first string that may have a 
window. So we scan the full string, from left to right. If we find any character that is included in the required list => Pop it off the
list and start the window from that string. Keep scanning. If you find any more letters, pop it off and extend the window's end. Else if
no other letter found, close the window at starting point itself.
After the scan check if requiredLetters == 0. If yes => you have a complete window. Update global vars [If localWindowSize<global].

>After your sub calls, if a left window is available => there might be letters required that aren't available on the left. So start scanning
from mid to right. If any required letter is found, extend left window. 
After scan is complete, check if requiredLetters==0. If yes => you have a complete window. Update global vars [If localWindowSize<global].
If you have a right window => there might be some required letters on the left. So start scanning from mid to left. If any required letters
are found => Extend window's beginning.
After the scan check if requiredLetters == 0. If yes => you have a complete window. Update global vars [If localWindowSize<global].

>Now take the minimum window size between left and right (After scanning) and return that window's start,end and requiredLetters to the 
above call. 

*/

#include<bits/stdc++.h>
using namespace std;

//Input
string mainString="this is a test string";
string letters="tist";
//........

int globalStartWindow=0,globalEndWindow=mainString.length();

struct returnElement{
	bool isThereWindow;
	int windowStart;
	int windowEnd;
	string requiredToComplete;
};

//Helper Functions...........................................................................................
bool isRequired(char letter,string requiredLetters){
	for(int i=0;i<requiredLetters.length();i++){
		if(letter==requiredLetters[i]){
			return true;
		}
	}
	return false;
}

string removeLetter(string requiredLetters,int indexInMainString){

	int indexToRemove;

	for(int i=0;i<requiredLetters.length();i++){
		if(requiredLetters[i]==mainString[indexInMainString]){
			indexToRemove=i;
			break;
		}
	}

	if(indexToRemove==0){
		requiredLetters=requiredLetters.substr(indexToRemove+1);
	}
	else{
		requiredLetters=requiredLetters.substr(0,indexToRemove) +requiredLetters.substr(indexToRemove+1,1);
	}

	return requiredLetters;
}

void updateGlobalWindowVariables(int start,int end){
	int globalWindowSize=globalEndWindow-globalStartWindow+1,localWindowSize=end-start+1;
	//cout<<"Complete Window"<<" start= "<<start<<" end= "<<end<<endl;
	
	if(localWindowSize<globalWindowSize){
		globalStartWindow=start;
		globalEndWindow=end;
	}

}
//............................................................................................................

struct returnElement* findWindow(int l,int r){

	//cout<<endl<<endl;
	//cout<<"Left= "<<l<<" Right= "<<r<<endl;

	//Initializing returnObject
	struct returnElement* returnObject=new struct returnElement;
	returnObject->windowStart=-1;
	returnObject->windowEnd=-1;
	returnObject->requiredToComplete=letters;

	//If length of sub string < required letters =>Simply return
	if((r-l+1)<letters.length()){
		//cout<<"Left= "<<l<<" Right= "<<r<<" subString too small return"<<endl;
		returnObject->isThereWindow=false;
		return returnObject;
	}

	//Left Right recursive calls
	int mid=(l+r)/2;

	struct returnElement* leftWindow = findWindow(l,mid-1);
	struct returnElement* rightWindow = findWindow(mid+1,r);

	//Both sides were too small => Search full sample
	if((leftWindow->isThereWindow==false)&&(rightWindow->isThereWindow==false)){
		//cout<<"Left= "<<l<<" Right= "<<r<<" full scan"<<endl;
		for(int i=l;i<=r;i++){

			if(isRequired(mainString[i],returnObject->requiredToComplete)){

				//Mark start OR Extend end of window
				if(returnObject->windowStart==-1){ //First required letter => New window created
					returnObject->windowStart=i;
					returnObject->windowEnd=i;
				}
				else{	//Another required letter => Extending created window
					returnObject->windowEnd=i;
				}

				//Remove letter from requiredLetters
				returnObject->requiredToComplete=removeLetter(returnObject->requiredToComplete,i);

			}

		}

		//Update global vars if this is a completeWindow
		if(returnObject->requiredToComplete.length()==0){
			updateGlobalWindowVariables(returnObject->windowStart,returnObject->windowEnd);
		}

		if(returnObject->windowStart==-1){
			//No window was created
			returnObject->isThereWindow=false;
		}
		else{
			returnObject->isThereWindow=true;
		}

		return returnObject;

	}

	//One or both windows present
		//Checking leftWindow
	if(leftWindow->isThereWindow!=false){
		//cout<<"Left= "<<l<<" Right= "<<r<<" leftWindowScan "<<" requiredToComplete= "<<leftWindow->requiredToComplete<<endl;
		for(int i=mid;i<=r;i++){

			if(isRequired(mainString[i],leftWindow->requiredToComplete)){
				leftWindow->windowEnd=i;
				leftWindow->requiredToComplete=removeLetter(leftWindow->requiredToComplete,i);
			}

		}

		//Update global vars if this is a completeWindow
		if(leftWindow->requiredToComplete.length()==0){
			updateGlobalWindowVariables(leftWindow->windowStart,leftWindow->windowEnd);
		}

	}	
		//Checking rightWindow
	if(rightWindow->isThereWindow!=false){
		//cout<<"Left= "<<l<<" Right= "<<r<<" rightWindowScan "<<" requiredToComplete= "<<rightWindow->requiredToComplete<<endl;
		for(int i=mid;i>=l;i--){

			if(isRequired(mainString[i],rightWindow->requiredToComplete)){
				rightWindow->windowStart=i;
				rightWindow->requiredToComplete=removeLetter(rightWindow->requiredToComplete,i);
			}

		}

		//Update global vars if this is a completeWindow
		if(rightWindow->requiredToComplete.length()==0){
			updateGlobalWindowVariables(rightWindow->windowStart,rightWindow->windowEnd);
		}

	}

	//Checking minWindow 
	if(rightWindow->isThereWindow==false){
		returnObject->windowStart=leftWindow->windowStart;
		returnObject->windowEnd=leftWindow->windowEnd;
		returnObject->requiredToComplete=leftWindow->requiredToComplete;
	}
	else if(leftWindow->isThereWindow==false){
		returnObject->windowStart=rightWindow->windowStart;
		returnObject->windowEnd=rightWindow->windowEnd;
		returnObject->requiredToComplete=rightWindow->requiredToComplete;
	}
	else{

		int leftWindowSize=leftWindow->windowEnd-leftWindow->windowStart+1,rightWindowSize=rightWindow->windowEnd-rightWindow->windowStart+1;

		if(leftWindowSize<rightWindowSize){
			returnObject->windowStart=leftWindow->windowStart;
			returnObject->windowEnd=leftWindow->windowEnd;
			returnObject->requiredToComplete=leftWindow->requiredToComplete;
		}
		else{
			returnObject->windowStart=rightWindow->windowStart;
			returnObject->windowEnd=rightWindow->windowEnd;
			returnObject->requiredToComplete=rightWindow->requiredToComplete;	
		}

	}

	returnObject->isThereWindow=true;
	return returnObject;

}


int main(){

	findWindow(0,mainString.length()-1);
	cout<<"startWindow= "<<globalStartWindow<<" endWindow= "<<globalEndWindow<<endl;

	return 0;
}