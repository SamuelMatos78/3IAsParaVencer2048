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
    
    if(movimentos(matTeste,2)){
        for(int i = 0; i < range; i++){
            copy(matTeste,matrizDeDesenvolvimento);
            for(int j = 0; j < 20; j++){
                do{
                
                    R = (rand() % 4) + 1 ;
                    if(movimentos(matrizDeDesenvolvimento,R))break;
                }while(ends(matrizDeDesenvolvimento));
                
            }
            mediaZeros[1] += Analise(matrizDeDesenvolvimento);
            
        }
        mediaZeros[1] = mediaZeros[1] /(range * 1.0);
         copy(tab,matTeste);
    }

    
    if(movimentos(matTeste,3)){
        for(int i = 0; i < range; i++){
            copy(matTeste,matrizDeDesenvolvimento);
            for(int j = 0; j < 20; j++){
                do{
                
                    R = (rand() % 4) + 1 ;
                    if(movimentos(matrizDeDesenvolvimento,R))break;
                }while(ends(matrizDeDesenvolvimento));
                
            }
            mediaZeros[2] += Analise(matrizDeDesenvolvimento);
            
        }
        mediaZeros[2] = mediaZeros[2] /(range * 1.0);
         copy(tab,matTeste);
    }
    
    if(movimentos(matTeste,4)){
        for(int i = 0; i < range; i++){
            copy(matTeste,matrizDeDesenvolvimento);
            for(int j = 0; j < 20; j++){
                do{
                
                    R = (rand() % 4) + 1 ;
                    if(movimentos(matrizDeDesenvolvimento,R))break;
                
                }while(ends(matrizDeDesenvolvimento));
                
            }
            mediaZeros[3] += Analise(matrizDeDesenvolvimento);
            
        }
        mediaZeros[3] = mediaZeros[3] /(range * 1.0);
         copy(tab,matTeste);
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
