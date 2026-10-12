
CFLAGS = -g -Wall -I../UTFT/. 

LDFLAGS = -L/usr/local/lib
LDLIBS    = -lgpiod

SRC = $(shell ls ../UTFT/*.c) main.c 

OBJ = $(SRC:.c=.o) 

helloworld: $(OBJ) 
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ)  $(LDFLAGS) $(LDLIBS) -o helloworld

clean:	
	-rm -f $(OBJ) helloworld

