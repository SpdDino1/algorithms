#include<bits/stdc++.h>
using namespace std;

struct activity{
    //times
    int id;
    int arrival;
    int computeLeft;
    int waiting;
    int execTime;
    int priority;
};

int executingProcessIndex=-1;

vector <activity> input;

bool sortingMech(struct activity a,struct activity b){
    return (a.arrival<b.arrival);
}

bool allProcessComplete(){
    for(int i=0;i<input.size();i++){
        if(input[i].computeLeft!=0){
            return false;
        }
    }
    return true;
}

void searchForProcess(int currentTime){
	int remainingTime=1000000;

	for(int i=0;i<input.size();i++){
		if((input[i].arrival<=currentTime)&&(input[i].computeLeft<remainingTime)&&(input[i].computeLeft!=0)){
			remainingTime = input[i].computeLeft;
			executingProcessIndex = i;
		}
	}
}

void srtfSchedule(int currentTime){
	if(executingProcessIndex==-1){
		searchForProcess(currentTime);
	}

	if(executingProcessIndex==-1){
        cout<<"no available process"<<endl;
        return;
	}

	for(int i=0;i<input.size();i++){
		if((input[i].arrival<=currentTime)&&(input[i].computeLeft!=0)){
            if(i==executingProcessIndex){
                cout<<"Executing = "<<input[i].id<<endl;
                input[i].computeLeft--;
            	executingProcessIndex=-1;
            }
            else{
                input[i].waiting++;
            }
        }
	}
	return;
}


int main(){
	struct activity temp;
    //Activity Initialization;
    temp.id=1;
    temp.arrival = 1;
    temp.computeLeft =10;
    temp.execTime = temp.computeLeft;
    temp.waiting = 0;
    input.push_back(temp);       
   
    temp.id=2;
    temp.arrival = 3;
    temp.computeLeft =5;
    temp.execTime = temp.computeLeft;
    temp.waiting = 0;
    input.push_back(temp);               
   
    temp.id=3;
    temp.arrival = 3;
    temp.computeLeft =4;
    temp.execTime = temp.computeLeft;
    temp.waiting = 0;
    input.push_back(temp);              
    //.......................

    sort(input.begin(),input.end(),sortingMech);

    for(int t=0;t<50;t++){
    	cout<<"\n\nTime = "<<t<<endl;
    	if(!allProcessComplete()){
        	srtfSchedule(t);
        }
        else{
            cout<<"All Processes Completed";
            break;
        }
    }

    cout<<"\n\nProcess Stats"<<endl;
       
    float netWaitTime=0;
   
    for(int i=0;i<input.size();i++){
        cout<<"Process ID = "<<input[i].id<<endl;
        cout<<"Waiting Time = "<<input[i].waiting<<endl;
        cout<<"TurnAround Time = "<<(input[i].waiting+input[i].execTime)<<endl;
        netWaitTime = netWaitTime + input[i].waiting;
        cout<<endl;
    }
    cout<<"Avg Wait Time = "<<(netWaitTime/(float)input.size())<<endl;

	return 1;
}