#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//Ordena do menor para o maior
void quick_sort(float *amostrasvizinhas, int primeiro, int ultimo) {
    int i, j, z;
    float x, y;
     
    i = primeiro;
    j = ultimo;
    z= (primeiro + ultimo) / 2;
    x = amostrasvizinhas[z];
     
    while(i <= j) {
        while(amostrasvizinhas[i] < x && i < ultimo) {
            i++;
        }
        while(amostrasvizinhas[j] > x && j > primeiro) {
            j--;
        }
        if(i <= j) {
            y = amostrasvizinhas[i];
            amostrasvizinhas[i] = amostrasvizinhas[j];
            amostrasvizinhas[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > primeiro) {
        quick_sort(amostrasvizinhas, primeiro, j);
    }
    if(i < ultimo) {
        quick_sort(amostrasvizinhas, i, ultimo);
    }
}

int main(){

    char url[]="iris/config.txt";
    char **matrizConfigArq, **matrizIrisTeste, c, ch;
    int i, j, w=0, linhas=0, colunas=0;
    int *todasColunas, n;
    float **matrizConfig;
    //Abre o arquivo (ok)
    FILE *arq;
    arq = fopen(url, "r");
    if(arq==NULL){
        printf ("Erro na abertura de arquivo! Programa terminado...");
        exit (1);
    }
    //Conta o numero de linhas e colunas de arq (ok)
    while(fread (&c, sizeof(char), 1, arq)) {
            if(c != '\n') {
                colunas++;
            }else if(linhas==0){
                n = linhas + 1;
                //Conta o numero de linhas e coloca o numero de colunas na linha que pertence (ok)
                todasColunas = (int *) malloc( n * sizeof(int));
                todasColunas[linhas] = colunas;
                linhas++;
                colunas = 0;
                }else{
                    n = linhas + 1;
                    todasColunas = (int *) realloc(todasColunas, n * sizeof(int));
                    todasColunas[linhas] = colunas;
                    linhas++;
                    colunas = 0;
                }
    }
    //Aloca a matriz com o nome de outros arquivos (ok)
    matrizConfigArq = (char **) malloc(linhas * (sizeof(char *)));
    for(i=0; i<linhas; i++){
        matrizConfigArq[i] = (char *) malloc((todasColunas[i]+1) * (sizeof(char)));
    }
    //Aloca a matriz com as entradas (ok)
    matrizConfig = (float **) malloc((linhas - 3) * (sizeof(float *)));
    for(i=0; i<linhas; i++){
        matrizConfig[i] = (float *) malloc((todasColunas[i]) * (sizeof(float)));
    }
    //Le o arquivo e coloca na matriz (dando erro)
    for(i = 3; i < linhas; i++){
        for(j = 0; j < todasColunas[i]; j++) {
            fscanf(arq, "%lf", &matrizConfig[i][j]);
            printf("%lf ",matrizConfig[i][j]);
        }
        printf("\n");
    }
    //Não Funciona
    /*for(i = 0; i < 3; i++){
        fgets(matrizConfigArq[i], todasColunas[i], arq);
    }
    for(i=0; i<3; i++){
        for(j=0; j<todasColunas[i]; j++){
            printf("%c", matrizConfigArq[i][j]);
        }
        printf("\n");
    }*/
    fclose(arq);
    //Copia o arquivo para a matriz em forma de vetores
    /*for(i=0; i<linhas; i++){
        fgets(matrizConfig[i], todasColunas[i], arq);
        
    }*/
    //Printa a matriz 
    /*for(i=0; i<linhas; i++){
        for(j=0; j<todasColunas[i]; j++){
            printf("%c", matrizConfig[i][j]);
        }
        printf("\n");
    }/*
    //Abre o arquivo
    FILE *arq1;
    arq1 = fopen(matrizConfig[0], "r");
    if(arq1==NULL){
        printf ("Erro na abertura de arquivo! Programa terminado...");
        exit (1);
    }
    //Conta o numero de linhas de arq
    while(!feof(arq1) ){
        fscanf(arq1, "%c", ch);
		if(ch == '\n'){
			linhas++;
        }
    }
    int todasColunas1[linhas], y;
    //conta o numero de colunas de arq e as coloca em ordem em um vetor 
    while(!feof(arq1)){
        fscanf(arq1, "%c", ch);
        if(ch != '\n'){
            colunas++;
        }else{
            todasColunas1[y]=colunas;
            colunas=0;
            y++;
        }
    }
    //Aloca a matriz
    matrizIrisTeste = (char **) malloc(linhas * (sizeof(char *)));
    for(i=0; i<linhas; i++){
       matrizIrisTeste[i] = (char *) malloc(todasColunas1[i] * (sizeof(char)));
    }
    //Copia o arquivo para a matriz em forma de vetores
    for(i=0; i<linhas; i++){
        fgets(matrizIrisTeste[i], todasColunas1[i], arq);
    }
    //Fecha o arquivo
    fclose(arq1);*/


   /* char escolhaDeCalculo;
    int k, r, DE, de, DM, dm, DC, dc, Acc, A, T, numDeRotulos;

    switch(escolhaDeCalculo){
       case 'E'://Distância Euclidiana soma
                
                //Distância Euclidiana final
                DE = sqrt(de)
                break;
        case 'M'://Distância Minkowsky soma

                //Distância Minkowsky final
                DM = (dm)^(1/r)
                break;

        case 'C'://Distância de Chebyshev

                //Distância Euclidiana soma
                
                //Distância Euclidiana final
                DE = sqrt(de)
                //Similaridade de Cosseno final
                DC = dc/DE
                break;
    }

    int matDeConf[numDeRotulos][numDeRotulos];*/

    //Desaloca a matriz
    free(todasColunas);
    for(i=0; i<linhas; i++){
        free(matrizConfig[i]);
        free(matrizConfig[i]);
        free(matrizIrisTeste[i]);
    }
    for(i=0; i<linhas; i++){
        free(matrizConfig[i]);
    }

    return 0;
}