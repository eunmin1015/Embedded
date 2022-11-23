#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "led.h"

#define LED_DRIVER_NAME "/dev/periled"

void doHelp(void)
{
printf("ledtest <hex byte> :data bit0 operation 1=>on 0=>off\n");
printf(" ledtest 0x05 ;4th and 1th led on\n");
printf(" ledtest 0xff ;all led on\n");
printf(" ledtest 0x00 ;all led off\n");
}


int main(int argc, char *argv[])
{
	unsigned int data1 = 0;
	unsigned int data2 = 0;
	
	if (argc < 3 ){
      perror(" Args number is less than 3\n");
      doHelp();
      return 1;
   }
	ledlibinit();
	
	
	data1 = strtol(argv[1],NULL,16);
	data2 = strtol(argv[2],NULL,16);

	
	printf ("--> %d, %d\r\n", data1, data2);
	ledonoff(data1,data2);
	sleep(1);
	ledlibexit();
	
	
	
	return 0;
}

