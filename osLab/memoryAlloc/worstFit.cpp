//bestFit

#include<bits/stdc++.h>
using namespace std;

struct memUnit{
	int start;
	int end;
	bool isUsed;
};

vector <struct memUnit> ram;

//Input........
int size = 100;
//............

void displayRam(){
	cout<<"Ram Status"<<endl;
	for(int i=0;i<ram.size();i++){
		cout<<"Partition "<<(i+1)<<": Start = "<<ram[i].start<<" End = "<<ram[i].end<<" Space = "<<ram[i].end-ram[i].start+1<<" isUsed = "<<ram[i].isUsed<<endl;
	}
	cout<<endl;	
}

void requestSpace(){
	int req;
	cout<<"Space Needed?"<<endl;
	cin>>req;

	struct memUnit temp;

	int worstPartitionIndex = -1;
	int partitionSize = 0; //Consider as infinity

	for(int i=0;i<ram.size();i++){
		if(!ram[i].isUsed){
			if(((ram[i].end-ram[i].start+1)>=req)&&((ram[i].end-ram[i].start+1)>partitionSize)){	//finding worst partition
				worstPartitionIndex =i;
				partitionSize = ram[i].end-ram[i].start+1;
			}
		}	
	}

	if(worstPartitionIndex!=-1){
		if((ram[worstPartitionIndex].end-ram[worstPartitionIndex].start+1)==req){	//Allocate Full Block
			ram[worstPartitionIndex].isUsed = 1;
			cout<<"\nMemory Alloted"<<endl;
			return;
		}
		else if((ram[worstPartitionIndex].end-ram[worstPartitionIndex].start+1)>req){	//Allocate a part
			struct memUnit free;
			free.start = ram[worstPartitionIndex].start;
			free.end = ram[worstPartitionIndex].end-req;
			free.isUsed = false;

			struct memUnit claimed;
			claimed.start = ram[worstPartitionIndex].end-req+1;
			claimed.end = ram[worstPartitionIndex].end;
			claimed.isUsed = true;

			ram.erase(ram.begin()+worstPartitionIndex,ram.begin()+worstPartitionIndex+1);
			ram.insert(ram.begin()+worstPartitionIndex,claimed);
			ram.insert(ram.begin()+worstPartitionIndex,free);
			cout<<"\nMemory Alloted"<<endl;
			return;
		}
	}
	cout<<"\nNo Free Space"<<endl;
	return;
}

void defragmentMemory(){
	for(int i=0;i<ram.size()-1;i++){
		if((ram[i].isUsed==0)&&(ram[i+1].isUsed==0)){
			ram[i].end = ram[i+1].end;
			ram.erase(ram.begin()+i+1,ram.begin()+i+2);
			cout<<"\nPartition Merged"<<endl;
			--i;
		}
	}
}

void freeSpace(){
	int partNo;
	cout<<"Partition To Free?"<<endl;
	cin>>partNo;
	partNo--; //Index

	if(ram[partNo].isUsed ==1){
		ram[partNo].isUsed=0;
		cout<<endl;
		cout<<"\nPartition Freed"<<endl;

		defragmentMemory();
		return;	
	}
	cout<<"\nInvalid Operation"<<endl;
}

int main(){
	struct memUnit temp;
	//Initializing ram
	temp.start=0;
	temp.end=size-1;
	temp.isUsed=false;
	ram.push_back(temp);
	//................

	//Input Ram Status
		//No processes in memory
	//................
	int choice;
	while(true){
		cout<<endl;
		displayRam();
		cout<<endl;
		cout<<"Press 1 To Request Memory"<<endl;
		cout<<"Press 2 To Release Memory"<<endl;
		cin>>choice;
		if(choice==1){
			requestSpace();		
		}
		else if(choice==2){
			freeSpace();		
		}
	}
	
}
