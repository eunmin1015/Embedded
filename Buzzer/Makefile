all : buzzer.h buzzer.c
	arm-linux-gnueabi-gcc -c buzzer.c -o buzzer.o
	arm-linux-gnueabi-ar rc libmyperi.a buzzer.o


all : libperi.a
libperi.a : button.o led.o buzzer.o
	arm-linux-gnueabi-ar rc libperi.a led.o button.o buzzer.o
button.o : button.h button.c
	arm-linux-gnueabi-gcc -c button.c -o button.o
led.o : led.h led.c
	arm-linux-gnueabi-gcc -c led.c -o led.o
buzzer.o : buzzer.h buzzer.c
	arm-linux-gnueabi-gcc -c buzzer.c -o buzzer.o

