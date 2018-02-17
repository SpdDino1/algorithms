#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

//Input......
int unsorted[]={10,9,8,7,6,5,4,3,2,1};
//...........

struct indexBounds{
	int start;
	int end;
};

void *sortingThread(void *param);
void *mergingThread(void *param);

int main(int argc, char *argv[]){
	int arrayLastIndex = (sizeof(unsorted)/sizeof(unsorted[0]))-1;

	int code;
	pthread_t sorter1,sorter2,merger;

	struct indexBounds sorter1Params;
	sorter1Params.start = 0;
	sorter1Params.end = (arrayLastIndex/2);
	
	code = pthread_create(&sorter1,NULL,sortingThread,(void *)&sorter1Params); 
	if(code!=0){
		printf("\nAn Error Occured While Creating sorter1");
		return 1;
	}

	struct indexBounds sorter2Params;
	sorter2Params.start = (arrayLastIndex/2)+1;
	sorter2Params.end = arrayLastIndex;

	code = pthread_create(&sorter2,NULL,sortingThread,(void *)&sorter2Params); 
	if(code!=0){
		printf("\nAn Error Occured While Creating sorter2");
		return 1;
	}

	pthread_join(sorter1,NULL);
	pthread_join(sorter2,NULL);

	code = pthread_create(&merger,NULL,mergingThread,(void *)arrayLastIndex); 
	if(code!=0){
		printf("\nAn Error Occured While Creating merger");
		return 1;
	}	
	pthread_join(merger,NULL);
}

void *sortingThread(void *param){
	struct indexBounds *bounds = param;

	int i=bounds->start,j;
	int min,pos,store;

	while(i<bounds->end){
		min = unsorted[i];
		j=i+1;
		pos=i;
		while(j<=bounds->end){
			if(unsorted[j]<min){
				min = unsorted[j];
				pos=j;
			}
			j++;
		}
		store = unsorted[i];
		unsorted[i] = min;
		unsorted[pos] = store;
		
		i++;
	}
	printf("Sorter Complete\n");

	pthread_exit(0);
}

void *mergingThread(void *param){
	int arraySize = (int*)param;
	int sorted[arraySize+1];
	int p=0;

	int l=0,r=(arraySize/2)+1;

	while((l<=(arraySize/2))&&(r<=arraySize)){
		if(unsorted[l]<unsorted[r]){
			sorted[p] = unsorted[l];
			l++;
			p++;
		}
		else{
			sorted[p] = unsorted[r];
			r++;
			p++;
		}
	}

	if(l>(arraySize/2)){//left exhausted
		while(r<=arraySize){
			sorted[p] = unsorted[r];
			r++;
			p++;
		}
	}
	else{ //right exhausted
		while(l<=(arraySize/2)){
			sorted[p] = unsorted[l];
			l++;
			p++;
		}
	}

	int i=0;
	while(i<=arraySize){
		printf("%d ",sorted[i]);
		i++;
	}
	printf("\nMerger Complete\n");
	pthread_exit(0);
}