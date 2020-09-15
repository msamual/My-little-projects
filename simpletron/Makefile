CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-Wall
SOURCES=srcs/main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=basic
#LIBRARY
INCLUDES=-I./includes/

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBRARY) $(INCLUDES) -o $@

.c.o:
	$(CC) $(CFLAGS) $(LIBRARY) $(INCLUDES) $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(EXECUTABLE)

re: fclean all
