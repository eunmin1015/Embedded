#include <stdio.h>
#include <sys/ipc.h>
#include "touch.h"

int main(void)
{
    touchInit();
    int msgID = msgget (MESSAGE_ID, IPC_CREAT | 0666);
       BUTTON_MSG_T recvMsg;
    while(1)
    {
        msgrcv(msgID, &recvMsg, sizeof(BUTTON_MSG_T)- sizeof(long int), 0, 0);
         
        switch (recvMsg.keyInput)
        {
            case 999:
                    if(recvMsg.pressed==1)
                { 
                    if(recvMsg.x < 100 && recvMsg.y <100)
                    {
                        printf("left top\r\n");
                    }
                    else if (recvMsg.x > 500 && recvMsg.y < 100)
                    {
                        printf("right top\r\n");
                    }
                    else if (recvMsg.x <100 && recvMsg.y > 300)
                    {
                        printf("left bottom\r\n");
                    }
                    else if (recvMsg.x > 500 && recvMsg.y > 300)
                    {
                        printf("right bottom\r\n");
                    }
                    else printf("you touch center?.. %d, %d\r\n", recvMsg.x, recvMsg.y);
                }
        
break;
    }

}
}
