#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

//random range = 1 to 100

void *primeCounterThread();

int main(int argc, char *argv[]){

	if(argc==1){
		printf("%s\n","Usage: ./a.out <<No of threads>>");
		return 1;
	}

	pthread_t tid[atoi(argv[1])]; //thread pool of ids

	int i=0,code;
	
	while(i<atoi(argv[1])){
		code = pthread_create(&tid[i],NULL,primeCounterThread,NULL);

		if(code!=0){
			printf("\nAn Error Occured While Creating Thread %d", i+1);
		}
		i++;
	}
}

void *primeCounterThread(){
	int primesTill = rand()%101;

	int count,i=2,j,flag;

	while(i<=primesTill){
		flag=0;
		j=2;
		while(j<i){
			if((i%j)==0){
				flag=1;
				break;
			}
			j++;
		}
		if(flag==0){
			count++;
		}
		i++;
	}
	printf("Primes Till %d = %d\n",primesTill,count);

	pthread_exit(0);
}