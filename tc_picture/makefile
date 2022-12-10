all: libperi.a
libperi.a : touch.o
	 arm-linux-gnueabi-ar rc libperi.a touch.o
touch.o : touch.h touch.c
	arm-linux-gnueabi-gcc -c touch.c -o touch.o

