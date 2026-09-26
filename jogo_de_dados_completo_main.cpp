#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(time(0));

    char jogarNovamente;
    int escolha;

    int vitoriasJogador = 0;
    int vitoriasComputador = 0;
    int empates = 0;

    do {

        cout << "========================" << endl;
        cout << "       JOGO DE DADOS    " << endl;
        cout << "========================" << endl;

        cout << "1 - Jogar" << endl;
        cout << "2 - Ver placar" << endl;
        cout << "3 - Sair" << endl;

        cout << "Escolha: ";
        cin >> escolha;

        switch (escolha) {

            case 1: {

                int jogadorDado1;
                int jogadorDado2;
                int computadorDado1;
                int computadorDado2;
                int totaljogador;
                int totalcomputador;

                jogadorDado1 = rand() % 6 + 1;
                cout << "Dado 1 do jogador: " << jogadorDado1 << endl;

                jogadorDado2 = rand() % 6 + 1;
                cout << "Dado 2 do jogador: " << jogadorDado2 << endl;

                computadorDado1 = rand() % 6 + 1;
                cout << "Dado 1 do computador: " << computadorDado1 << endl;

                computadorDado2 = rand() % 6 + 1;
                cout << "Dado 2 do computador: " << computadorDado2 << endl;

                totaljogador = jogadorDado1 + jogadorDado2;
                cout << "Total do jogador: " << totaljogador << endl;

                totalcomputador = computadorDado1 + computadorDado2;
                cout << "Total do computador: " << totalcomputador << endl;

                if (totaljogador > totalcomputador) {
                    cout << "O jogador ganhou!" << endl;
                    vitoriasJogador++;
                }
                else if (totaljogador < totalcomputador) {
                    cout << "O computador ganhou!" << endl;
                    vitoriasComputador++;
                }
                else {
                    cout << "Empate!" << endl;
                    empates++;
                }

                cout << "Queres jogar novamente? (s/n): ";
                cin >> jogarNovamente;

                break;
            }

            case 2:

                cout << "========================" << endl;
                cout << "          PLACAR        " << endl;
                cout << "========================" << endl;

                cout << "Vitorias do jogador: " << vitoriasJogador << endl;
                cout << "Vitorias do computador: " << vitoriasComputador << endl;
                cout << "Empates: " << empates << endl;

                break;

            case 3:

                cout << "Obrigado por jogar!" << endl;

                break;

            default:

                cout << "Opcao invalida!" << endl;
        }

    } while (escolha != 3);

    return 0;
}
