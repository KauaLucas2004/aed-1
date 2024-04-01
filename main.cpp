#include "JogoDaVida.hpp"
#include <iostream>
using namespace std;

int main() {
  JogoDaVida jogo("geracoes.mps");

  int geracoes;
  cout << "Quantas gerações deseja gerar? ";
  cin >> geracoes;

  jogo.executar(geracoes);

  return 0;
}
