#include "historico.hh"

Historico::Historico( size_t max_disciplinas ) {
    this->max_disciplinas = max_disciplinas;
}

ostream& operator<<( ostream& os, const Historico& historico ) {
    for ( size_t i = 0; i < historico.disciplinas.size(); i++ ) {
        
        os << historico.disciplinas[i] << endl;
    }
    return os;
}

int Historico::operator+=( const Disciplina& disciplina ) {
    if ( disciplinas.size() >= max_disciplinas ) {
        cout << "Numero maximo de disciplinas atingido" << endl;
        return -1;
    }

    if ( disciplinas.size() == 0 ) {
        disciplinas.push_back( disciplina );
        return 0;
    }

    for ( size_t i = 0; i < disciplinas.size(); i++ ) {
        if ( disciplina == disciplinas[i] ) {
            cout << "Disciplina ja cursada" << endl;
            return -1;
        }
        if ( disciplina < disciplinas[i] ) {
            disciplinas.insert( disciplinas.begin() + i, disciplina );
            return i;
        }

        if ( disciplina.periodo == disciplinas[i].periodo ) {
            if ( disciplina.nome < disciplinas[i].nome ) {
                disciplinas.insert( disciplinas.begin() + i, disciplina );
                return i;
            }
        }
        
    }
    disciplinas.push_back( disciplina );
    return disciplinas.size() - 1;
}
