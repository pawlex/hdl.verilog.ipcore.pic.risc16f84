SRC=main.c
CC=gcc
CFLAGS=-I -WAll
OPTS=-fno-stack-protector
#all: $(SRC:.c=.hex)

all: $(SRC) 
	$(CC) -o main  $^ $(CFLAGS) $(OPTS)

#clean:
#	rm main

.PHONY: all


#CC=gcc
#CFLAGS=-I.
#DEPS = hellomake.h
#OBJ = hellomake.o hellofunc.o
#
#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)
#
#hellomake: $(OBJ)
#	$(CC) -o $@ $^ $(CFLAGS)
#
