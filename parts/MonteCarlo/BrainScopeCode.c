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
