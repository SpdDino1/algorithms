#include<bits/stdc++.h>
using namespace std;

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

int main(){

        int i,j;
        int completedProcessesCount =0;

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
        temp.arrival = 4;
        temp.computeLeft =2;
        temp.execTime = temp.computeLeft;
        temp.waiting = 0;
        input.push_back(temp);               
        //.......................
       
        sort(input.begin(),input.end(),sortingMech);

        /*for(int i=0;i<input.size();i++){
                cout<<input[i].id<<" ";       
        }*/       
       
        for(int t=1;t>-1;t++){
                completedProcessesCount=0;
                cout<<"\n\nTime = "<<t<<endl;
               
                for(i=0;i<input.size();i++){
            		if(t>=input[i].arrival){
            			if(input[i].computeLeft==0){
                            completedProcessesCount++;
                        }
                        else{
                                cout<<"Executing = "<<input[i].id<<endl;
                                input[i].computeLeft--;
                               
                                for(j=i+1;j<input.size();j++){
                                        input[j].waiting++;                               
                                }
                                break;
                        }
            		}                                             
                }
                if(completedProcessesCount==(input.size()-1)){
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