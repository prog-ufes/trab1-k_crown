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
    int *numeroDeVizinhos, tamanho[3], colunas, i, j, linhas=0, tamanhovet;
    float *raio;

    FILE *arq;
    arq = fopen("iris/config.txt", "r");
    if(arq == NULL){
        printf("Erro");
        return 1;
    }

    arquivotreino = (char *) malloc(2 * sizeof(char));
    arquivoteste = (char *) malloc(2 * sizeof(char));
    predicoes = (char *) malloc(2 * sizeof(char));
    numeroDeVizinhos = (int *) malloc(1 * sizeof(int));
    raio = (float *) malloc(1 * sizeof(float));
    modoDecalcular = (char *) malloc(2 * sizeof(char));

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
                linhas++;
                colunas=0;
                i=0;
                printf("\n");
            }
        }
        i=0;
        fscanf(arq, "%i, %c", &numeroDeVizinhos[i], &modoDecalcular[i]);
        printf("%i\n", numeroDeVizinhos[i]);
        printf("%c\n", modoDecalcular[i]);
        if(modoDecalcular[i] == 'M'){
            fscanf(arq, ", %f", &raio[i]);
        }else{
            raio[i] = 0;
        }
        printf("%i, %c, %f\n", numeroDeVizinhos[i], modoDecalcular[i], raio[i]);
        i++;
        modoDecalcular = (char *) realloc(modoDecalcular, (i+2) * sizeof(char));
        numeroDeVizinhos = (int *) realloc(numeroDeVizinhos, (i+1) * sizeof(int));
        raio = (float *) realloc(raio, (i+1) * sizeof(float));
    }

    free(arquivoteste);
    free(arquivotreino);
    free(predicoes);
    free(modoDecalcular);
    free(numeroDeVizinhos);
    free(raio);

    return 0;
}