#ifndef _LED_H_
#define _LED_H_

int ledlibinit(void);
int ledonoff(int lednum, int onoff);
int ledlibexit(void);

#define LED_DRIVER_NAME "/dev/periled"

#endif _LED_H_
