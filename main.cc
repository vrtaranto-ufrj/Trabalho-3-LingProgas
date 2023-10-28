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
    Descrição:  Programa que simula um histórico de disciplinas cursadas
                por um aluno, com o cálculo do CRA.

*/

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

#include "historico.hh"
#include "disciplina.hh"

using namespace std;

int main() {
    int opcao = -1;
    Historico historico( 40 );
    string nome;
    int posicao;
    double nota;

    while (opcao != 0) {
        cout << "Escolha uma opção:" << endl;
        cout << "1 - Impressão do catálogo inteiro de disciplinas cursadas" << endl;
        cout << "2 - Inicialização e inserção dos dados referentes a uma disciplina ao historico" << endl;
        cout << "3 - Remoção de uma disciplina do histórico" << endl;
        cout << "4 - Busca de uma disciplina no histórico" << endl;
        cout << "5 - Edição da nota de uma disciplina no histórico" << endl;
        cout << "6 - Cálculo do CRA" << endl;
        cout << "0 - Sair" << endl;
        getline(cin, nome);
        opcao = atoi(nome.c_str());

        switch (opcao) {
            case 1: {
                cout << historico << endl;
                break;
            }
            case 2: {
                Disciplina disciplina;
                cin >> disciplina;
                historico += disciplina;
                break;
            }
            case 3: {
                cout << "Digite o nome da disciplina: ";
                getline( cin, nome );
                posicao = historico( nome );
                if (posicao != -1) {
                    historico -= historico.getDisciplinas()[posicao];
                }
                
                break;
            }
            case 4: {
                cout << "Digite o nome da disciplina: ";
                getline( cin, nome );
                posicao = historico( nome );
                if (posicao != -1) {
                    cout << historico.getDisciplinas()[posicao] << endl;
                }
                break;
            }
            case 5: {
                string auxiliar;
                cout << "Digite o nome da disciplina: ";
                getline( cin, nome );
                cout << "Digite a nova nota da disciplina: ";
                getline( cin, auxiliar );
                nota = atof( auxiliar.c_str() );
                historico( nome, nota );
                break;
            }
            case 6: {
                historico >> nota;
                cout << "CRA: " << nota << endl;
                break;
            }
            case 0: {
                cout << "Saindo..." << endl;
                break;
            }
            default: {
                cout << "Opção inválida" << endl;
                break;
            }
        }
    }

    return 0;
}