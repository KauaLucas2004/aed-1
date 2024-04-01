#ifndef JOGODAVIDA_HPP
#define JOGODAVIDA_HPP

#include <vector>
#include <fstream>

class JogoDaVida {
public:
    JogoDaVida(const std::string& arquivoEntrada);
    void executar(int geracoes);
private:
    std::vector<std::vector<int>> lerMatriz(std::ifstream& arquivo);
    void exibirMatriz(const std::vector<std::vector<int>>& matriz);
    std::vector<std::vector<int>> proximaGeracao(const std::vector<std::vector<int>>& matriz);
    void salvarMatriz(const std::vector<std::vector<int>>& matriz);
    void gerarRelatorio(const std::vector<std::vector<int>>& matriz, std::ofstream& arquivo);

    std::vector<std::vector<int>> matrizAtual;
    std::ofstream relatorio;
    std::string arquivoSaida;
};

#endif // JOGODAVIDA_HPP
