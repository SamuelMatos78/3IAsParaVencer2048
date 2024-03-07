# 3IAsParaVencer2048
Aqui estará um repositório para te ajudar com ideias e introduzir mais a fundo IAs para resolver alguns problemas abstratos, como o jogo 2048 por exemplo. 

# Este código tem um proposito educativo.

## Visão geral do codigo:

O código implementa um jogo 2048 com três agentes de inteligência artificial (IA):

Monte Carlo: Este agente utiliza o método de Monte Carlo para realizar simulações e escolher a jogada com maior probabilidade de levar à vitória.
  Uma explicação mais simples seria de que ele simula jogos aleatorios e escolhe o proximo movimento em que sua média de jogadas na partida foi maior (o movimento que ele sobreviveu por mais tempo)

Circular Brain: Este agente utiliza um algoritmo circular para explorar diferentes jogadas e escolher a que maximize o número de espaços vazios no tabuleiro.
  Muito boa para Lidar com a Aleatoriedade do Game, tem um raciocinio a um prazo relativamente curto porém ela sempre planeja como aumentar a quantidade de zeros(espaços vazios) no tabuleiro sendo bem agressiva.

MacroIA: Este agente é uma combinação dos dois agentes anteriores, utilizando o Monte Carlo para a primeira jogada e o Circular Brain para as jogadas subsequentes.
  Este código analisa a métrica dos dois, pode colocar um para analisar o tabuleiro do outro para ver se encontra uma jogada melhor ou simular profundidade.
  
O código também inclui as seguintes funções:

movimentos(tabuleiro, direcao): Move os blocos no tabuleiro na direção especificada, além de fazer junções.
  É basicamente toda a movimentação possivel no jogo de forma compactada dentro dela.
sorteio(tabuleiro): Adiciona um novo bloco aleatoriamente no tabuleiro.
mostra(tabuleiro): Exibe o tabuleiro no console.
ends(tab): Verifica se o jogo terminou.
copy(tabprime, secondtab): Copia o conteúdo de um tabuleiro para outro.
Analise(tab): Conta o número de espaços vazios no tabuleiro.
MaiorTab(tab,result): Encontra os três maiores valores no tabuleiro.

### Como Executar o Jogo
Para executar o jogo, basta chamar a função principal jogo_2048() que irá iniciar o jogo com um tabuleiro inicializado. Os agentes de IA serão então alternados para fazer suas jogadas e o jogo continuará até que não seja possível realizar mais movimentos ou até alcançar o objetivo de 2048.

Para selecionar um agente específico, basta configurar a variável agente para um dos valores abaixo:

0 para o agente Monte Carlo.
1 para o agente Circular Brain.
2 para fazer uma partida de exibição, onde ambas as IAs aparecem e o agente MacroIA.
