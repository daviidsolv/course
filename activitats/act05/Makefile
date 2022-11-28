CC=gcc
CFLAGS=-c -Wall -O3 -Wstrict-prototypes -Wmissing-prototypes -Wshadow -Wconversion
SOURCES=main.c utils.c

OBJECTS=$(SOURCES:.c=.o)
EXECS=act05

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