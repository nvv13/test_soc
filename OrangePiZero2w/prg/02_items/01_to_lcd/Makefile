
CFLAGS = -g -Wall -I../u8g2/csrc/. -I../u8g2/sys/linux-spi/.

LDFLAGS = -L/usr/local/lib
LDLIBS    = -lgpiod

SRC = $(shell ls ../u8g2/csrc/*.c) $(shell ls ../u8g2/sys/linux-spi/*.c) main.c 

OBJ = $(SRC:.c=.o) 

helloworld: $(OBJ) 
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ)  $(LDFLAGS) $(LDLIBS) -o helloworld

clean:	
	-rm -f $(OBJ) helloworld

