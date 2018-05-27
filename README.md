# Algoritmo de dijkstra

## Função
Em um grafo direcionado ponderado:
Determinar peso necessário até todos os vértices do grafo, deixando um rastro do caminho mais curto.

## Funcionamento
- O arquivo exemplo __entrada.txt__ são informados:
 - Arquivo:
 ```
 <vertice-de-origem-dijkstra>
 <quantidade-de-vertices> <quantidade-de-arestas>
 <verticeDeOrigem> <verticeDestino> <pesoAresta>
 <verticeDeOrigem> <verticeDestino> <pesoAresta>
 ...
 <verticeDeOrigem> <verticeDestino> <pesoAresta>
 ```
 - Exemplo no arquivo __entrada.txt__:
 ```
 1
 10 16
 1 2 1
 1 3 2
 1 4 3
 2 7 3
 3 7 1
 3 5 4
 4 5 2
 7 8 5
 3 6 6
 5 6 3
 5 9 10
 6 8 7
 6 10 9
 6 9 1
 8 10 2
 9 10 9
 ```
- Para executar o programa:
  - Executar no terminal
   - É necessário ter um arquivo de entrada válido!
   - Para compilar códigos (mais detalhes no makefile):
  ```shell
  make
  ```
   - Para executar
  ```shell
  ./dijkstra <arquivo-de-entrada> <arquivo-de-saida>
  ```

- Será gerado um arquivo de saída:
 - Arquivo:
 ```
 <vertice> <peso-para-alcançar> <vertice-anterior>
 <vertice> <peso-para-alcançar> <vertice-anterior>
 ...
 <vertice> <peso-para-alcançar> <vertice-anterior>
 ```
 - Exemplo de arquivo de saída:
  ```
  1 0.000000 -1
  2 1.000000 1
  3 2.000000 1
  4 3.000000 1
  5 5.000000 4
  6 8.000000 3
  7 3.000000 3
  8 8.000000 7
  9 9.000000 6
  10 10.000000 8
  ```
   - O valor -1 é atribuído a vétices impossíveis de serem alcançados a partir da origem determinada.
