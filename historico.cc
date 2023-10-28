#include "historico.hh"

#include <fstream>

Historico::Historico( size_t max_disciplinas ) {
    this->max_disciplinas = max_disciplinas;
    ifstream arquivo( "historico.csv" );
    if (arquivo.is_open()) {
        string nome;
        string periodo;
        int creditos;
        double nota;
        while ( getline( arquivo, nome, ',' ) ) {
            getline( arquivo, periodo, ',' );
            arquivo >> creditos;
            arquivo.ignore();
            arquivo >> nota;
            arquivo.ignore();
            *this += Disciplina( nome, periodo, creditos, nota );
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir arquivo" << endl;
    }
}

Historico::~Historico() {
    ofstream arquivo( "historico.csv" );
    if (arquivo.is_open()) {
        for ( size_t i = 0; i < disciplinas.size(); i++ ) {
            arquivo << disciplinas[i].nome << ',' << disciplinas[i].periodo << ',' << disciplinas[i].creditos << ',' << disciplinas[i].nota << endl;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir arquivo" << endl;
    }
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

int Historico::operator+=( const vector<Disciplina>& disciplinasNovas ) {
    for ( auto& disciplina : disciplinasNovas ) {
        *this += disciplina;
    }
    return disciplinas.size() - 1;

}

int Historico::operator-=( const Disciplina& disciplina ) {
    for ( size_t i = 0; i < disciplinas.size(); i++ ) {
        if ( disciplina == disciplinas[i] ) {
            disciplinas.erase( disciplinas.begin() + i );
            return i;
        }
    }
    cout << "Disciplina nao encontrada" << endl;
    return -1;
}

int Historico::operator()( const string& nome ) {
    for ( size_t i = 0; i < disciplinas.size(); i++ ) {
        //cout << disciplinas[i].nome << " : " << nome << endl;
        if ( disciplinas[i].nome == nome ) {
            return i;
        }
    }
    cout << "Disciplina nao encontrada" << endl;
    return -1;
}

int Historico::operator()( const string& nome, double novaNota ) {
    for ( size_t i = 0; i < disciplinas.size(); i++ ) {
        if ( disciplinas[i].nome == nome ) {
            disciplinas[i].nota = novaNota;
            return i;
        }
    }
    cout << "Disciplina nao encontrada" << endl;
    return -1;
}

double Historico::operator>>(double& cra) const {
    double somaNotas = 0;
    double somaCreditos = 0;
    for (const auto& disciplina : disciplinas) {
        somaNotas += disciplina.nota * disciplina.creditos;
        somaCreditos += disciplina.creditos;
    }
    if (somaCreditos == 0) {
        cra = 0;
    } else {
        cra = somaNotas / somaCreditos;
    }
    return cra;
}

vector<Disciplina>& Historico::getDisciplinas() {
    return disciplinas;
}