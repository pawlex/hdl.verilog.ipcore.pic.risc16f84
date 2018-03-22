SRC=main.c
CC=sdcc-sdcc
FAMILY=pic14
PROC=16f84
OPTS=--no-extended-instructions

all: $(SRC:.c=.hex)

$(SRC:.c=.hex): $(SRC)
	$(CC) --use-non-free -m$(FAMILY) -p$(PROC) $(OPTS) $^
	./intel2readmemh main.hex > rom.mem

clean:
	rm -f $(SRC:.c=.asm) $(SRC:.c=.cod) $(SRC:.c=.hex) $(SRC:.c=.lst) $(SRC:.c=.o)

.PHONY: all clean
