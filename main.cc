#include <string>
#include <vector>
#include <iostream>

#include "historico.hh"
#include "disciplina.hh"

using namespace std;

int main() {
    Historico historico( 10 );
    //Disciplina disciplina;
    //cin >> disciplina;

    Disciplina disciplina( "Programação I", "2018.1", 4, 10 );
    Disciplina disciplina2( "Programação II", "2018.2", 4, 10 );
    Disciplina disciplina3( "Programação III", "2019.1", 4, 10 );
    Disciplina disciplina4( "Calculo I", "2018.1", 4, 10 );
    Disciplina disciplina5( "Calculo II", "2018.2", 4, 10 );
    Disciplina disciplina6( "Matematica", "2017.2", 4, 10 );

    cout << (historico += disciplina) << endl;
    cout << historico << endl;
    cout << (historico += disciplina2) << endl;
    cout << historico << endl;
    cout << (historico += disciplina3) << endl;
    cout << historico << endl;
    cout << (historico += disciplina4) << endl;
    cout << historico << endl;
    cout << (historico += disciplina5) << endl;
    cout << historico << endl;
    cout << (historico += disciplina6) << endl;
    cout << historico << endl;

}