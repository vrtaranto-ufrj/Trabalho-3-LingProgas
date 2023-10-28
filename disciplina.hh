/*
    Universidade Federal do Rio de Janeiro
    Escola Politécnica
    Departamento de Eletrônica e de Computação

    Aluno:      Vitor Taranto
    DRE:        121063585
    Disciplina: EEL670 - Linguagens de Programação
    Professor:  Miguel Campista
    Data:       28 de outubro de 2023
    Período:    2023.2
    Atividade:  Trabalho 3
    Descrição:  Header da classe Disciplina

*/

#ifndef DISCIPLINA_HH
#define DISCIPLINA_HH

#include <string>
#include <iostream>

using namespace std;

struct Disciplina {
    Disciplina() {}
    Disciplina(string nome, string periodo, int creditos, double nota);
    string nome;
    string periodo;
    int creditos;
    double nota;
};

ostream& operator<<( ostream& os, const Disciplina& disciplina );
istream& operator>>( istream& is, Disciplina& disciplina );
bool operator<( const Disciplina& disciplina1, const Disciplina& disciplina2 );
bool operator==( const Disciplina& disciplina1, const Disciplina& disciplina2 );

#endif