
CFLAGS = -g -Wall -I../UTFT/.  -ffunction-sections -fdata-sections

LDFLAGS = -L/usr/local/lib -Wl,--gc-sections
LDLIBS    = -lgpiod

SRC = $(shell ls ../UTFT/*.c) main.c 

OBJ = $(SRC:.c=.o) 

helloworld: $(OBJ) 
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ)  $(LDFLAGS) $(LDLIBS) -o helloworld

clean:	
	-rm -f $(OBJ) helloworld

