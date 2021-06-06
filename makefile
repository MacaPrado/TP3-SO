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

cleanTest:
	rm -rf output.cppOut report.tasks results.valgrind

test: clean 
	./pvs.sh; valgrind --leak-check=full -v ./server 2>> results.valgrind; valgrind --leak-check=full -v ./client 2>> results.valgrind; cppcheck --quiet --enable=all --force --inconclusive server.c levels.c client.c 2>> output.cppOut

.PHONY: all clean cleanTest test client
