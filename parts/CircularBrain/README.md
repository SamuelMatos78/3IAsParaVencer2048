# Estratégia Circular Brain para Inteligência Artificial no Jogo 2048:
Este código implementa a estratégia de Circular Brain para a Inteligência Artificial no jogo 2048. A função CircularBrain é responsável por explorar diferentes jogadas e escolher a que maximize o número de espaços vazios no tabuleiro.

Funções Implementadas
Além da função CircularBrain, o código também inclui a função Analise para contar o número de espaços vazios no tabuleiro.

1. Analise(int tab[tam][tam])
Esta função conta o número de espaços vazios no tabuleiro.

2. CircularBrain(int tab[tam][tam])
Esta função implementa a estratégia de Circular Brain:

Inicializa uma matriz de teste matTeste para realizar simulações.

Calcula um range para o número de simulações baseado na força.

Inicializa um array mediaZeros para armazenar a média de espaços vazios para cada direção possível.

## Para cada direção:
Se for possível mover na direção, realiza range simulações e calcula a média de espaços vazios.
Atualiza mediaZeros com a média de espaços vazios para essa direção.
Escolhe a direção que resulta na maior média de espaços vazios.
Retorna o número da direção com o melhor lance possível.
```c
int Analise(int tab[tam][tam]){
    int zeros = 0;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(tab[i][j] == 0) zeros++;
        }
    }
    return zeros;
}

int CircularBrain(int tab[tam][tam]){
    int matTeste[tam][tam];
    int matrizDeDesenvolvimento[tam][tam];
    copy(tab,matTeste);
    
    int R;
    int range = forca * 2;
    double mediaZeros[4];
    for(int i = 0; i < 4; i++){
        mediaZeros[i] = 0;
    }
    if(movimentos(matTeste,1)){
        for(int i = 0; i < range; i++){
            copy(matTeste,matrizDeDesenvolvimento);
            for(int j = 0; j < 20; j++){
                do{
                    R = (rand() % 4) + 1 ;
                    if(movimentos(matrizDeDesenvolvimento,R))break;
                }while(ends(matrizDeDesenvolvimento));
            }
            mediaZeros[0] += Analise(matrizDeDesenvolvimento);
        }
        mediaZeros[0] = mediaZeros[0] /(range * 1.0);
         copy(tab,matTeste);
    }
    
    // Similar para as outras direções (2, 3 e 4)...

    int MelhorLance = 0;
    for (int i = 0; i < 4; i++)
    {
        if(mediaZeros[MelhorLance] < mediaZeros[i])MelhorLance = i;
    }
    MelhorLance++;
    movimentos(tab,MelhorLance );
    return MelhorLance;
}
```
Este README considera que as funções auxiliares foram implementadas corretamente, Além de fazer sua jogada de forma automática retorna o número 
da jogada para ser utilizado na macroIA
