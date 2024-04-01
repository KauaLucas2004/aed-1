#include "jogo_da_vida.hpp"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

JogoDaVida::JogoDaVida(const string& arquivo) : nomeArquivo("datasets/" + arquivo) {}

bool JogoDaVida::carregarMatriz() {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return false;
    }

    int tamanho;
    if (!(arquivo >> tamanho)) {
        cerr << "Erro ao ler o tamanho da matriz do arquivo." << endl;
        arquivo.close();
        return false;
    }

    matriz.resize(tamanho, vector<int>(tamanho));

    for (int i = 0; i < tamanho; ++i) {
        string linha;
        if (!(arquivo >> linha) || linha.size() != tamanho) {
            cerr << "Erro ao ler o arquivo." << endl;
            arquivo.close();
            return false;
        }

        for (int j = 0; j < tamanho; ++j) {
            if (linha[j] != '0' && linha[j] != '1') {
                cerr << "Erro ao ler o arquivo." << endl;
                arquivo.close();
                return false;
            }
            matriz[i][j] = linha[j] - '0';
        }
    }

    arquivo.close();
    return true;
}

void JogoDaVida::exibirEstadoInicial() {
    for (const auto& linha : matriz) {
        for (int celula : linha) {
            cout << celula << " ";
        }
        cout << endl;
    }
}

void JogoDaVida::gerarGeracoes(int numGeracoes) {
    ofstream relatorio("datasets/geracoes.mps");
    if (!relatorio.is_open()) {
        cerr << "Erro ao abrir o arquivo 'datasets/geracoes.mps' para escrita." << endl;
        return;
    }

    relatorio << "Matriz Inicial:" << endl;
    for (const auto& linha : matriz) {
        for (int celula : linha) {
            relatorio << celula;
        }
        relatorio << endl;
    }
    relatorio << endl;

    for (int geracao = 1; geracao <= numGeracoes; ++geracao) {
        vector<vector<int>> novaMatriz(matriz.size(), vector<int>(matriz[0].size()));

        for (int i = 0; i < matriz.size(); ++i) {
            for (int j = 0; j < matriz[0].size(); ++j) {
                int vizinhosVivos = contarVizinhosVivos(i, j);

                if (matriz[i][j] == 1) {
                    if (vizinhosVivos < 2 || vizinhosVivos > 3) {
                        novaMatriz[i][j] = 0; // Célula viva com menos de 2 ou mais de 3 vizinhos vivos morre
                    } else {
                        novaMatriz[i][j] = 1; // Célula viva com 2 ou 3 vizinhos vivos sobrevive
                    }
                } else {
                    if (vizinhosVivos == 3) {
                        novaMatriz[i][j] = 1; // Célula morta com 3 vizinhos vivos se torna viva
                    }
                }
            }
        }

        matriz = novaMatriz;

        relatorio << "Geração " << geracao << ":" << endl;
        for (const auto& linha : matriz) {
            for (int celula : linha) {
                relatorio << celula;
            }
            relatorio << endl;
        }
        relatorio << endl;
    }

    relatorio.close();
}

int JogoDaVida::contarVizinhosVivos(int linha, int coluna) {
    int vizinhosVivos = 0;
    int linhas = matriz.size();
    int colunas = matriz[0].size();

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int novaLinha = linha + i;
            int novaColuna = coluna + j;
            if (i == 0 && j == 0) continue;
            if (novaLinha >= 0 && novaLinha < linhas && novaColuna >= 0 && novaColuna < colunas) {
                if (matriz[novaLinha][novaColuna] == 1) {
                    vizinhosVivos++;
                }
            }
        }
    }

    return vizinhosVivos;
}
