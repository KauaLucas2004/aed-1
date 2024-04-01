# TRABALHO 0 AEDS - JOGO DA VIDA

## INTRODUÇÃO

O trabalho foi proposto na disciplina de Labroratório de Arquitetura e Organização de Computadores pelo professor Michel Pires da Silva do Centro Federal de Educação Tecnológica de Minas Gerais.
O trabalho consiste no desenvolvimento de um Jogo da Vida, um autômato celular que evolui de acordo com regras simples, mas gera padrões complexos, o qual é representado por uma matriz 2D de células, cada uma
podendo estar viva (1) ou morta (0).

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
e fora da pasta src, armazenando ela como input.mps

##IMPLEMETAÇÃO


#LÓGICA DO CÓDIGO
