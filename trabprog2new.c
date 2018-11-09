#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//mudar config.txt
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

    char *arquivoteste, *arquivotreino, *predicoes, *modoDecalcular, c, lixo;
    int *numeroDeVizinhos, colunas=0, i=0, j=0, linhas=0, colunasTeste=0, colunasTreino=0, linhasTeste=0, linhasTreino=0, *todasColunas;
    float *raio, **matrizDeTeste, **matrizDeTreino;
    int n;

    todasColunas = (int *) malloc(1 * sizeof(int));

    matrizDeTreino = (float **) malloc(1*sizeof(float*));
    for(j=0; j<1; j++){
        matrizDeTreino[j] = (float *) malloc(1*sizeof(float));
    }
    matrizDeTeste = (float **) malloc(1*sizeof(float*));
    for(j=0; j<1; j++){
        matrizDeTeste[j] = (float *) malloc(1*sizeof(float));
    }

    FILE *arq;
    arq = fopen("iris/config.txt", "r");
    if(arq == NULL){
        printf("Erro");
        return 1;
    }

    while(fread (&c, sizeof(char), 1, arq)) {
            if(c != '\n') {
                colunas++;
            }else if(linhas==0){
                n = linhas + 1;
                todasColunas = (int *) malloc( n * sizeof(int));
                todasColunas[linhas] = colunas +1;
                linhas++;
                colunas = 0;
                }else{
                    n = linhas + 1;
                    todasColunas = (int *) realloc(todasColunas, n * sizeof(int));
                    todasColunas[linhas] = colunas + 1;
                    linhas++;
                    colunas = 0;
                }
    
    }

    arquivotreino = (char *) malloc(todasColunas[0] * sizeof(char));
    arquivoteste = (char *) malloc(todasColunas[1] * sizeof(char));
    predicoes = (char *) malloc(todasColunas[2] * sizeof(char));
    numeroDeVizinhos = (int *) malloc((linhas - 3) * sizeof(int));
    raio = (float *) malloc((linhas - 3) * sizeof(float));
    modoDecalcular = (char *) malloc((linhas - 3) * sizeof(char));
    
    rewind(arq);
    colunas=0;
    //Aloca os vetores de arquivos e de entradas
    while(!feof(arq)){
        while(fscanf(arq, "%c", &c) && linhas <3){
            if(c != '\n'){
                switch(linhas){
                    case 0: arquivotreino[i] = c;
                            printf("%c", arquivotreino[i]);
                            i++;
                            break;
                    case 1: arquivoteste[i] = c;
                            printf("%c", arquivoteste[i]);
                            i++;
                            break;
                    case 2: predicoes[i] = c;
                            printf("%c", predicoes[i]);
                            i++;
                            break;
                }
            }else{
                linhas++;
                i=0;
                printf("\n");
            }
        }
        i=0;
        fscanf(arq, "%i, %c", &numeroDeVizinhos[i], &modoDecalcular[i]);
        if(modoDecalcular[i] == 'M'){
            fscanf(arq, ", %f", &raio[i]);
        }else{
            raio[i] = 0;
        }
        printf("%i, %c, %f\n", numeroDeVizinhos[i], modoDecalcular[i], raio[i]);
        i++;
    }

    for(i=0; i<strlen(arquivoteste); i++){
        printf("%c", arquivoteste[i]);
    }
    
    /*FILE *arqteste;
    arqteste = fopen(arquivoteste, "r");
    if(arqteste == NULL){
        printf("Erro");
        return 1;
    }
    i=0;
    j=0;
    char *f;
    while(fscanf(arqteste, "%c", &c)){
        if(c != '\n'){
            colunasTreino++;
            matrizDeTreino[i] = (float *) realloc(matrizDeTreino[i], colunasTreino * sizeof(float));
            f = &c;
            matrizDeTreino[i][j] = atof(f);
            printf("%f", matrizDeTreino[i][j]);
            j++;
        }else{
            linhasTreino++;
            matrizDeTreino = (float **) realloc(matrizDeTreino, colunasTreino * sizeof(float *));
            colunasTreino=0;
            i++;
            j=0;
            printf("\n");
        }
    }*/

    free(todasColunas);

    free(arquivoteste);
    free(arquivotreino);
    free(predicoes);
    free(modoDecalcular);
    free(numeroDeVizinhos);
    free(raio);

    for(j=0; j<colunasTreino; j++){
        free(matrizDeTreino[i]);
    }
    free(matrizDeTeste);
    for(j=0; j<colunasTeste; j++){
        free(matrizDeTeste[i]);
    }
    free(matrizDeTeste);

    return 0;
}