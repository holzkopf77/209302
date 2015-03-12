#
#	Makefile dla leniwych by Hodor
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++11

__start__: a.out
	./a.out

a.out: obj/Benchmark.o obj/main.o
	g++ -Wall -pedantic -std=c++11 -o a.out obj/Benchmark.o obj/main.o

obj/Benchmark.o: src/Benchmark.cpp inc/Benchmark.hh 
	g++ ${CPPFLAGS} -o obj/Benchmark.o src/Benchmark.cpp

obj/main.o: src/main.cpp inc/Benchmark.hh 
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o a.out
