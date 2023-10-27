#ifndef HISOTRICO_HH
#define HISOTRICO_HH

#include <vector>
#include <string>
#include <iostream>

#include "disciplina.hh"

using namespace std;

class Historico {
    friend ostream& operator<<( ostream& os, const Historico& historico );
    public:
        Historico( size_t max_disciplinas );

        int operator+=( const Disciplina& disciplina );
        
    private:
        vector<Disciplina> disciplinas;
        size_t max_disciplinas;
};

ostream& operator<<( ostream& os, const Historico& historico );


#endif