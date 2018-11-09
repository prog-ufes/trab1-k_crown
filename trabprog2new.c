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
    int *numeroDeVizinhos, colunas, i, j=0, linhas=0, colunasTeste=0, colunasTreino=0, linhasTeste=0, linhasTreino=0, todasColunas[3];
    float *raio, **matrizDeTeste, **matrizDeTreino;

    FILE *arq;
    arq = fopen("iris/config.txt", "r");
    if(arq == NULL){
        printf("Erro");
        return 1;
    }

    arquivotreino = (char *) malloc(10 * sizeof(char));
    arquivoteste = (char *) malloc(10 * sizeof(char));
    predicoes = (char *) malloc(10 * sizeof(char));
    numeroDeVizinhos = (int *) malloc(1 * sizeof(int));
    raio = (float *) malloc(1 * sizeof(float));
    modoDecalcular = (char *) malloc(10 * sizeof(char));

    matrizDeTreino = (float **) malloc(1*sizeof(float*));
    for(j=0; j<1; j++){
        matrizDeTreino[j] = (float *) malloc(1*sizeof(float));
    }
    matrizDeTeste = (float **) malloc(1*sizeof(float*));
    for(j=0; j<1; j++){
        matrizDeTeste[j] = (float *) malloc(1*sizeof(float));
    }

    //Aloca os vetores de arquivos e de entradas
    while(!feof(arq)){
        while(fscanf(arq, "%c", &c) && linhas <3){
            if(c != '\n'){
                switch(linhas){
                    case 0: colunas++;
                            arquivotreino = (char *) realloc(arquivotreino, colunas * sizeof(char));
                            arquivotreino[i] = c;
                            printf("%c", arquivotreino[i]);
                            i++;
                            break;
                    case 1: colunas++;
                            arquivoteste = (char *) realloc(arquivoteste, colunas * sizeof(char));
                            arquivoteste[i] = c;
                            printf("%c", arquivoteste[i]);
                            i++;
                            break;
                    case 2: colunas++;
                            predicoes = (char *) realloc(predicoes, colunas * sizeof(char));
                            predicoes[i] = c;
                            printf("%c", predicoes[i]);
                            i++;
                            break;
                }
            }else{
                todasColunas[j] = colunas;
                linhas++;
                colunas=0;
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
        modoDecalcular = (char *) realloc(modoDecalcular, (i+1) * sizeof(char));
        numeroDeVizinhos = (int *) realloc(numeroDeVizinhos, i * sizeof(int));
        raio = (float *) realloc(raio, i * sizeof(float));
    }
    printf("%c", arquivotreino[0]);
    
    FILE *arqtreino;
    arqtreino = fopen(arquivotreino, "r");
    if(arqtreino == NULL){
        printf("Erro");
        return 1;
    }
    i=0;
    j=0;
    char *f;
    while(fscanf(arqtreino, "%c", &*f)){
        if(*f != '\n'){
            colunasTreino++;
            matrizDeTreino[i] = (float *) realloc(matrizDeTreino[i], colunasTreino * sizeof(float));
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
    }

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