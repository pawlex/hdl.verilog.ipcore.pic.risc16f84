SRC=main.c
CC=/opt/sdcc/bin/sdcc
FAMILY=pic14
PROC=16f84
CPU=--use-non-free --no-warn-non-free --stack-size 16 
OPTS=-V -Wl-m -Wa-w1
OPTS+=-llibc.lib -llibsdcc.lib
OBJ=--compile-only


#OPTS+=--opt-code-size --max-allocs-per-node 1 --allow-unsafe-read
#OPTS+=--debug
#OPTS+=--no-pcode-opt
#OPTS+=--more-pedantic 
#OPTS+=--less-pedantic 
#OPTS+=--nogcse --no-optsdcc-in-asm --nolospre --nooverlay --no-extended-instructions --no-pcode-opt --no-peep --nolabelopt --noinvariant --noinduction --noloopreverse --nolospre
#OPTS+=--nogcse --no-optsdcc-in-asm --nolospre --nooverlay --no-extended-instructions --no-pcode-opt --no-peep --noinvariant --noinduction --noloopreverse
#OPTS+=--stack-auto
#OPTS+=--int-long-reent

#OPTS+=-lstdarg -lstring
#OPTS+=--out-fmt-ihx
#OPTS+=--out-fmt-s19
#LINKEROPTS=-Wl-w-r-mout.map

all:
	$(CC) -c constants.c $(CPU) -m$(FAMILY) -p$(PROC)
	$(CC) -c print_functions.c $(CPU) -m$(FAMILY) -p$(PROC)
	$(CC) -S main.c $(CPU) -m$(FAMILY) -p$(PROC) $(OPTS)
	echo 'include "constants.asm"' > include.me
	echo 'include "print_functions.asm"' >> include.me
	echo 'include "main.asm"' >> include.me
	$(CC) -c -Wa-c main.o constants.o print_functions.o $(CPU) -m$(FAMILY) -p$(PROC) $(OPTS)


#none:
#	#$(CC) -c print_functions.c $(OPTS) -m$(FAMILY) -p$(PROC)
#	#$(CC) -o main.c -o constants.c -o print_functions.c $(OPTS) -m$(FAMILY) -p$(PROC)

#all: $(UART:.c=.o) $(SRC:.c=.hex) rom
#all: clean $(SRC:.c=.hex) rom

#_main: $(SRC:.c=.hex)

#_uart: $(UART:.c=.o)

#$(UART:.c=.o): $(UART)
#	$(CC) $(OPTS) -m$(FAMILY) -p$(PROC) -c $^

#$(SRC:.c=.hex): $(SRC)
#	$(CC) $(OPTS) -m$(FAMILY) -p$(PROC) $^ $(UART:.c=.o)

#clean:
#	rm -f $(SRC:.c=.asm) $(SRC:.c=.cod) $(SRC:.c=.hex) $(SRC:.c=.lst) $(SRC:.c=.o) $(SRC:.c=.hex) $(SRC:.c=.rom) $(SRC:.c=.map)
#	rm -f $(UART:.c=.asm) $(UART:.c=.cod) $(UART:.c=.hex) $(UART:.c=.lst) $(UART:.c=.o) $(UART:.c=.hex) $(UART:.c=.rom)
#	rm -f out.vvp dump.vcd
#
#rom:
#	./bin/intel2readmemh $(SRC:.c=.hex) > $(SRC:.c=.rom) || /bin/true
#
#flash: all rom 
#	cd bin; ./hex_mif.sh
#	cd bin; ./asm.sh
#	cd bin; ./prog.sh reconfigure
#
#sim: clean all
#	./run_sim
#
#.PHONY: all clean
