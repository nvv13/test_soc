CC ?= cc

SRC = *.c

all: main

main: $(SRC)
	$(CC) $(SRC) -o test-spi-c.bin

clean:
	rm -f *.ihx *.hex *.bin a.out

fmt:
	clang-format --style=GNU --verbose -i *.c *.h


