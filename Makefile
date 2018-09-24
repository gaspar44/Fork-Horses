GCC=gcc
GCCFLAGS= -g -std=c99 #-Wall -Werror

%.o: %.c
	$(GCC) -c $(GCCFLAGS) $<

all: main.o master.o horse.o
	$(GCC) -o main main.o master.o horse.o
	
clean:
	rm *.o main