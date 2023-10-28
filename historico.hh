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