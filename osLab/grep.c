#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

//grep word file

int main(int argc, char *argv[]){
	char *ret;

	FILE *fPtr;
	char oneLine[1000];

	fPtr =fopen(argv[2],"r");

	if(fPtr==NULL){
		printf("\n%s","Unable to open file");
	}
	else{
		//Reading line by line...

		while(fgets(oneLine,1000, fPtr)!=NULL){
			ret = strstr(oneLine,argv[1]);
			if(ret!=NULL){
				printf("%s",ret);			
			}
		}
	}
	return 1;
}