#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(time(0));
    char jogarNovamente;

    int vitoriasJogador = 0;
    int vitoriasComputador = 0;
    int empates = 0;

    do {

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
        cout << "O total do jogador sera: " << totaljogador << endl;

        totalcomputador = computadorDado1 + computadorDado2;
        cout << "O total do computador sera: " << totalcomputador << endl;

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

        cout << "--------------------" << endl;
        cout << "Vitorias do jogador: " << vitoriasJogador << endl;
        cout << "Vitorias do computador: " << vitoriasComputador << endl;
        cout << "Empates: " << empates << endl;

                cout << "Queres jogar novamente? (s/n): ";
                cin >> jogarNovamente;

    } while (jogarNovamente == 's');

    cout << "Obrigado por jogar!" << endl;

}
