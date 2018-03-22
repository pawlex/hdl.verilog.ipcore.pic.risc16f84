SRC=empty_main.c

#CC=sdcc
#CC=/usr/local/sdcc/bin/sdcc
CC=sdcc-sdcc
FAMILY=pic14
PROC=16f84

all: $(SRC:.c=.hex)

$(SRC:.c=.hex): $(SRC)
	$(CC) --use-non-free -m$(FAMILY) -p$(PROC) $^

clean:
	rm -f $(SRC:.c=.asm) $(SRC:.c=.cod) $(SRC:.c=.hex) $(SRC:.c=.lst) $(SRC:.c=.o)

.PHONY: all clean
