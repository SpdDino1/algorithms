#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<strings.h>

//File name = test.txt

int main(){
	int filePointer;
	filePointer = open("test.txt",O_RDWR);

	char buffer[1];

	//reading mech
	while(read(filePointer,buffer,1)>0){
		printf("%c",buffer[0]);
	}

	//writing mech
	char writeText[] = "Text has changed!!";

	write(filePointer,writeText,strlen(writeText));
	close(filePointer);
}