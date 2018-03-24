#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[],char *envp[]){
	unsigned int envp_num=strlen(envp);
	int i;
	printf("Command-line arguments:\n");
	for(i=0;i<argc;i++){
		printf("%s\n",argv[i]);
	}
	printf("Environment variables:\n");
	for(i=0;i<envp_num;i++){
		printf("%s\n",envp[i]);
	}
}
