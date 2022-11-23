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

static unsigned int ledvalue = 0;
static int fd = 0;
int ledonoff(int lednum, int onoff)
{
	int i = 1;
	i = i<<lednum;
	ledvalue = ledvalue& (~i);
	if(onoff != 0)
	{
		ledvalue |= i;
	}
	write(fd,&ledvalue,4);
}

int ledlibinit(void)
{
	fd = open("/dev/periled", O_WRONLY);
	ledvalue = 0;
}

int ledlibexit(void)
{
	ledvalue = 0;
	ledonoff(0,0);
	close(fd);
}
