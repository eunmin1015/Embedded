all: project

project : libMyPeri.a main.c
	arm-linux-gnueabi-gcc main.c  -l MyPeri -L. -o project -lpthread
	scp ./project ecube@192.168.111.22:/home/ecube
libMyPeri.a : button.o led.o buzzer.o fnd.o ColorLed.o Temperature.o acc.o textlcd.o bitmap.o embe.o touch.o
	arm-linux-gnueabi-ar rc libMyPeri.a led.o button.o buzzer.o fnd.o ColorLed.o Temperature.o acc.o textlcd.o bitmap.o embe.o touch.o
bitmap.o : bitmap.c bitmap.h
	arm-linux-gnueabi-gcc -c bitmap.c -o bitmap.o
textlcd.o : textlcd.c textlcd.h
	arm-linux-gnueabi-gcc -c textlcd.c -o textlcd.o
fnd.o : fnd.c fnd.h
	arm-linux-gnueabi-gcc -c fnd.c -o fnd.o
buzzer.o : buzzer.h buzzer.c
	arm-linux-gnueabi-gcc -c buzzer.c -o buzzer.o
button.o : button.h button.c
	arm-linux-gnueabi-gcc -c button.c -lpthread -o button.o
led.o: led.h led.c
	arm-linux-gnueabi-gcc -c led.c -o led.o
ColorLed.o: ColorLed.h ColorLed.c
	arm-linux-gnueabi-gcc -c ColorLed.c -o ColorLed.o
Temperature.o: Temperature.h Temperature.c
	arm-linux-gnueabi-gcc -c Temperature.c -o Temperature.o
acc.o: acc.h accelMagGyro.c
	arm-linux-gnueabi-gcc -c accelMagGyro.c -o acc.o
embe.o: embe.h embe.c
	arm-linux-gnueabi-gcc -c embe.c -o embe.o
touch.o : touch.h touch.c 
	arm-linux-gnueabi-gcc -c touch.c -o touch.o
clear : 
	rm *.o
	rm libMyPeri.a
