#include <bits/stdc++.h>
using namespace std;

struct activity{
	int start;
	int end;
	int duration;
};

vector <activity> activityList;

int main(){
	int size;
	cout<<"How many activities?"<<endl;
	cin>>size;

	activity temp;

	for(int i=0;i<size;i++){
		cout<<"Activity "<<(i+1)<<endl;
		cout<<"Start = ";
		cin>>temp.start;
		cout<<"End = ";
		cin>>temp.end;
		temp.duration = (temp.end-temp.start);
		activityList.push_back(temp);
	}

	cout<<"\ni value = ";
	int x;
	cin>>x;
	x--; //converting to index value

	activity min;
	int pos;

	for(int j=0;j<(activityList.size()-1);j++){
		min = activityList[j];
		for(int k=j+1;k<activityList.size();k++){
			if(activityList[k].duration<min.duration){
				min = activityList[k];
				pos = k; 
			}
		}
		temp = activityList[j];
		activityList[j] = min;
		activityList[pos] = temp;

		if(x==j){
			cout<<"Duration of "<<(j+1)<<"th Smallest Activity = "<<activityList[j].duration<<endl;
			return 1;
		}
	}
	cout<<"Duration of "<<(x+1)<<"th Smallest Activity = "<<activityList[activityList.size()-1].duration<<endl;
}