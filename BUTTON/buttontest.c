#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>
#include <unistd.h> // for open/close
#include <fcntl.h> // for O_RDWR
#include <sys/ioctl.h> // for ioctl
#include <sys/msg.h>
#include <pthread.h>
#include "button.h"
#include "led.h"

#define LED_DRIVER_NAME "/dev/periled"
#define MAX_LED_NUM 8
#define INPUT_DEVICE_LIST "/dev/input/event" //실제 디바이스 드라이버 노드파일: 뒤에 숫자가 붙음., ex)/dev/input/event5
#define PROBE_FILE "/proc/bus/input/devices" //PPT에 제시된 "이 파일을 까보면 event? 의 숫자를 알수 있다"는 바로 그 파일
#define HAVE_TO_FIND_1 "N: Name=\"ecube-button\"\n"
#define HAVE_TO_FIND_2 "H: Handlers=kbd event"


int main(int argc, char *argv[])
{   
	ledlibinit();
	BUTTON_MSG_T B;
	int returnValue = 0;
	int msgID = msgget (MESSAGE_ID, IPC_CREAT|0666);
	
	if (msgID == -1){
	printf ("Cannot get msgQueueID, Return!\r\n");
	return -1;
	}

	buttonInit();
   // buttonThFunc();
	while(1){
	    
		returnValue = msgrcv(msgID, &B, sizeof(unsigned short)*2 + sizeof(int), 0, 0);

		if(B.messageNum == EV_KEY){
			switch(B.keyInput)
			{
			case KEY_HOME:printf("pressed");	break;
			case KEY_BACK: ledonoff(0x00,0); break;
			case KEY_SEARCH: ledonoff(0x01,1); break;
			case KEY_MENU: ledonoff(0x01,0); break;
			case KEY_VOLUMEUP: ledonoff(0x02,1); break;
			case KEY_VOLUMEDOWN: ledonoff(0x02,0);break;
			}
			if ( B.pressed ) printf("pressed\n");
			else printf("released\n");
		}
		else ; 
		
	}
	
	
	buttonExit();
	return 0;
}
