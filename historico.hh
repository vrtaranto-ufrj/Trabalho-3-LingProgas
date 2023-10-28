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
    Descrição:  Header da classe Historico

*/

#ifndef HISOTRICO_HH
#define HISOTRICO_HH

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

#include "disciplina.hh"

using namespace std;

class Historico {
    friend ostream& operator<<( ostream& os, const Historico& historico );
    public:
        Historico( size_t max_disciplinas );
        ~Historico();

        int operator+=( const Disciplina& disciplina );
        int operator+=( const vector<Disciplina>& disciplinas );
        int operator-=( const Disciplina& disciplina );
        int operator()( const string& nome );
        int operator()( const string& nome, double novaNota );
        double operator>>( double& cra ) const;

        vector<Disciplina>& getDisciplinas();
        
    private:
        vector<Disciplina> disciplinas;
        size_t max_disciplinas;
};

ostream& operator<<( ostream& os, const Historico& historico );


#endif