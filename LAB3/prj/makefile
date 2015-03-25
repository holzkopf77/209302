#
#	Makefile dla leniwych by Hodor
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++11

__start__: a.out
	./a.out

a.out: obj/main.o
	g++ -Wall -std=c++11 -pedantic -o a.out obj/main.o

obj/main.o: src/main.cpp inc/Benchmark.hh inc/Kolejka.hh inc/Lista.hh inc/Stack.hh 
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o a.out
