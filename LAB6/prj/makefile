#
#	Makefile dla leniwych by Hodor
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++11

__start__: a.out
	./a.out

a.out: obj/HaszWyszukaj.o obj/main.o obj/Sortowanie.o obj/TablicaAsosjacyjna.o obj/ZapiszStosKolejkaLista.o
	g++ -Wall -pedantic -std=c++11 -o a.out obj/HaszWyszukaj.o obj/main.o obj/Sortowanie.o obj/TablicaAsosjacyjna.o obj/ZapiszStosKolejkaLista.o

obj/HaszWyszukaj.o: src/HaszWyszukaj.cpp inc/Benchmark.hh inc/HaszWyszukaj.hh inc/iKolejka.hh inc/iKontenery.hh inc/iLista.hh inc/iObserwator.hh inc/iObserwowany.hh inc/iStack.hh inc/Kolejka.hh inc/Lista.hh inc/Node.hh inc/NodeL.hh inc/OperacjeNaPlikach.hh inc/Sortowanie.hh inc/Stack.hh inc/Struktury.hh inc/TablicaAsocjacyjna.hh inc/ZapiszStosKolejkaLista.hh 
	g++ ${CPPFLAGS} -o obj/HaszWyszukaj.o src/HaszWyszukaj.cpp

obj/main.o: src/main.cpp inc/Benchmark.hh inc/HaszWyszukaj.hh inc/iKolejka.hh inc/iKontenery.hh inc/iLista.hh inc/iObserwator.hh inc/iObserwowany.hh inc/iStack.hh inc/Kolejka.hh inc/Lista.hh inc/Node.hh inc/NodeL.hh inc/OperacjeNaPlikach.hh inc/Sortowanie.hh inc/Stack.hh inc/Struktury.hh inc/TablicaAsocjacyjna.hh inc/ZapiszStosKolejkaLista.hh inc/Obserwator.hh 
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Sortowanie.o: src/Sortowanie.cpp inc/Benchmark.hh inc/HaszWyszukaj.hh inc/iKolejka.hh inc/iKontenery.hh inc/iLista.hh inc/iObserwator.hh inc/iObserwowany.hh inc/iStack.hh inc/Kolejka.hh inc/Lista.hh inc/Node.hh inc/NodeL.hh inc/OperacjeNaPlikach.hh inc/Sortowanie.hh inc/Stack.hh inc/Struktury.hh inc/TablicaAsocjacyjna.hh inc/ZapiszStosKolejkaLista.hh 
	g++ ${CPPFLAGS} -o obj/Sortowanie.o src/Sortowanie.cpp

obj/TablicaAsosjacyjna.o: src/TablicaAsosjacyjna.cpp inc/Benchmark.hh inc/HaszWyszukaj.hh inc/iKolejka.hh inc/iKontenery.hh inc/iLista.hh inc/iObserwator.hh inc/iObserwowany.hh inc/iStack.hh inc/Kolejka.hh inc/Lista.hh inc/Node.hh inc/NodeL.hh inc/OperacjeNaPlikach.hh inc/Sortowanie.hh inc/Stack.hh inc/Struktury.hh inc/TablicaAsocjacyjna.hh inc/ZapiszStosKolejkaLista.hh 
	g++ ${CPPFLAGS} -o obj/TablicaAsosjacyjna.o src/TablicaAsosjacyjna.cpp

obj/ZapiszStosKolejkaLista.o: src/ZapiszStosKolejkaLista.cpp inc/Benchmark.hh inc/HaszWyszukaj.hh inc/iKolejka.hh inc/iKontenery.hh inc/iLista.hh inc/iObserwator.hh inc/iObserwowany.hh inc/iStack.hh inc/Kolejka.hh inc/Lista.hh inc/Node.hh inc/NodeL.hh inc/OperacjeNaPlikach.hh inc/Sortowanie.hh inc/Stack.hh inc/Struktury.hh inc/TablicaAsocjacyjna.hh inc/ZapiszStosKolejkaLista.hh 
	g++ ${CPPFLAGS} -o obj/ZapiszStosKolejkaLista.o src/ZapiszStosKolejkaLista.cpp

clean:
	rm -f obj/*.o a.out
