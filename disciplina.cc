#include "disciplina.hh"

Disciplina::Disciplina(string nome, string periodo, int creditos, double nota) {
    this->nome = nome;
    this->periodo = periodo;
    this->creditos = creditos;
    this->nota = nota;
}

ostream& operator<<( ostream& os, const Disciplina& disciplina ) {
    os << disciplina.nome;
    return os;
}

istream& operator>>( istream& is, Disciplina& disciplina ) {
    cout << "Nome: ";
    is >> disciplina.nome;
    cout << "Periodo: ";
    is >> disciplina.periodo;
    cout << "Creditos: ";
    is >> disciplina.creditos;
    cout << "Nota: ";
    is >> disciplina.nota;
    
    return is;
}

bool operator<( const Disciplina& disciplina1, const Disciplina& disciplina2 ) {
    return disciplina1.periodo < disciplina2.periodo;
}

bool operator==( const Disciplina& disciplina1, const Disciplina& disciplina2 ) {
    return disciplina1.nome == disciplina2.nome;
}