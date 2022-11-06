compile: ossh.o parsing.o
	gcc -Wall main.o parsing.o -o ossh
	echo "OSSH Compiled!"

ossh.o: main.c parsing.h
	gcc -Wall -c main.c

parsing.o: parsing.c parsing.h
	gcc -Wall -c parsing.c

install:
	cp ./ossh /usr/bin
	rm ./ossh
	echo "Successfully installed OSSH in /usr/bin!"

test:
	echo "Testing RMSF..."
	./test.sh

clean:
	rm -f *.o
	rm -f ossh
	echo "Cleaned up!"