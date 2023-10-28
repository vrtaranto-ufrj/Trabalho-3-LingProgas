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
    Descrição:  Implementação da classe Disciplina

*/

#include "disciplina.hh"
#include <cstdlib>


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
    disciplina.creditos = atoi( auxiliar.c_str() );
    cout << "Nota: ";
    getline(is, auxiliar );
    disciplina.nota = atof( auxiliar.c_str() );
    
    return is;
}

bool operator<( const Disciplina& disciplina1, const Disciplina& disciplina2 ) {
    return disciplina1.periodo < disciplina2.periodo;
}

bool operator==( const Disciplina& disciplina1, const Disciplina& disciplina2 ) {
    return disciplina1.nome == disciplina2.nome;
}