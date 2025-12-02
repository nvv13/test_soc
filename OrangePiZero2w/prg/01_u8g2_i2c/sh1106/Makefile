
CFLAGS = -g -Wall -I../u8g2/csrc/. -I../u8g2/sys/linux-i2c/.

SRC = $(shell ls ../u8g2/csrc/*.c) $(shell ls ../u8g2/sys/linux-i2c/*.c) main.c 

OBJ = $(SRC:.c=.o) 

helloworld: $(OBJ) 
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -li2c -o helloworld

clean:	
	-rm -f $(OBJ) helloworld

