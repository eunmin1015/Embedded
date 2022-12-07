all: libperi.a

libperi.a: button.o led.o fnd.o colorLed.o Temperature.o acc.o
		arm-linux-gnueabi-ar rc libperi.a led.o button.o fnd.o colorLed.o Temperature.o acc.o
button.o: button.h button.c
		arm-linux-gnueabi-gcc -c button.c -o button.o
led.o: led.h led.c
		arm-linux-gnueabi-gcc -c led.c -o led.o
fnd.o: fnd.h fnd.c
		arm-linux-gnueabi-gcc -c fnd.c -o fnd.o
colorLed.o: colorLed.h colorLed.c
		 arm-linux-gnueabi-gcc -c colorLed.c -o colorLed.o
Temperature.o : Temperature.h Temperature.c
	 	arm-linux-gnueabi-gcc -c Temperature.c -o Temperature.o
acc.o : acc.h acc.c
		 arm-linux-gnueabi-gcc -c acc.c -o acc.o                                 
