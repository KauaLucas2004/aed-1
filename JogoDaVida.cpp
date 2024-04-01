#include "JogoDaVida.hpp"
#include <iostream>
using namespace std;

JogoDaVida::JogoDaVida(const string &arquivoEntrada) {
  ifstream arquivo(arquivoEntrada);
  if (!arquivo.is_open() || arquivo.peek() == ifstream::traits_type::eof()) {
    cerr << "Erro ao abrir o arquivo de entrada ou arquivo vazio." << endl;
    exit(1);
  }

  arquivoSaida = arquivoEntrada;
  matrizAtual = lerMatriz(arquivo);
  salvarMatriz(matrizAtual); // Salvar a matriz de entrada no arquivo
}

void JogoDaVida::executar(int geracoes) {
  for (int i = 0; i < geracoes; ++i) {
    matrizAtual = proximaGeracao(matrizAtual);
    salvarMatriz(matrizAtual); // Salvar cada nova geração no arquivo
  }

  cout << "Histórico de evolução salvo no arquivo " << arquivoSaida << endl;
}

vector<vector<int>> JogoDaVida::lerMatriz(ifstream &arquivo) {
  int tamanho;
  arquivo >> tamanho;
  if (tamanho <= 0) {
    cerr << "Formato de arquivo inválido." << endl;
    exit(1);
  }

  vector<vector<int>> matriz(tamanho, vector<int>(tamanho, 0));

  for (int i = 0; i < tamanho; ++i) {
    string linha;
    arquivo >> linha;
    if (linha.size() != tamanho) {
      cerr << "Formato de arquivo inválido." << endl;
      exit(1);
    }
    for (int j = 0; j < tamanho; ++j) {
      if (linha[j] != '0' && linha[j] != '1') {
        cerr << "Valores inválidos na matriz." << endl;
        exit(1);
      }
      matriz[i][j] = linha[j] - '0';
    }
  }

  return matriz;
}

void JogoDaVida::exibirMatriz(const vector<vector<int>> &matriz) {
  for (const auto &linha : matriz) {
    for (int valor : linha) {
      cout << valor << " ";
    }
    cout << endl;
  }
}

vector<vector<int>>
JogoDaVida::proximaGeracao(const vector<vector<int>> &matriz) {
  int linhas = matriz.size();
  int colunas = matriz[0].size();
  vector<vector<int>> proxima(linhas, vector<int>(colunas, 0));

  for (int i = 0; i < linhas; ++i) {
    for (int j = 0; j < colunas; ++j) {
      int vizinhosVivos = 0;

      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          int ni = i + dx;
          int nj = j + dy;
          if (ni >= 0 && ni < linhas && nj >= 0 && nj < colunas &&
              !(dx == 0 && dy == 0) && matriz[ni][nj] == 1) {
            vizinhosVivos++;
          }
        }
      }

      if (matriz[i][j] == 1) {
        if (vizinhosVivos < 2 || vizinhosVivos > 3) {
          proxima[i][j] = 0;
        } else {
          proxima[i][j] = 1;
        }
      } else {
        if (vizinhosVivos == 3) {
          proxima[i][j] = 1;
        }
      }
    }
  }

  return proxima;
}

void JogoDaVida::salvarMatriz(const vector<vector<int>> &matriz) {
  ofstream arquivo(arquivoSaida, ios::app);
  if (!arquivo.is_open()) {
    cerr << "Erro ao abrir o arquivo de saída." << endl;
    exit(1);
  }

  for (const auto &linha : matriz) {
    for (int valor : linha) {
      arquivo << valor;
    }
    arquivo << endl;
  }

  arquivo << endl; // Adicionar uma linha em branco após cada matriz
  arquivo.close();
}
