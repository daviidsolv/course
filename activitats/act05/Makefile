CC=gcc
CFLAGS=-c -Wall -O3 -Wstrict-prototypes -Wmissing-prototypes -Wshadow -Wconversion
SOURCES=main.c utils.c

OBJECTS=$(SOURCES:.c=.o)
EXECS=act05

.PHONY: all
all: $(SOURCES) $(EXECS)
	
$(EXECS): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	$(CC) $(CFLAGS) player.c -o player.o
	$(CC) utils.o player.o -o player
	$(RM) *.o

.c.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	/bin/rm -rf *.o
	/bin/rm -rf $(EXECS)
	rm -rf player 

.PHONY: run
run: $(EXECS)
	 ./$(EXECS)