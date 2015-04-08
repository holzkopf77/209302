#
#	Makefile dla leniwych by Hodor
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++11

__start__: a.out
	./a.out

a.out: obj/main.o obj/ZapiszStosKolejkaLista.o
	g++ -Wall -pedantic -std=c++11 -o a.out obj/main.o obj/ZapiszStosKolejkaLista.o

obj/main.o: src/main.cpp inc/Benchmark.hh inc/Kolejka.hh inc/Lista.hh inc/Stack.hh inc/Struktury.hh inc/ZapiszStosKolejkaLista.hh 
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/ZapiszStosKolejkaLista.o: src/ZapiszStosKolejkaLista.cpp inc/Benchmark.hh inc/Kolejka.hh inc/Lista.hh inc/Stack.hh inc/Struktury.hh inc/ZapiszStosKolejkaLista.hh 
	g++ ${CPPFLAGS} -o obj/ZapiszStosKolejkaLista.o src/ZapiszStosKolejkaLista.cpp

clean:
	rm -f obj/*.o a.out
