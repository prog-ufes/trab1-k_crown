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

    char c, tipo, url1[]="iris/config.txt", url2[]="vowels/config.txt";
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

    printf("Escolha o tipo a ser analizado (i-iris/ v-vowels): ");
    scanf(" %c", &tipo);

    FILE *arq;
    if(tipo == 'i'){
        arq = fopen(url1, "r");
    }else{
        arq = fopen(url2, "r");
    }
    if(arq == NULL){
        printf("Erro");
        exit(1);
    }

    while(fread (&c, sizeof(char), 1, arq)) {
        if(c != '\n') {
            colunas++;
        }else{
            n = linhas + 1;
            todasColunas = (int *) realloc(todasColunas, n * sizeof(int));
            if(linhas<3){
                todasColunas[linhas] = colunas + 1;
                linhas++;
                colunas = 0;
            }else{
                todasColunas[linhas] = colunas ;
                linhas++;
                colunas = 0;
            }
        }
    
    }

    char *arquivoteste1, *arquivotreino1, *predicoes1, *modoDecalcular;
    int *numeroDeVizinhos;
    float *raio;

    arquivotreino1 = (char *) malloc(todasColunas[0] * sizeof(char));
    arquivoteste1 = (char *) malloc(todasColunas[1] * sizeof(char));
    predicoes1 = (char *) malloc(todasColunas[2] * sizeof(char));
    modoDecalcular = (char *) malloc((linhas - 2) * sizeof(char));
    numeroDeVizinhos = (int *) malloc((linhas - 3) * sizeof(int));
    raio = (float *) malloc((linhas - 3) * sizeof(float));
    
    rewind(arq);
    int linhas1 = 0;
    //Aloca os vetores de arquivos e de entradas
    while(linhas1<linhas){
        while(fread (&c, sizeof(char), 1, arq) && linhas1 <3){
            if(c != '\n'){
                switch(linhas1){
                    case 0: arquivotreino1[i] = c;
                            i++;
                            break;
                    case 1: arquivoteste1[i] = c;                            
                            i++;
                            break;
                    case 2: predicoes1[i] = c;                           
                            i++;
                            break;
                }
            }else{
                linhas1++;
                i=0;
            }
        }
        if(linhas1 == 3){
            numeroDeVizinhos[i] = c -'0';
            fscanf(arq, " , %c", &modoDecalcular[i]);
            if(modoDecalcular[i] == 'M'){
            fscanf(arq, ", %f", &raio[i]);
            }else{
                raio[i]=0;
            }
            i++;
            linhas1++;
        }else{
            fscanf(arq, "%i, %c", &numeroDeVizinhos[i], &modoDecalcular[i]);
            if(modoDecalcular[i] == 'M'){
                fscanf(arq, ", %f", &raio[i]);
            }else{
                raio[i]=0;
            }
            i++;
            linhas1++;
        }
    }
    char *arquivotreino, *arquivoteste, *predicoes;
    if(tipo=='i'){
        arquivotreino = (char *) malloc((todasColunas[0] + 5) * sizeof(char));
        strcpy(arquivotreino, "iris/");
        arquivoteste = (char *) malloc((todasColunas[1] + 5) * sizeof(char));
        strcpy(arquivoteste, "iris/");
        predicoes = (char *) malloc((todasColunas[2] + 5) * sizeof(char));
        strcpy(predicoes, "iris/");
        strcat(arquivotreino, arquivotreino1);
        strcat(arquivoteste, arquivoteste1);
        strcat(predicoes, predicoes1);

    }else{
        arquivotreino = (char *) malloc((todasColunas[0] + 7) * sizeof(char));
        strcpy(arquivotreino, "vowels/");
        arquivoteste = (char *) malloc((todasColunas[1] + 7) * sizeof(char));
        strcpy(arquivoteste, "vowels/");
        predicoes = (char *) malloc((todasColunas[2] + 7) * sizeof(char));
        strcpy(predicoes, "vowels/");
        strcat(arquivotreino, arquivotreino1); 
        strcat(arquivoteste, arquivoteste1); 
        strcat(predicoes, predicoes1); 
    }
        
    for(i=0; i<strlen(arquivotreino); i++){
        printf("%c", arquivotreino[i]);
    }
    printf("\n");
    for(i=0; i<strlen(arquivoteste); i++){
        printf("%c", arquivoteste[i]);
    }
    printf("\n");
    for(i=0; i<strlen(predicoes); i++){
        printf("%c", predicoes[i]);
    }
    printf("\n");
    for(i=0; i<(linhas-3); i++){
        printf("%i, %c, %f\n", numeroDeVizinhos[i], modoDecalcular[i], raio[i]);
    }
    fclose(arq);

    free(todasColunas);

    free(arquivoteste1);
    free(arquivotreino1);
    free(predicoes1);
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