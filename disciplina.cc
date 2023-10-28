#include "disciplina.hh"
#include <limits>

Disciplina::Disciplina(string nome, string periodo, int creditos, double nota) {
    this->nome = nome;
    this->periodo = periodo;
    this->creditos = creditos;
    this->nota = nota;
}

ostream& operator<<( ostream& os, const Disciplina& disciplina ) {
    os << disciplina.nome << " - " << disciplina.periodo << " - " << disciplina.creditos << " - " << disciplina.nota;
    return os;
}

istream& operator>>( istream& is, Disciplina& disciplina ) {
    string auxiliar;
    cout << "Nome: ";
    getline( is, disciplina.nome );
    cout << "Periodo: ";
    getline( is, disciplina.periodo );
    cout << "Creditos: ";
    getline( is, auxiliar );
    disciplina.creditos = stoi( auxiliar );
    cout << "Nota: ";
    getline(is, auxiliar );
    disciplina.nota = stod( auxiliar );
    
    return is;
}

bool operator<( const Disciplina& disciplina1, const Disciplina& disciplina2 ) {
    return disciplina1.periodo < disciplina2.periodo;
}

bool operator==( const Disciplina& disciplina1, const Disciplina& disciplina2 ) {
    return disciplina1.nome == disciplina2.nome;
}