#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>
#include <unistd.h> // for open/close
#include <fcntl.h> // for O_RDWR
#include <sys/ioctl.h> // for ioctl
#include <sys/msg.h>
#include <pthread.h>
#include "touch.h"


#define INPUT_DEVICE_LIST  "/dev/input/event" //실제 디바이스 드라이버 노드파일: 뒤에 숫자가 붙음., ex)/dev/input/event5
#define PROBE_FILE  "/proc/bus/input/devices" //PPT에 제시된 "이 파일을 까보면 event? 의 숫자를 알수 있다"는 바로 그 파일


int probeTouchPath(char *newPath)
{

    int returnValue = 0; //button에 해당하는 event#을 찾았나?
	int number = 0; //찾았다면 여기에 집어넣자

#define HAVE_TO_FIND_1 "N: Name=\"WaveShare WS170120\"\n"
#define HAVE_TO_FIND_2 "H: Handlers=mouse0 event"
   
    FILE *fp = fopen(PROBE_FILE,"rt");
	while(!feof(fp)) 
    { 
        
        char tmpStr[200]; //200자를 읽을 수 있게 버퍼
	      fgets(tmpStr,200,fp); //최대 200자를 읽어봄
	           //printf ("%s",tmpStr);
	 if (strcmp(tmpStr,HAVE_TO_FIND_1) == 0){
		printf("YES! I found!: %s\r\n", tmpStr);
		returnValue = 1; //찾
    }

     if ((returnValue == 1) && (strncasecmp(tmpStr, HAVE_TO_FIND_2, strlen(HAVE_TO_FIND_2)) == 0) )
	{
	printf ("-->%s",tmpStr);
	printf("\t%c\r\n",tmpStr[strlen(tmpStr)-3]);
	number = tmpStr[strlen(tmpStr)-3] - '0';
	//Ascii character '0'-'9' (0x30-0x39)
	//to interger(0)
	break;
    }
    }


    fclose(fp);
	if (returnValue == 1)
		sprintf (newPath,"%s%d",INPUT_DEVICE_LIST,number);
	return returnValue;
}


static pthread_t touchTh_id ;
static int fd =0;
static int msgID = 0;




void *touchThFunc(void* args)
{   
      int x=0;
      int y=0;
      struct input_event stEvent;
       printf("TOUCH SCRREN  ready \r\n");
    BUTTON_MSG_T sendMsg;
    sendMsg.messageNum = 1;
   sendMsg.keyInput = 999;
    
	while(1)
	{ 
            read(fd, &stEvent , sizeof (stEvent));

                if(stEvent.type == EV_ABS)
                    { 
                            if(stEvent.code == ABS_MT_POSITION_X){
                                          x = stEvent.value ;              
                                       //printf("touch x: %d\r\n",stEvent.value);
                                           }
                              else if (stEvent.code ==ABS_MT_POSITION_Y)
                                    {
                                          y= stEvent.value;
                                      //  printf("touch y: %d\r\n",stEvent.value);
                                    }
                    }

                                
                else if ((stEvent.type == EV_KEY ) && (stEvent.code == BTN_TOUCH )  )
                {
                               sendMsg.x = x;
                               sendMsg.y = y;
                              
                             if   (stEvent.value ==0 ){
                                    sendMsg.pressed=0;
                                 //printf("finish\r\n");
                                       }

                              else if (stEvent.value ==1) 
                              {    
                                   sendMsg.pressed=1;
                                    //printf("you touch now\r\n");
                                   
                                
                              }
                            msgsnd(msgID ,&sendMsg , sizeof(BUTTON_MSG_T) - sizeof(long int),0);
                        

                         

               }
               
    }


}
    int touchInit(void){
	     
        char touchPath[1024];

	if (probeTouchPath(touchPath) == 0)
      {
            printf(" open fail ");
	         return 0;
      }
	fd=open (touchPath, O_RDONLY);
    msgID = msgget (MESSAGE_ID, IPC_CREAT|0666);
    //printf("trash id %d", msgID );


    BUTTON_MSG_T trashCan;
    while(msgrcv (msgID, &trashCan, sizeof(BUTTON_MSG_T) - sizeof(long int),0,IPC_NOWAIT) >= 0)
            { 
               printf("cleaning message" );
                } 
       pthread_create(&touchTh_id ,NULL , touchThFunc, NULL);
	return 1;
}


int touchExit(void)
 {
      pthread_cancel(touchTh_id);
 }
