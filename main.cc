#include <string>
#include <vector>
#include <iostream>

#include "historico.hh"
#include "disciplina.hh"

using namespace std;

int main() {
    Historico historico( 10 );
    Disciplina disciplina;
    cin >> disciplina;
    cout << (historico += disciplina);

    cout << historico << endl;
}