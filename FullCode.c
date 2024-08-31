
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


#define tam 4 // Tamanho do mapa = (tam * tam)

#define forca 2000 /*apenas um conceito abstrato para análises apenas diminua se aumentar o tabuleiro
não há motivos para diminuir ou aumentar em um tabuleiro 4x4
*/


double AuxiliarGlobalData = 0;//Faz a comunicação do monteCarlo com a macro

bool movimentos(int map[tam][tam], int direcao){
    bool validacao = false;
    int atual = -1;
    int posicao;
    int posicaoDois;
    int SomadorOuDecrementador, contador, parada;
    if (direcao % 2 == 0)
    {
        SomadorOuDecrementador = -1;
        contador = tam-1;
        parada = -1;
    }
    else{
        SomadorOuDecrementador =1;
        parada = tam;
        contador = 0;
    }

    //direita e esquerda
    if (direcao < 3) {
        for (int i = contador; i != parada; i += SomadorOuDecrementador) {
            posicao = contador;
            atual = -1;
            for (int j = contador; j != parada; j += SomadorOuDecrementador) {
                if (map[i][j] != 0) {
                    if (map[i][j] != atual) {
                        atual = map[i][j];
                        if(posicao != j){
                            map[i][j] = 0;
                            map[i][posicao] = atual;
                            if (!validacao) validacao = true;
                        }
                        
                        posicaoDois = posicao;
                        posicao+= SomadorOuDecrementador;
                    } else{
                        map[i][j] = 0;
                        map[i][posicaoDois] += 1;
                        atual = -1;
                        if (!validacao) validacao = true;
                    } 
                }
            }
        }
    } else {
        // Para cima e para baixo
        for (int i = contador; i != parada; i += SomadorOuDecrementador) {
            posicao = contador;
            atual = -1;
            for (int j = contador; j != parada; j += SomadorOuDecrementador) {
                if (map[j][i] != 0) {
                    if (map[j][i] != atual) {
                        atual = map[j][i];
                        if(posicao != j){
                            map[j][i] = 0;
                            map[posicao][i] = atual;
                            if (!validacao) validacao = true;
                        }
                        
                        posicaoDois = posicao;
                        posicao+= SomadorOuDecrementador;
                    } else  {
                        map[j][i] = 0;
                        map[posicaoDois][i] += 1;
                        atual = -1;
                        if (!validacao) validacao = true;
                    } 
                    
                }
            }
        }
    }
    if(validacao)sorteio(map);
    return validacao;
}

void sorteio(int tabuleiro[tam][tam]){
    int tamanho = 0, NovoBloco,R,corretor;
    corretor = (tam * tam);
    int VetorDeControle[corretor];
    R = rand() % 10;
    NovoBloco = (R > 8) ? 2 : 1;
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if(tabuleiro[i][j] == 0){
                VetorDeControle[tamanho] = (i*tam) + j ;
                tamanho++;
            }
        }
        
    }
    R = rand() % tamanho;
     tabuleiro[(VetorDeControle[R]) / tam][(VetorDeControle[R]) % tam] = NovoBloco;
    
}

void mostra(int tabuleiro[tam][tam]){
    for (int i = tam - 1; i >= 0; i--)
    {
        for(int j = tam - 1; j >= 0; j--){
            printf("| %d |",tabuleiro[i][j]);
        }
        printf("\n");
    }
    
}
    
bool ends(int tab[tam][tam]){
    int mat[tam][tam];

    copy(tab,mat);
    for (int i = 1; i < 5; i++)
    {
        if (movimentos(mat,i))return true;
        copy(tab,mat);
    }

    
    return false;
    
}
void copy(int tabprime[tam][tam],int secondtab[tam][tam]){
    for(int i = 0; i < tam; i++){
        for (int j= 0; j < tam; j++)
        {
            secondtab[i][j] = tabprime[i][j];
        }
        
    }
}

int MonteCarlo(int tab[tam][tam]){
    int matTeste[tam][tam];
    int matrizDeDesenvolvimento[tam][tam];
    copy(tab,matTeste);
    int range = 0;
    for(int i = 1; i < 5; i++){
        if(movimentos(matTeste,i))range++;
        copy(tab,matTeste);
    }
    range = ( forca/range);
    int R;
    
    double mediaMoves[4];
    for(int i = 0; i < 4; i++){
        mediaMoves[i] = 0;
    }
    for(int k = 0; k < 4; k++){
        if(movimentos(matTeste,k+1)){
            for(int i = 0; i < range; i++){
                copy(matTeste,matrizDeDesenvolvimento);
                do{
                
                    R = (rand() % 4) + 1 ;
                    if(movimentos(matrizDeDesenvolvimento,R))mediaMoves[k]++;
                

                }while(ends(matrizDeDesenvolvimento));

            }
            mediaMoves[k] = mediaMoves[k] /(range * 1.0);
            copy(tab,matTeste);
        }
    }
    
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

int Analise(int tab [tam][tam]){
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
    for(int k = 0; k < 4; k++){
        if(movimentos(matTeste,k+1)){
            for(int i = 0; i < range; i++){
                copy(matTeste,matrizDeDesenvolvimento);
                for(int j = 0; j < 20; j++){
                    do{
                
                        R = (rand() % 4) + 1 ;
                        if(movimentos(matrizDeDesenvolvimento,R))break;
                
                    }while(ends(matrizDeDesenvolvimento));
                
                }
                mediaZeros[k] += Analise(matrizDeDesenvolvimento);
            
            }
            mediaZeros[k] = mediaZeros[k] /(range * 1.0);
            copy(tab,matTeste);
        }
    }
   
    int MelhorLance = 0;
    for (int i = 0; i < 4; i++)
    {
        if(mediaZeros[MelhorLance] < mediaZeros[i])MelhorLance = i;
    }
    MelhorLance++;
    movimentos(tab,MelhorLance );
    return MelhorLance;
}

void MaiorTab(int tab[tam][tam],int result[3]){
    result[0] = result[1] = result[2] = 0;
    for(int i = 0; i<tam ; i++){
        for( int j = 0; j < tam; j++){
            if(result[0] < tab[i][j]){
                result[2] = result[1];
                result[1] = result[0];
                result[0] = tab[i][j];
                
            }
            else if(result[0] > tab[i][j] && tab[i][j] > result[1] ){
                result[2] = result[1];
                result[1] = tab[i][j];
            }
            else if(tab[i][j] < result[1] && tab[i][j] > result[2]) result[2] = tab[i][j];
        }
    }
}

void Instinto(int tabuleiro[tam][tam]){

    int DadosCarlo[3];
    MaiorTab(tabuleiro,DadosCarlo);
    
    if(DadosCarlo[0] < 4){
        printf("MonteCarlo jogou:\n");
        MonteCarlo(tabuleiro);
        return;
    }
    else if(DadosCarlo[0] < 9){
        printf("Circular Brain jogou:\n");
        CircularBrain(tabuleiro);
        return;
    }
    else{
        
        int matrizDeDesenvolvimento1[tam][tam];
        int matrizDeDesenvolvimento2[tam][tam];
        copy(tabuleiro,matrizDeDesenvolvimento1);
        copy(tabuleiro,matrizDeDesenvolvimento2);
        double auxiliarLocal= 0;
        int DadosCircular[3],JogadaCircular = 0, JogadaCarmo = 0, zeros1,zeros2;
        
        if(DadosCarlo[0] < 10){
            printf("Macro IA simples jogou:\n");
            
            JogadaCarmo = MonteCarlo(matrizDeDesenvolvimento1);
            
            JogadaCircular = CircularBrain(matrizDeDesenvolvimento2);
            zeros1 = Analise(matrizDeDesenvolvimento1);
            zeros2 = Analise(matrizDeDesenvolvimento2);
            
            
            (zeros1 > zeros2) ? movimentos(tabuleiro,JogadaCarmo) : movimentos(tabuleiro,JogadaCircular); 
        }
        else{
            
            JogadaCarmo = MonteCarlo(matrizDeDesenvolvimento1);
            auxiliarLocal = AuxiliarGlobalData;
            
            JogadaCircular = CircularBrain(matrizDeDesenvolvimento2);
            
            MonteCarlo(matrizDeDesenvolvimento2);
            
            if(AuxiliarGlobalData > auxiliarLocal){
                printf("MacroIA 100%% jogou:\n");
                movimentos(tabuleiro,JogadaCircular);
            } 
            else{
                
                for(int i = 0; i < 3; i++){
                    MonteCarlo(matrizDeDesenvolvimento1);
                    CircularBrain(matrizDeDesenvolvimento2);
                }
                int jogada1 = 0,jogada2 = 0;
                zeros1 = Analise(matrizDeDesenvolvimento1);
                zeros2 = Analise(matrizDeDesenvolvimento2);
                MaiorTab(matrizDeDesenvolvimento1,DadosCarlo);
                MaiorTab(matrizDeDesenvolvimento2,DadosCircular);
                
                if(zeros1 > zeros2) jogada1 +=4;
                
                else if( zeros2 > zeros1) jogada2 += 4;
                
                for(int i = 2; i >= 0; i--){
                    if(DadosCarlo[i] > DadosCircular[i])jogada1 += i + 1;
                    else if(DadosCircular[i] > DadosCarlo[i]) jogada2 += i + 1;
                }
                printf("MacroIA 100%% jogou:\n");
                if(jogada1 >= jogada2){
                    
                    movimentos(tabuleiro,JogadaCarmo);
                    
                }
                else{
                    movimentos(tabuleiro,JogadaCircular);
                }
                
                
            }
        }
    }
}
bool breaker(int tab[tam][tam]){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(tab[i][j] == 11)return true;
        }
    }
    return false;
}
int main(){
    int tabuleiro[tam][tam];
    
    int decisao;
    printf("Digite\n 1 - Monte Carlo ganha 2048\n 2 - Circular Circular Brain Ganha\n 3 - show match, IA1+IA2+MacroIA\n outro numero fecha\n");
    printf("todo azulejo sera logaritmado na base 2\n");
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            tabuleiro[i][j] = 0;
        }
        
    }
    
    
    scanf("%d",&decisao);
    
    sorteio(tabuleiro);
    sorteio(tabuleiro);
    switch(decisao){
        case 1:
            mostra(tabuleiro);
            do{
                printf("MonteCarlo jogou:\n");
                MonteCarlo(tabuleiro);
                mostra(tabuleiro);
            }while(ends(tabuleiro) && !breaker(tabuleiro));
            break;
        
        case 2:
            mostra(tabuleiro);
            do{
                printf("Circular Brain jogou: \n");
                CircularBrain(tabuleiro);
                mostra(tabuleiro);
            }while(ends(tabuleiro) && !breaker(tabuleiro));
            break;
            
        case 3:
             mostra(tabuleiro);
            do{
                
                Instinto(tabuleiro);
                mostra(tabuleiro);
            }while(ends(tabuleiro) && !breaker(tabuleiro));
            break;
        
        default: 
            printf("encerrando\n");
            return 0;
            
    }   
    

}
