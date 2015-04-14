#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++11


Struktury: obj/BenchmarkInterfejs.o obj/TablicaHash.o obj/TablicaAso.o  obj/Main.o
	g++ -Wall -pedantic -o Struktury obj/*.o

obj/Main.o: src/Main.cpp inc/*.hh
	g++ ${CPPFLAGS} -o obj/Main.o src/Main.cpp

obj/BenchmarkInterfejs.o : src/BenchmarkInterfejs.cpp inc/BenchmarkInterfejs.hh
	g++ ${CPPFLAGS} -o obj/BenchmarkInterfejs.o src/BenchmarkInterfejs.cpp
obj/TablicaHash.o: src/TablicaHash.cpp inc/TablicaHash.hh
	g++ ${CPPFLAGS} -o obj/TablicaHash.o src/TablicaHash.cpp
obj/TablicaAso.o: src/TablicaAso.cpp inc/TablicaAso.hh
	g++ ${CPPFLAGS} -o obj/TablicaAso.o src/TablicaAso.cpp

clean:
	rm -f obj/*.o Struktury


