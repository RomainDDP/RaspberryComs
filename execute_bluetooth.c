#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(){
	FILE *f;
	char c[BUFFER_SIZE];
	f=fopen("/dev/rfcomm0", "r");
	if (f ==NULL){
		perror("Error openning File '/dev/rfcomm0' \n");
		exit(1);
		}
	if (fgets(c,BUFFER_SIZE,f)!=NULL){
		c[strcspn(c, "\n")] = 0;
		printf("execute command %s \n",c);
		}
		
	if (system(c) == -1){
		perror("Fail executing \n");
		exit(2);
		}
	printf("Execution Done \n");
	fclose(f);
	return 0;
	
	}
