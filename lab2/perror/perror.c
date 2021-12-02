#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "perror.h"

extern void my_perror(char *str);

void main (int argc, char *argv[]){
	FILE *f;
	
	if ( argc < 2){
		printf("Usage : %s nof I lename \n", argv[0]);
		exit(1);
		}
	if ((f = fopen(argv[1],"r")) == NULL){
		my_perror(NULL);
		exit(1);
		}
		
	printf("open a file \"%s\".\n", argv[1]);
	fclose(f);
	}
