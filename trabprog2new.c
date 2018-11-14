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

    char c;
    int colunas=0, i=0, j=0, linhas=0, colunasTeste=0, colunasTreino=0, linhasTeste=0, linhasTreino=0, *todasColunas;
    float **matrizDeTeste, **matrizDeTreino;
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
                todasColunas[linhas] = colunas + 1;
                linhas++;
                colunas = 0;
                }else{
                    n = linhas + 1;
                    todasColunas = (int *) realloc(todasColunas, n * sizeof(int));
                    if(linhas<3){
                        todasColunas[linhas] = colunas + 1;
                    }else{
                        todasColunas[linhas] = colunas ;
                    }
                    linhas++;
                    colunas = 0;
                }
    
    }

    char *arquivoteste, *arquivotreino, *predicoes, *modoDecalcular;
    int *numeroDeVizinhos;
    float *raio;

    arquivotreino = (char *) malloc(todasColunas[0] * sizeof(char));
    arquivoteste = (char *) malloc(todasColunas[1] * sizeof(char));
    predicoes = (char *) malloc(todasColunas[2] * sizeof(char));
    modoDecalcular = (char *) malloc((linhas - 2) * sizeof(char));
    numeroDeVizinhos = (int *) malloc((linhas - 2) * sizeof(int));
    raio = (float *) malloc((linhas - 2) * sizeof(float));
    
    rewind(arq);
    int linhas1 = 0;
    //Aloca os vetores de arquivos e de entradas
    while(!feof(arq)){
        while(fread (&c, sizeof(char), 1, arq) && linhas1 <3){
            if(c != '\n'){
                switch(linhas1){
                    case 0: arquivotreino[i] = c;
                            i++;
                            break;
                    case 1: arquivoteste[i] = c;                            
                            i++;
                            break;
                    case 2: predicoes[i] = c;                           
                            i++;
                            break;
                }
            }else{
                linhas1++;
                i=0;
            }
        }
        fscanf(arq, "%i, %c", &numeroDeVizinhos[i], &modoDecalcular[i]);
        if(modoDecalcular[i] == 'M'){
            fscanf(arq, ", %f", &raio[i]);
        }else{
            raio[i]=0;
        }
        i++;
    }
    for(i=0; i<todasColunas[0]; i++){
        printf("%c", arquivotreino[i]);
    }
    printf("\n");
    for(i=0; i<todasColunas[1]; i++){
        printf("%c", arquivoteste[i]);
    }
    printf("\n");
    for(i=0; i<todasColunas[2]; i++){
        printf("%c", predicoes[i]);
    }
    printf("\n");
    for(i=0; i<(linhas-2); i++){
        printf("%i, %c, %f\n", numeroDeVizinhos[i], modoDecalcular[i], raio[i]);
    }
    
    int y;
    FILE *arqtreino;
    arqtreino = fopen(arquivotreino, "r");
    if(arqtreino == NULL){
        printf("Erro");
        return 1;
    }
    while(fread (&c, sizeof(char), 1, arqtreino)) {
            if(c != '\n') {
                colunasTreino++;
            }else{
                y = colunasTreino;
                linhasTreino++;
                colunasTreino = 0;
            }
    
    }
    printf("%i ", linhasTreino);
    printf("%i ", y);

    rewind(arqtreino);
    matrizDeTreino = (float **) realloc(matrizDeTreino, linhasTreino * sizeof(float *));
    for(i=0; i<linhasTeste; i++){
        matrizDeTreino[i] = (float *) realloc(matrizDeTreino[i], y * sizeof(float));
    }
    i=0;
    j=0;
    while(i<linhasTreino){
        fscanf(arqtreino, "%f%c", &matrizDeTreino[i][j], &c);
        printf("%f ", matrizDeTreino[i][j]);
        while(c!='\n'){
            j++;
            fscanf(arqtreino, " %f%c", &matrizDeTreino[i][j], &c);
            printf("%f ", matrizDeTreino[i][j]);
        }
        printf("\n");
        i++;
        j=0;
    }

    int w;
    FILE *arqteste;
    arqteste = fopen(arquivoteste, "r");
    if(arqteste == NULL){
        printf("Erro");
        return 1;
    }
    while(fread (&c, sizeof(char), 1, arqteste)) {
            if(c != '\n') {
                colunasTeste++;
            }else{
                w = colunasTeste;
                linhasTeste++;
                colunasTeste = 0;
            }
    
    }

    rewind(arqteste);
    matrizDeTeste = (float **) realloc(matrizDeTeste, linhasTeste * sizeof(float *));
    for(i=0; i<linhasTeste; i++){
        matrizDeTeste[i] = (float *) realloc(matrizDeTeste[i], w * sizeof(float));
    }
    i=0;
    j=0;
    while(i<linhasTeste){
        fscanf(arqteste, "%f%c", &matrizDeTeste[i][j], &c);
        printf("%f ", matrizDeTeste[i][j]);
        while(c!='\n'){
            j++;
            fscanf(arqteste, " %f%c", &matrizDeTeste[i][j], &c);
            printf("%f ", matrizDeTeste[i][j]);
        }
        printf("\n");
        i++;
        j=0;
    }

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