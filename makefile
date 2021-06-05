CC= gcc
GCCFLAGS= -std=c99 -Wall -pedantic -fsanitize=address
GCCLIBS= -lm

SOURCES_SERVER= server.c
SOURCES_CLIENT= client.c
SOURCES_LEVELS= levels.c

OBJECTS_LEVELS=$(SOURCES_LEVELS:.c=.o)

EXECUTABLE_SERVER= server
EXECUTABLE_CLIENT= client

all: $(OBJECTS_LEVELS) client
	$(CC) $(GCCFLAGS) $(SOURCES_SERVER) $(OBJECTS_LEVELS) -I./include -o $(EXECUTABLE_SERVER) $(GCCLIBS)

%.o: %.c
	$(CC) $(GCCFLAGS) -I./include -c $^ $(GCCLIBS)

client:
	$(CC) $(GCCFLAGS) $(SOURCES_CLIENT) -o $(EXECUTABLE_CLIENT)

clean:
	rm -rf *.o server client

.PHONY: all clean cleanTest test client