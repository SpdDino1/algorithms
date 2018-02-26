#include<bits/stdc++.h>
using namespace std;

//Input..................
int timeSlice = 3;
//.......................
int timeSliceRemaining=0;
int timeSliceUsedBy=-1;


struct activity{
        //times
        int id;
        int arrival;
        int computeLeft;
        int waiting;
        int execTime;
};

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

void allotFreshTimeSlice(int currentTime){
        //Search right side of input (next processes)
        for(int i=timeSliceUsedBy+1;i<input.size();i++){
                if((input[i].arrival<=currentTime)&&(input[i].computeLeft != 0)){
                        timeSliceUsedBy = i;
                        timeSliceRemaining=timeSlice;
                        //cout<<"Right Alloc"<<endl;
                        return;
                }
        }

        //Search left side of input (earlier processes)
        for(int i=0;i<timeSliceUsedBy;i++){
                if((input[i].arrival<=currentTime)&&(input[i].computeLeft != 0)){
                        timeSliceUsedBy = i;
                        timeSliceRemaining=timeSlice;
                        cout<<"Left Alloc"<<endl;
                        return;
                }
        }

        //Try to allot time slice to same process
        if((timeSliceUsedBy!=-1)&&(input[timeSliceUsedBy].arrival<=currentTime)&&(input[timeSliceUsedBy].computeLeft!=0)){
                timeSliceRemaining=timeSlice;
                //cout<<"Same Alloc"<<endl;
                return;
        }

        //No available processes
        timeSliceUsedBy = -1;
        cout<<"no available process"<<endl;
        return;
}

void roundRobin(int currentTime){

        if(timeSliceRemaining==0){
                //cout<<"time slice alotted function called"<<endl;
                allotFreshTimeSlice(currentTime);                
        }

        if(timeSliceUsedBy!=-1){
                for(int i=0;i<input.size();i++){
                        if((input[i].arrival<=currentTime)&&(input[i].computeLeft!=0)){
                                if(i==timeSliceUsedBy){
                                        cout<<"Executing = "<<input[timeSliceUsedBy].id<<endl;
                                        input[i].computeLeft--;
                                        timeSliceRemaining--;
                                        if(input[i].computeLeft==0){
                                                timeSliceRemaining=0;
                                        }
                                }
                                else{
                                        input[i].waiting++;
                                }
                        }
                }
        }
}

int main(){

        int i,j;

        struct activity temp;
        //Activity Initialization;
        temp.id=1;
        temp.arrival = 3;
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
        temp.arrival = 2;
        temp.computeLeft =4;
        temp.execTime = temp.computeLeft;
        temp.waiting = 0;
        input.push_back(temp);               
        //.......................
       
        sort(input.begin(),input.end(),sortingMech);

        /*for(int i=0;i<input.size();i++){
                cout<<input[i].id<<" ";       
        }*/       
       
        for(int t=1;t<50;t++){
                cout<<"\n\nTime = "<<t<<endl;

                if(!allProcessComplete()){
                        roundRobin(t);
                }
                else{
                        cout<<"All Processes Completed";
                        break;
                }
        }

        cout<<"\n\nProcess Stats"<<endl;
       
        float netWaitTime=0;
       
        for(i=0;i<input.size();i++){
                cout<<"Process ID = "<<input[i].id<<endl;
                cout<<"Waiting Time = "<<input[i].waiting<<endl;
                cout<<"TurnAround Time = "<<(input[i].waiting+input[i].execTime)<<endl;
                netWaitTime = netWaitTime + input[i].waiting;
                cout<<endl;
        }
        cout<<"Avg Wait Time = "<<(netWaitTime/(float)input.size())<<endl;

return 1;
} 