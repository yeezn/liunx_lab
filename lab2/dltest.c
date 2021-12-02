#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "math.h"

int main(){
	void *handle;
  	int (*add)(int,int),(*divi)(int,int),(*sub)(int,int),(*mult)(int,int);
  	char *error;
  
  	handle = dlopen("./lib/libshare.so", RTLD_LAZY);
  
  	if (!handle) {
    		fputs(dlerror(), stderr);
    		exit(1);
  	}
    	
    	char* str = (char*)malloc(10*sizeof(char));
    	int a, b;
    	
    	printf("What do uou want to Calculate?");
    	scanf("%s", str);
    	
    	printf("Two num = ");
    	scanf("%d %d",&a, &b);
    	
  	if (strcmp(str, "add")==0){
  		add = dlsym(handle, "add");
  		if(( error = dlerror()) != NULL){
    	 		fprintf(stderr, "%s" , error);
    	 		exit(1);
  			}
  			printf("add = %d\n", (*add)(a,b));
  		}
  	else if (strcmp(str, "sub")==0){
  		sub = dlsym(handle, "sub");
  		if(( error = dlerror()) != NULL){
    	 		fprintf(stderr, "%s" , error);
    	 		exit(1);
  			}
  			printf("sub = %d\n", (*sub)(a,b));
  		}
  	else if (strcmp(str, "divi")==0){
  		divi = dlsym(handle, "divi");
  		if(( error = dlerror()) != NULL){
    	 		fprintf(stderr, "%s" , error);
    	 		exit(1);
  			}
  			printf("divi = %d\n", (*divi)(a,b));
  		}
  	else if (strcmp(str, "mult")==0){
  		mult = dlsym(handle, "mult");
  		if(( error = dlerror()) != NULL){
    	 		fprintf(stderr, "%s" , error);
    	 		exit(1);
  			}
  			printf("mult = %d\n", (*mult)(a,b));
  		}
  	dlclose(handle);
  	free(str);
  	}
