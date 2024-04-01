# TRABALHO 0 AEDS - JOGO DA VIDA

## INTRODUÇÃO

O trabalho foi proposto na disciplina de Algoritmos e Estruturas de Dados pelo professor Michel Pires da Silva do Centro Federal de Educação Tecnológica de Minas Gerais.
O trabalho consiste no desenvolvimento de um Jogo da Vida, um autômato celular que evolui de acordo com regras simples, mas gera padrões complexos, o qual é representado por uma matriz 2D de células, cada uma
podendo estar viva (1) ou morta (0). O objetivo deste trabalho é revisar os conceitos de manipulação de matrizes, controle
de fluxo e lógica de jogo.

## REGRAS

O trabalho possui 6 comandos:

1. Criar uma matriz N x N para representar o tabuleiro do Jogo da Vida.
2. Inicializar o tabuleiro com células vivas (1) e mortas (0) aleatoriamente.
3. Implementar uma função para exibir o estado atual do tabuleiro.
4. Implementar uma função para produzir um relatório de execução, guardando o
histórico da evolução do jogo em arquivo.
5. Implementar uma função para calcular a próxima geração do Jogo da Vida com base
nas seguintes regras:
    - Uma célula viva com menos de dois vizinhos vivos morre (solidão).
    - Uma célula viva com mais de três vizinhos vivos morre (superpopulação).
    - Uma célula viva com dois ou três vizinhos vivos sobrevive.
    - Uma célula morta com exatamente três vizinhos vivos se torna viva (reprodução).
6. Executar várias gerações do jogo e mostre o estado do tabuleiro após cada geração.
   


Além disso, deve-se considerar como parte da tarefa as seguintes instruções: 

– Ler a matriz de entrada de um arquivo, considerando um tamanho mínimo de
5x5.

– Considere uma fração de 2 para 1 para compor os valores 0s e 1s, sendo o
número de 1s em menor quantidade para produzir um melhor espalhamento.

– A cada interação, faça as avaliações utilizando a matriz atual e produza os
resultados da avaliação em uma nova matriz. Feito isso, salve a matriz avaliada
como parte de seus resultados em um arquivo chamado geracoes.mps.

– O arquivo geracoes.mps deve ser organizado para mostrar todas as evoluções,
contando inclusive com a matriz de origem da execução.

– Na tela, basta apresentar as mensagens de algoritmo executando e processo
de gerações finalizado.

– Como entradas, pedir ao usuário para digitar apenas o número de gerações a
ser avaliado.

– Para a matriz de entrada, crie uma pasta chamada datasets dentro do seu projeto
e fora da pasta src, armazenando ela como input.mps.

## IMPLEMETAÇÃO DO CÓDIGO

### O programa foi dividido em 3 partes:

#### jogo_da_vida.hpp

- Inclui as bibliotecas usadas no código (`<vector>`, `<string>`, `<iostream>`, `<fstream>`).
- Define a classe `JogoDaVida` com membros públicos e privados.
   - Os membros privados incluem uma matriz 2D para representar o tabuleiro e o nome do arquivo de entrada.
   - Os membros públicos incluem o construtor, métodos para carregar a matriz, exibir o estado inicial, gerar gerações e contar vizinhos vivos.

#### jogo_da_vida.cpp

- Inclui as bibliotecas mencionadas no cabeçalho.
- Implementa os métodos da classe `JogoDaVida`.
   - O método `carregarMatriz` lê a matriz de um arquivo, validando seu tamanho e conteúdo.
   - O método `exibirEstadoInicial` mostra a matriz inicial carregada.
   - O método `gerarGeracoes` calcula as próximas gerações conforme as regras do Jogo da Vida e as salva em um arquivo de relatório (geracoes.mps).
 
#### main.cpp

   - Inclui o cabeçalho da classe `JogoDaVida`.
   - Instancia-se um objeto `JogoDaVida`.
   - Carrega a matriz do arquivo.
   - Exibe o estado inicial.
   - Solicita o número de gerações ao usuário e gera as gerações necessárias.

## IMPLEMENTAÇÃO DAS FUNÇÕES 

### Construtor JogoDaVida::JogoDaVida(const std::string& arquivo):
    O construtor é responsável por inicializar a classe JogoDaVida e definir o nome do arquivo de entrada.
    
### Método bool JogoDaVida::carregarMatriz():
    Este método carrega a matriz do arquivo de entrada, verificando se o arquivo está no formato correto e se os dados são válidos.
    
### Método void JogoDaVida::exibirEstadoInicial():
    Exibe na tela o estado inicial da matriz carregada a partir do arquivo.
    
### Método void JogoDaVida::gerarGeracoes(int numGeracoes):
    Calcula e gera as próximas gerações do Jogo da Vida com base nas regras estabelecidas, salvando cada geração em um arquivo de relatório.
    
### Método int JogoDaVida::contarVizinhosVivos(int linha, int coluna):
    Conta o número de vizinhos vivos de uma célula na posição especificada da matriz.
    
## FLUXO DE EXECUÇÃO 

### 1 Carregamento da Matriz Inicial:

  - O programa começa carregando uma matriz inicial a partir de um arquivo de entrada especificado.
  - Esta matriz representa o estado inicial do tabuleiro do Jogo da Vida.
   
### 2 Exibição do Estado Inicial:

  - Após carregar a matriz, o programa a exibe na tela para que o usuário possa visualizar como o jogo começa.

### 3 Solicitação do Número de Gerações:

  - O programa solicita ao usuário que digite o número de gerações que deseja simular no Jogo da Vida.

### 4 Geração das Próximas Gerações:

  - Com base no número de gerações informado pelo usuário, o programa calcula e salva as próximas gerações do Jogo da Vida em um arquivo de relatório.
  - Cada nova geração é produzida seguindo as regras do jogo, utilizando a matriz da geração anterior como referência.
  - O processo é repetido até que o número desejado de gerações seja alcançado.
  
### 5 Finalização do Programa:

  - Após gerar todas as gerações solicitadas, o programa exibe uma mensagem indicando que o processo de gerações foi concluído.
  - A execução do programa é encerrada.

## COMPILAÇÃO E EXECUÇÃO  

O arquivo makefile disponibilizado pelo professor Michel realiza os comandos que compilam e executam o código. Tais comandos são:
  
|Comando 	    |Função                                                                                  |
|---------------|----------------------------------------------------------------------------------------|
|make clean     |Apaga a última compilação realizada contida na pasta build                              |
|make 	        |Executa a compilação do programa utilizando o gcc e o resultado vai para a pasta build |
|make run 	    |Executa o programa da pasta build após a realização da compilação      

##CONCLUSÃO

  O programa atende aos requisitos do trabalho, incluindo a manipulação de matrizes, controle de fluxo, leitura e escrita em arquivos, e a implementação das regras do Jogo da Vida. A estrutura do código é organizada e modular, facilitando a compreensão e manutenção do código.
