compile: ossh.o parsing.o other.o log.o
	gcc -Wall main.o parsing.o other.o log.o -o ossh
	echo "OSSH Compiled!"

ossh.o: main.c parsing.h
	gcc -Wall -c main.c

parsing.o: parsing.c parsing.h
	gcc -Wall -c parsing.c

other.o: other.c other.h
	gcc -Wall -c other.c

log.o: log.c log.h
	gcc -Wall -c log.c

install:
	cp ./ossh /usr/bin
	rm ./ossh
	echo "Successfully installed OSSH in /usr/bin!"

cleanall:
	rm -f *.o
	rm -f ossh
	echo "Cleaned up!"

clean:
	rm -f *.o
	echo "Cleaned up!"