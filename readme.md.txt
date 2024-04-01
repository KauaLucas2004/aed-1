Trabalho 0 AEDS - Jogo da Vida

Descrição do Exercício: Jogo da Vida

O Jogo da Vida é um autômato celular que evolui de acordo com regras simples, mas
gera padrões complexos. Ele é representado por uma matriz 2D de células, cada uma
podendo estar viva ou morta.

1. Crie uma matriz N x N para representar o tabuleiro do Jogo da Vida.
2. Inicialize o tabuleiro com células vivas (1) e mortas (0) aleatoriamente.
3. Implemente uma função para exibir o estado atual do tabuleiro.
4. Implemente uma função para produzir um relatório de execução, guardando o
histórico da evolução do jogo em arquivo.
5. Implemente uma função para calcular a próxima geração do Jogo da Vida com base
nas seguintes regras:
- Uma célula viva com menos de dois vizinhos vivos morre (solidão).
- Uma célula viva com mais de três vizinhos vivos morre (superpopulação).
- Uma célula viva com dois ou três vizinhos vivos sobrevive.
- Uma célula morta com exatamente três vizinhos vivos se torna viva (reprodução).
6. Execute várias gerações do jogo e mostre o estado do tabuleiro após cada geração.

O objetivo deste trabalho é revisar os conceitos de manipulação de matrizes, controle
de fluxo e lógica de jogo. Para tanto considere como parte de sua tarefa:

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