##
##  Universidade Federal do Rio de Janeiro
##  Escola Politécnica
##  Departamento de Eletrônica e de Computação
##
##  Aluno:      Vitor Taranto
##  DRE:        121063585
##  Disciplina: EEL670 - Linguagens de Programação
##  Professor:  Miguel Campista
##  Data:       28 de outubro de 2023
##  Período:    2023.2
##  Atividade:  Trabalho 3
##  Descrição:  Makefile
##

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