#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "textlcd.h"

int main(int argc, char * argv[]){
	text(argv[1], argv[2]);
	
	return 0;
}