#include <stdio.h>
#include <sys/ipc.h>
#include "touch.h"

int main(void)
{
    touchInit();
    int msgID = msgget (MESSAGE_ID, IPC_CREAT | 0666);
    TOUCH_MSG_T B;
    while(1);
    {
        msgrcv(msgID, &B, sizeof(B)- sizeof(long int), 0, 0);

        switch (B.keyInput)
        {
            case 999:
                if(B.pressed == 1)
                {
                    if(B.x < 100 && B.y <100)
                    {
                        printf("left top");
                    }
                    else if (B.x > 500 && B.y < 100)
                    {
                        printf("right top");
                    }
                    else if (B.x <100 && B.y > 300)
                    {
                        printf("left bottom");
                    }
                    else if (B.x > 500 && B.y > 300)
                    {
                        printf("right bottom");
                    }
                    else printf("hmm... %d, %d", B.x, B.y);
                }
        }
break;
    }

}
