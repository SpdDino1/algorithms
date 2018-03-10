//Banker's

#include<bits/stdc++.h>
using namespace std;

int seqCount=0;

//global vars
int resCount;
int processCount;
vector <int> alreadyAllocated;
//...........

//Global volatile Vars
vector <int> seq;
//..................

void findSeq(vector <int> freeRes,vector <int> processNeeds){
	//cout<<"called"<<endl;
	int i,j,z,zeroCount=0;
	//Check if all processes satisfied already
	if(seq.size()==processCount){
		cout<<"\n";
		for(i=0;i<seq.size();i++){
			cout<<seq[i]<<" ";	
		}
		seqCount++;
		return;	
	}
	
	//Iterating through processes
	for(i=0;i<processNeeds.size();i+=resCount){
		
		//Check if process 'i' is safe
		z=0,zeroCount=0;
		for(j=i;j<(i+resCount);j++){
			if(processNeeds[j]>freeRes[z]){
				break;
			}
			else if(processNeeds[j]==0){
				zeroCount++;								
			}
			z++;	
		}
		if((z==resCount)&&(zeroCount!=resCount)){
			//Is Safe Process
			seq.push_back(i/resCount);
			
			vector <int> storeFreeRes;
			vector <int> storeProcessNeeds;
		
			//Store original vectors
			for(int p=0;p<freeRes.size();p++){
				storeFreeRes.push_back(freeRes[p]);			
			}
			for(int p=0;p<processNeeds.size();p++){
				storeProcessNeeds.push_back(processNeeds[p]);			
			}	
			
			//Release Allocated Resources / Update freeResource List
			z=0;
			for(j=i;j<(i+resCount);j++){
				freeRes[z] = freeRes[z]+alreadyAllocated[j];
				processNeeds[j] = 0;
				z++;
			}
			
			findSeq(freeRes,processNeeds);
			seq.pop_back();

			//Reinitialize to original
			freeRes.clear();
			for(int p=0;p<storeFreeRes.size();p++){
				freeRes.push_back(storeFreeRes[p]);			
			}
			processNeeds.clear();
			for(int p=0;p<storeProcessNeeds.size();p++){
				processNeeds.push_back(storeProcessNeeds[p]);			
			}

		}
	}
	return;
}

int main(){
	
	//Input..................
	vector <int> freeRes;
	freeRes.push_back(2);//Resource 0
	freeRes.push_back(3);//Resource 1
	freeRes.push_back(0);//Resource 2

	vector <int> processFullDemand;
	processFullDemand.push_back(7);//Process 0
	processFullDemand.push_back(5);
	processFullDemand.push_back(3);

	processFullDemand.push_back(3);//Process 1
	processFullDemand.push_back(2);
	processFullDemand.push_back(2);

	processFullDemand.push_back(9);//Process 2
	processFullDemand.push_back(0);
	processFullDemand.push_back(2);

	processFullDemand.push_back(2);//Process 3
	processFullDemand.push_back(2);
	processFullDemand.push_back(2);

	processFullDemand.push_back(4);//Process 4
	processFullDemand.push_back(3);
	processFullDemand.push_back(3);

	//Resources already allocated to processes
	alreadyAllocated.push_back(0);//Process 0
	alreadyAllocated.push_back(1);
	alreadyAllocated.push_back(0);

	alreadyAllocated.push_back(3);//Process 1
	alreadyAllocated.push_back(0);
	alreadyAllocated.push_back(2);

	alreadyAllocated.push_back(3);//Process 2
	alreadyAllocated.push_back(0);
	alreadyAllocated.push_back(2);

	alreadyAllocated.push_back(2);//Process 3
	alreadyAllocated.push_back(1);
	alreadyAllocated.push_back(1);

	alreadyAllocated.push_back(0);//Process 4
	alreadyAllocated.push_back(0);
	alreadyAllocated.push_back(2);
	//.......................

	//Calculating pending needs
	vector <int> processNeeds;
	for(int i=0;i<processFullDemand.size();i++){
		processNeeds.push_back(processFullDemand[i]-alreadyAllocated[i]);
	}


	resCount = freeRes.size();
	processCount = processNeeds.size()/resCount;
	
	findSeq(freeRes,processNeeds);	

	cout<<"\n\nTotal Sequences = "<<seqCount<<endl;	

	return 1;
}