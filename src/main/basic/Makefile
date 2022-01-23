SRC=main.c
CC=/opt/sdcc/bin/sdcc
FAMILY=pic14
PROC=16f84
CPU=--use-non-free --no-warn-non-free --stack-size 16 -V
OPTS=-Wl-m # generate map file

all: clean $(SRC:.c=.hex) rom

$(SRC:.c=.hex): $(SRC)
	$(CC) $(OPTS) -m$(FAMILY) -p$(PROC) $(CPU) $^ $(UART:.c=.o)

clean:
	rm -f $(SRC:.c=.asm) $(SRC:.c=.cod) $(SRC:.c=.hex) $(SRC:.c=.lst) $(SRC:.c=.o) $(SRC:.c=.hex) $(SRC:.c=.rom) $(SRC:.c=.map) $(SRC:.c=.adb) $(SRC:.c=.p)
	rm -f out.vvp dump.vcd

rom:
	./bin/intel2readmemh $(SRC:.c=.hex) > $(SRC:.c=.rom) || /bin/true

flash: all rom 
	cd bin; ./hex_mif.sh
	cd bin; ./asm.sh
	cd bin; ./prog.sh reconfigure

sim: clean all
	./run_sim

.PHONY: all clean
