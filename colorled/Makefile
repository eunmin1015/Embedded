all: libperi.a
libperi.a: colorled.o button.o led.o textlcd.o led.o buzzer.o
	arm-linux-gnueabi-ar rc libperi.a colorled.o led.o button.o buzzer.o textlcd.o
colorled.o: colorled.c colorled.h
	arm-linux-gnueabi-gcc -c colorled.c -o colorled.o
button.o : button.h button.c
	arm-linux-gnueabi-gcc -c button.c -o button.o
led.o : led.h led.c
	arm-linux-gnueabi-gcc -c led.c -o led.o
buzzer.o : buzzer.h buzzer.c
	arm-linux-gnueabi-gcc -c buzzer.c -o buzzer.o
textlcd.o : textlcd.h textlcd.c
	arm-linux-gnueabi-gcc -c textlcd.c -o textlcd.o
