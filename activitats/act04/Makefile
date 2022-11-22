CC=gcc
CFLAGS=-c -Wall -O3 -Wstrict-prototypes -Wmissing-prototypes -Wshadow -Wconversion
SOURCES=main.c

OBJECTS=$(SOURCES:.c=.o)
EXECS=act04

.PHONY: all
all: $(SOURCES) $(EXECS)
	
$(EXECS): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	/bin/rm -rf *.o
	/bin/rm -rf $(EXECS) 

.PHONY: run
run: $(EXECS)
	 ./$(EXECS)