#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100

char *stack[MAX];
int top=-1;
void push(char *dir){
	if(top==MAX-1){
	printf("stack overflow\n");
	return;
	}
	top++;
	stack[top]=strdup(dir);
}
char *pop(){
	if(top==-1){
	printf("stack is empty\n");
	return NULL;
	}
	char *dir=stack[top];
	top--;
	return dir;
}

int main(){
    char currentdir[256];
	char input[256];
    while(1){
    	printf("current dir:%s\n",currentdir);
    	
    	printf("enter pushd,popd or exit:");
    	scanf("%s",input);
    	
    	if(strcmp(input,"pushd")==0){
    		char newdir[256];
    		printf("Enter dir to push: ");
    		scanf("%s",newdir);
    		push(currentdir);
    		strcpy(currentdir,newdir);
    	}
	else if(strcmp(input,"popd")==0){
		char *prevdir=pop();
		if(prevdir!=NULL){
		 strcpy(currentdir,prevdir);
		 free(prevdir);
		}
	} 
	else if(strcmp(input,"exit")==0){
		break;
	}   	
	else{
	printf("Invalid command\n");
	}
    } 
    return 0;   
}
