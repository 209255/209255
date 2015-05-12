#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic 


Struktury: obj/StrukturyBenchmark.o obj/Czasomierz.o obj/Wyniki.o obj/TablicaHash.o obj/TablicaAso.o obj/Main.o
	g++ -Wall -pedantic -o Struktury obj/*.o

obj:
	mkdir obj

obj/Main.o: src/Main.cpp inc/*.hh
	g++ ${CPPFLAGS} -o obj/Main.o src/Main.cpp
obj/StrukturyBenchmark.o: src/StrukturyBenchmark.cpp inc/StrukturyBenchmark.hh
	g++ ${CPPFLAGS} -o obj/StrukturyBenchmark.o src/StrukturyBenchmark.cpp
obj/Wyniki.o: src/Wyniki.cpp inc/Wyniki.hh
	g++ ${CPPFLAGS} -o obj/Wyniki.o src/Wyniki.cpp
obj/Czasomierz.o: src/Czasomierz.cpp inc/Czasomierz.hh
	g++ ${CPPFLAGS} -o obj/Czasomierz.o src/Czasomierz.cpp
obj/TablicaHash.o: src/TablicaHash.cpp inc/TablicaHash.hh
	g++ ${CPPFLAGS} -o obj/TablicaHash.o src/TablicaHash.cpp
obj/TablicaAso.o: src/TablicaAso.cpp inc/TablicaAso.hh
	g++ ${CPPFLAGS} -o obj/TablicaAso.o src/TablicaAso.cpp

clean:
	rm -f obj/*.o Struktury


