# Como Funciona:
Inicialização das Variáveis:
matTeste: Matriz de teste para simulações.
matrizDeDesenvolvimento: Matriz usada para desenvolver as simulações.
range: Contador de movimentos possíveis.
```c

int MonteCarlo(int tab[tam][tam]){
    int matTeste[tam][tam];
    int matrizDeDesenvolvimento[tam][tam];
    copy(tab,matTeste);
    int range = 0;
```
Cálculo do Range:
Verifica quantos movimentos são possíveis a partir do estado atual do tabuleiro.
Calcula o range como a força do movimento dividida pelo número de movimentos possíveis.
```c

    for(int i = 1; i < 5; i++){
        if(movimentos(matTeste,i))range++;
        copy(tab,matTeste);
    }
    range = ( forca/range);
```
## Simulação de Movimentos:
mediaMoves: Array para armazenar a média de movimentos para cada direção possível.
Para cada direção:
Se for possível mover na direção, realiza range simulações e calcula a média de movimentos.
Atualiza mediaMoves com a média de movimentos para essa direção.

```c


    double mediaMoves[4];
    for(int i = 0; i < 4; i++){
        mediaMoves[i] = 0;
    }

    // Simulação para direção 1
    if(movimentos(matTeste,1)){
        for(int i = 0; i < range; i++){
            copy(matTeste,matrizDeDesenvolvimento);
            do{
                R = (rand() % 4) + 1 ;
                if(movimentos(matrizDeDesenvolvimento,R))mediaMoves[0]++;
            }while(ends(matrizDeDesenvolvimento));
        }
        mediaMoves[0] = mediaMoves[0] /(range * 1.0);
         copy(tab,matTeste);
    }

    // Simulação para direção 2
    if(movimentos(matTeste,2)){
        for(int i = 0; i < range; i++){
            copy(matTeste,matrizDeDesenvolvimento);
            do{
                R = (rand() % 4) + 1 ;
                if(movimentos(matrizDeDesenvolvimento,R))mediaMoves[1]++;
            }while(ends(matrizDeDesenvolvimento));
        }
        mediaMoves[1] = mediaMoves[1] /(range * 1.0);
        copy(tab,matTeste);
    }

    // Simulação para direção 3
    if(movimentos(matTeste,3)){
        for(int i = 0; i < range; i++){
            copy(matTeste,matrizDeDesenvolvimento);
            do{
                R = (rand() % 4) + 1 ;
                if(movimentos(matrizDeDesenvolvimento,R))mediaMoves[2]++;
            }while(ends(matrizDeDesenvolvimento));
        }
        mediaMoves[2] = mediaMoves[2] /(range * 1.0);
        copy(tab,matTeste);
    }

    // Simulação para direção 4
    if(movimentos(matTeste,4)){
        for(int i = 0; i < range; i++){
            copy(matTeste,matrizDeDesenvolvimento);
            do{
                R = (rand() % 4) + 1 ;
                if(movimentos(matrizDeDesenvolvimento,R))mediaMoves[3]++;
            }while(ends(matrizDeDesenvolvimento));
        }
        mediaMoves[3] = mediaMoves[3] /(range * 1.0);
         copy(tab,matTeste);
    }
```
## Escolha do Melhor Lance:
Comparação das médias de movimentos para determinar a direção com melhor desempenho.
Retorna o número da direção que resulta no melhor lance.
```c

    int MelhorLance = 0;
    for (int i = 0; i < 4; i++)
    {
        if(mediaMoves[MelhorLance] < mediaMoves[i]){
            MelhorLance = i;
            AuxiliarGlobalData = mediaMoves[i];
        }
    }
    MelhorLance++;
    movimentos(tab,MelhorLance );
    return MelhorLance;

}
```
Este README considera que todas as outras funções foram implementadas corretamente, além de realizar a jogada de forma Automática, também se comunica com a Variável global e retorna o Número da jogada para a MacroIA
