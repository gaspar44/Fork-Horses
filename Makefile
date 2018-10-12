GCC=gcc
GCCFLAGS= -g -std=c99 #-Wall -Werror

%.o: %.c
	$(GCC) -c $(GCCFLAGS) $<

all: main.o master.o horse.o puntuacion.o
	$(GCC) -o main main.o master.o horse.o puntuacion.o
	
clean:
	rm *.o main puntuacion.txt