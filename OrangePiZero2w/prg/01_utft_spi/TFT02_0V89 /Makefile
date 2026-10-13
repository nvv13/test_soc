
CFLAGS = -g -Wall -I../UTFT/. -I../UTFT/jpeg/. -ffunction-sections -fdata-sections

LDFLAGS = -L/usr/local/lib -Wl,--gc-sections
LDLIBS    = -lgpiod -lm 

SRC = $(shell ls ../UTFT/*.c) $(shell ls ../UTFT/jpeg/*.c) main.c 

OBJ = $(SRC:.c=.o) 

helloworld: $(OBJ) 
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ)  $(LDFLAGS) $(LDLIBS) -o helloworld

clean:	
	-rm -f $(OBJ) helloworld

