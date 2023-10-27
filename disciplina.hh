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