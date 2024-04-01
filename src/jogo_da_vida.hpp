#ifndef JOGO_DA_VIDA_HPP
#define JOGO_DA_VIDA_HPP

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class JogoDaVida {
public:
    explicit JogoDaVida(const std::string& arquivo);

    bool carregarMatriz();
    void exibirEstadoInicial();
    void gerarGeracoes(int numGeracoes);

private:
    std::vector<std::vector<int>> matriz;
    std::string nomeArquivo;

    int contarVizinhosVivos(int linha, int coluna);
};

#endif 
