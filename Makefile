all: main.o historico.o disciplina.o
	g++ -Wall -std=c++11 -o main main.o historico.o disciplina.o

disciplina.o: disciplina.cc disciplina.hh
	g++ -Wall -std=c++11 -c disciplina.cc

historico.o: historico.cc historico.hh disciplina.hh
	g++ -Wall -std=c++11 -c historico.cc

main.o: main.cc historico.hh disciplina.hh
	g++ -Wall -std=c++11 -c main.cc

clean:
	rm -f *.o main

run: all
	./main