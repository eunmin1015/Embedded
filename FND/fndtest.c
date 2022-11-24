#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "fnd.h"

int main(int argc, char* argv[]){
	unsigned int number = 0;
	number = strtol(argv[2],NULL,10);
	
	
	fnd(*argv[1], number);
}