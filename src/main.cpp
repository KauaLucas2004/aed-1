#include <iostream>
#include<fstream>
#include "jogo_da_vida.hpp"
using namespace std;

int main() {
    JogoDaVida jogo("input.mps");

    if (!jogo.carregarMatriz()) {
        cerr << "Erro ao carregar o arquivo input.mps." << endl;
        return 1;
    }

    jogo.exibirEstadoInicial();

    int geracoes;
    cout << "Quantas gerações deseja gerar? ";
    cin >> geracoes;

    jogo.gerarGeracoes(geracoes);

    cout << "Processo de gerações finalizado." << endl;

    return 0;
}
