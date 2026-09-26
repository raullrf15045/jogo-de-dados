#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;


// Guarda o jogo para podermos continuar depois
void guardarJogo(string nome, int nivel, int xp, int moedas,
                 int vitorias, int derrotas, int empates,
                 int recorde) {

    ofstream ficheiro("jogo.txt");

    if (ficheiro.is_open()) {

        ficheiro << nome << endl;
        ficheiro << nivel << endl;
        ficheiro << xp << endl;
        ficheiro << moedas << endl;
        ficheiro << vitorias << endl;
        ficheiro << derrotas << endl;
        ficheiro << empates << endl;
        ficheiro << recorde << endl;

        ficheiro.close();
    }
}


// Vai buscar o jogo que foi guardado
bool carregarJogo(string &nome, int &nivel, int &xp, int &moedas,
                  int &vitorias, int &derrotas, int &empates,
                  int &recorde) {

    ifstream ficheiro("jogo.txt");

    if (!ficheiro.is_open()) {
        return false;
    }

    getline(ficheiro, nome);

    ficheiro >> nivel;
    ficheiro >> xp;
    ficheiro >> moedas;
    ficheiro >> vitorias;
    ficheiro >> derrotas;
    ficheiro >> empates;
    ficheiro >> recorde;

    ficheiro.close();

    return true;
}


// Mostra as vitórias e derrotas
void mostrarPlacar(string nome, int vitorias, int derrotas, int empates) {

    cout << endl;
    cout << "============================" << endl;
    cout << "           PLACAR           " << endl;
    cout << "============================" << endl;

    cout << nome << ": "
         << vitorias << " vitorias" << endl;

    cout << "Computador: "
         << derrotas << " vitorias" << endl;

    cout << "Empates: "
         << empates << endl;
}


// Mostra as informações do jogador
void mostrarPerfil(string nome, int nivel, int xp, int moedas, int recorde) {

    cout << endl;
    cout << "============================" << endl;
    cout << "           PERFIL           " << endl;
    cout << "============================" << endl;

    cout << "Nome: " << nome << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "XP: " << xp << endl;
    cout << "Moedas: " << moedas << endl;
    cout << "Recorde: " << recorde
         << " vitorias numa partida" << endl;
}


// Mostra as partidas que ja jogamos
void mostrarHistorico(string historico[], int quantidade) {

    cout << endl;
    cout << "============================" << endl;
    cout << "          HISTORICO         " << endl;
    cout << "============================" << endl;

    if (quantidade == 0) {

        cout << "Ainda nao jogaste nenhuma partida." << endl;
    }
    else {

        for (int i = 0; i < quantidade; i++) {

            cout << i + 1 << " - "
                 << historico[i] << endl;
        }
    }
}


// Escolhe o nivel de dificuldade
int escolherDificuldade() {

    int dificuldade;

    cout << endl;
    cout << "============================" << endl;
    cout << "        DIFICULDADE         " << endl;
    cout << "============================" << endl;

    cout << "1 - Facil" << endl;
    cout << "2 - Normal" << endl;
    cout << "3 - Dificil" << endl;

    cout << "Escolha: ";
    cin >> dificuldade;

    while (dificuldade < 1 || dificuldade > 3) {

        cout << "Essa opcao nao existe." << endl;
        cout << "Escolhe entre 1 e 3: ";
        cin >> dificuldade;
    }

    return dificuldade;
}


int main() {

    srand(time(0));

    string nome;

    int nivel = 1;
    int xp = 0;
    int moedas = 0;

    int vitorias = 0;
    int derrotas = 0;
    int empates = 0;

    int recorde = 0;

    // Aqui ficam guardadas as ultimas partidas
    string historico[10];
    int quantidadeHistorico = 0;


    // Primeiro tentamos encontrar um jogo antigo
    bool encontrouJogo = carregarJogo(
        nome,
        nivel,
        xp,
        moedas,
        vitorias,
        derrotas,
        empates,
        recorde
    );


    if (encontrouJogo) {

        cout << "Progresso encontrado!" << endl;
        cout << "Bem-vindo de volta, "
             << nome << "!" << endl;
    }
    else {

        cout << "============================" << endl;
        cout << "        JOGO DE DADOS       " << endl;
        cout << "============================" << endl;

        cout << "Qual e o teu nome? ";
        cin >> nome;
    }


    int escolha;


    // Este e o menu principal
    do {

        cout << endl;
        cout << "============================" << endl;
        cout << "       MENU PRINCIPAL       " << endl;
        cout << "============================" << endl;

        cout << "Ola, " << nome << "!" << endl;
        cout << endl;

        cout << "1 - Jogar" << endl;
        cout << "2 - Ver placar" << endl;
        cout << "3 - Ver perfil" << endl;
        cout << "4 - Ver historico" << endl;
        cout << "5 - Guardar jogo" << endl;
        cout << "6 - Sair" << endl;

        cout << endl;
        cout << "Escolha: ";
        cin >> escolha;


        switch (escolha) {


            // JOGAR
            case 1: {

                int dificuldade = escolherDificuldade();

                int rodadas;

                cout << endl;
                cout << "Quantas rodadas queres jogar? ";
                cin >> rodadas;

                while (rodadas <= 0) {

                    cout << "Tens de jogar pelo menos uma rodada."
                         << endl;

                    cout << "Quantas rodadas queres jogar? ";
                    cin >> rodadas;
                }


                int rodada = 1;

                int vitoriasNestaPartida = 0;
                int derrotasNestaPartida = 0;
                int empatesNestaPartida = 0;


                cout << endl;


                // Mostra a dificuldade escolhida
                if (dificuldade == 1) {

                    cout << "Dificuldade: FACIL" << endl;
                    cout << "O computador usa 1 dado." << endl;
                }

                else if (dificuldade == 2) {

                    cout << "Dificuldade: NORMAL" << endl;
                    cout << "Ambos usam 2 dados." << endl;
                }

                else {

                    cout << "Dificuldade: DIFICIL" << endl;
                    cout << "O computador usa 3 dados." << endl;
                }


                // Comeca o jogo
                do {

                    cout << endl;
                    cout << "---------- RODADA "
                         << rodada
                         << " ----------" << endl;


                    // Dados do jogador
                    int dadoJogador1 = rand() % 6 + 1;
                    int dadoJogador2 = rand() % 6 + 1;


                    // Dados do computador
                    int dadoComputador1 = rand() % 6 + 1;
                    int dadoComputador2 = rand() % 6 + 1;
                    int dadoComputador3 = rand() % 6 + 1;


                    int totalJogador;
                    int totalComputador;


                    // O jogador usa sempre dois dados
                    totalJogador =
                        dadoJogador1 + dadoJogador2;


                    // O computador depende da dificuldade
                    if (dificuldade == 1) {

                        totalComputador = dadoComputador1;
                    }

                    else if (dificuldade == 2) {

                        totalComputador =
                            dadoComputador1 +
                            dadoComputador2;
                    }

                    else {

                        totalComputador =
                            dadoComputador1 +
                            dadoComputador2 +
                            dadoComputador3;
                    }


                    // Mostra os dados do jogador
                    cout << endl;

                    cout << nome << ": "
                         << dadoJogador1 << " + "
                         << dadoJogador2 << " = "
                         << totalJogador << endl;


                    // Mostra os dados do computador
                    cout << "Computador: ";


                    if (dificuldade == 1) {

                        cout << dadoComputador1;
                    }

                    else if (dificuldade == 2) {

                        cout << dadoComputador1 << " + "
                             << dadoComputador2;
                    }

                    else {

                        cout << dadoComputador1 << " + "
                             << dadoComputador2 << " + "
                             << dadoComputador3;
                    }


                    cout << " = "
                         << totalComputador << endl;


                    // Compara os resultados
                    if (totalJogador > totalComputador) {

                        cout << endl;
                        cout << nome
                             << " ganhou esta rodada!"
                             << endl;

                        vitoriasNestaPartida++;
                        vitorias++;

                        moedas += 10;
                        xp += 10;
                    }


                    else if (totalJogador < totalComputador) {

                        cout << endl;
                        cout << "O computador ganhou esta rodada!"
                             << endl;

                        derrotasNestaPartida++;
                        derrotas++;

                        xp += 3;
                    }


                    else {

                        cout << endl;
                        cout << "Empate!" << endl;

                        empatesNestaPartida++;
                        empates++;

                        xp += 5;
                    }


                    rodada++;


                    // Verifica se o jogador subiu de nivel
                    if (xp >= nivel * 100) {

                        xp = xp - nivel * 100;

                        nivel++;

                        cout << endl;
                        cout << "============================" << endl;
                        cout << "     SUBISTE DE NIVEL!      " << endl;
                        cout << "============================" << endl;

                        cout << "Agora estas no nivel "
                             << nivel << "!" << endl;
                    }


                } while (rodada <= rodadas);


                // Resultado da partida
                cout << endl;
                cout << "============================" << endl;
                cout << "       RESULTADO FINAL      " << endl;
                cout << "============================" << endl;

                cout << nome << ": "
                     << vitoriasNestaPartida
                     << " vitorias" << endl;

                cout << "Computador: "
                     << derrotasNestaPartida
                     << " vitorias" << endl;

                cout << "Empates: "
                     << empatesNestaPartida << endl;


                cout << endl;


                // Decide quem ganhou a partida
                if (vitoriasNestaPartida > derrotasNestaPartida) {

                    cout << "Parabens, " << nome
                         << "! Ganhaste a partida!"
                         << endl;

                    moedas += 20;
                }

                else if (vitoriasNestaPartida < derrotasNestaPartida) {

                    cout << "O computador ganhou a partida."
                         << endl;
                }

                else {

                    cout << "A partida terminou empatada!"
                         << endl;
                }


                // Verifica se temos um novo recorde
                if (vitoriasNestaPartida > recorde) {

                    recorde = vitoriasNestaPartida;

                    cout << endl;
                    cout << "Novo recorde!" << endl;
                }


                // Guarda o resultado no historico
                if (quantidadeHistorico < 10) {

                    if (vitoriasNestaPartida > derrotasNestaPartida) {

                        historico[quantidadeHistorico] =
                            "Ganhaste a partida!";
                    }

                    else if (vitoriasNestaPartida <
                             derrotasNestaPartida) {

                        historico[quantidadeHistorico] =
                            "Perdeste a partida.";
                    }

                    else {

                        historico[quantidadeHistorico] =
                            "Empataste a partida.";
                    }

                    quantidadeHistorico++;
                }


                cout << endl;
                cout << "Moedas: " << moedas << endl;
                cout << "XP: " << xp << endl;
                cout << "Nivel: " << nivel << endl;

                break;
            }


            // VER PLACAR
            case 2:

                mostrarPlacar(
                    nome,
                    vitorias,
                    derrotas,
                    empates
                );

                break;


            // VER PERFIL
            case 3:

                mostrarPerfil(
                    nome,
                    nivel,
                    xp,
                    moedas,
                    recorde
                );

                break;


            // VER HISTORICO
            case 4:

                mostrarHistorico(
                    historico,
                    quantidadeHistorico
                );

                break;


            // GUARDAR JOGO
            case 5:

                guardarJogo(
                    nome,
                    nivel,
                    xp,
                    moedas,
                    vitorias,
                    derrotas,
                    empates,
                    recorde
                );

                cout << endl;
                cout << "Jogo guardado!" << endl;

                break;


            // SAIR
            case 6:

                guardarJogo(
                    nome,
                    nivel,
                    xp,
                    moedas,
                    vitorias,
                    derrotas,
                    empates,
                    recorde
                );

                cout << endl;
                cout << "Progresso guardado." << endl;

                cout << "Obrigado por jogar, "
                     << nome << "!" << endl;

                break;


            default:

                cout << endl;
                cout << "Essa opcao nao existe!" << endl;
        }


    } while (escolha != 6);


    return 0;
}
