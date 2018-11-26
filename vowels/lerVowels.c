#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){

    char  url[] = "dataset/vowels_treino.csv", url1[] = "dataset/vowels_teste.csv", c;
    float **matriztreino, **matrizteste, f;
    int i, j, linhastreino=0, colunas=0, linhasteste=0, *todascolunastreino, *todascolunasteste;

    todascolunastreino = (int *) malloc(1 * sizeof(int));
    todascolunasteste = (int *) malloc(1 * sizeof(int));

    FILE *treino;
    treino = fopen(url, "r");
    if(treino == NULL){
        printf("Erro!");
        exit (1);
    }
    while(!feof(treino)){
        fscanf(treino, "%f%c", &f, &c);
        if(c != '\n'){
            colunas++;
        }else{
            todascolunastreino = (int *) realloc(todascolunastreino, (linhastreino+1) * sizeof(int));
            todascolunastreino[linhastreino] = colunas;
            linhastreino++;
            colunas = 0;
        }
    }
    colunas=0;

    rewind(treino);

    matriztreino = (float **) malloc(linhastreino * sizeof(float *));
    for(i=0; i<(linhastreino-1); i++){
        matriztreino[i] = (float *) malloc(todascolunastreino[i] * sizeof(float));
    }
    for(i=0; i<(linhastreino-1); i++){
        for(j=0; j<todascolunastreino[i]; j++){
            fscanf(treino, "%f%c", &matriztreino[i][j], &c);
        }
    }
    colunas=0;
    FILE *teste;
    teste = fopen(url1, "r");
    if(teste == NULL){
        printf("Erro!");
        exit (1);
    }
    while(!feof(teste)){
        fscanf(teste, "%f%c", &f, &c);
        if(c != '\n'){
            colunas++;
        }else{
            todascolunasteste = (int *) realloc(todascolunasteste, (linhasteste+1) * sizeof(int));
            todascolunasteste[linhasteste] = colunas;
            linhasteste++;
            colunas = 0;
        }
    }

    rewind(teste);

    matrizteste = (float **) malloc(linhasteste * sizeof(float *));
    for(i=0; i<linhasteste; i++){
        matrizteste[i] = (float *) malloc(todascolunasteste[i] * sizeof(float));
    }
    for(i=0; i<(linhasteste-1); i++){
        for(j=0; j<todascolunasteste[i]; j++){
            fscanf(teste, "%f%c", &matrizteste[i][j], &c);
        }
    }

    for(i=0; i<(linhastreino-1); i++){
        for(j=0; j<todascolunastreino[i]; j++){
            printf("%f ", matriztreino[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    for(i=0; i<(linhasteste-1); i++){
        for(j=0; j<todascolunasteste[i]; j++){
            printf("%f ", matrizteste[i][j]);
        }
        printf("\n");
    }

    free(todascolunasteste);
    free(todascolunastreino);

    for(i=0; i<linhasteste; i++){
        free(matrizteste[i]);
    }
    free(matrizteste);

    for(i=0; i<linhastreino; i++){
        free(matriztreino[i]);
    }
    free(matriztreino);

    return 0;
}