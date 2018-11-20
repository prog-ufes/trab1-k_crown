
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void troca(float *n, float *m){
    float aux;
    aux = *n;
    *n = *m;
    *m = aux;
}

void bubblesort(float vetor[], int n, float vetor2[]){
    int i, j;
    for (i = 0; i< n  - 1; i++){
        for (j = 0; j < n - i -1; j++){
            if (vetor[j] > vetor[j+1]){
                troca(&vetor[j], &vetor[j+1]);
                troca(&vetor2[j], &vetor2[j+1]);
            }
        }
    }
}

int main(){
    FILE *file = fopen("teste1.txt", "r"), *file2 = fopen("teste2.txt", "r");
    char *str = malloc(sizeof(char)*1000), *str2 = malloc(sizeof(char)*1000);
    if (file == NULL) {
    printf ("Erro na abertura de arquivo! Programa terminado...");
    exit (1);
    }
    int n = 0, linhas = 0, linhas2 = 0, i, quebra = 0, j = 0;
    // Calculo do numero de linhas
    while(!feof(file)){
        //fscanf(file, "%[^\n]", str);
        fgets(str, 1000, file);
        if( quebra == 0){
            for(i = 0; i < strlen(str); i++){
                if (str[i] == ','){
                    n++;
                }
            }
            quebra++;
        }
        linhas++;
    }
    while(!feof(file2)){
        fgets(str2, 1000, file2);
        linhas2++;
    }
    //retomar o arquivo para o inicio
    rewind(file2);
    rewind(file);
    //alocando memoria para a matriz de floats do arq 1
    float **vetor = malloc(sizeof(float*) * linhas);
    for (i = 0; i < linhas; i++){
        vetor[i] = malloc(sizeof(float)*(n+1));
    }
    //alocando memoria para a matriz de floats do arq 2
    float **vetor2 = malloc(sizeof(float*) * linhas2);
    for (i = 0; i < linhas2; i++){
        vetor2[i] = malloc(sizeof(float)*n);
    }
    //alocando memoria para o resultado da distancia
    float **vetor3 = malloc(sizeof(float*) * linhas2);
    for (i = 0; i < linhas; i++){
        vetor3[i] = malloc(sizeof(float)*linhas);
    }
    //alocando memoria para o rotulo do vetor;
    float **vetor4 = malloc(sizeof(float*) * linhas2);
    for (i = 0; i < linhas; i++){
        vetor4[i] = malloc(sizeof(float)*linhas);
    }
    //Quebrando a string em varias para converter o valores 1
    for (i = 0; i < linhas; i++){
        //fscanf(file, "%[^\n]", str);
        fgets(str, 1000, file);
        char *strnew = NULL;
        strnew = strtok(str, ",\n");
        while(strnew != NULL){
            vetor[i][j] = atof(strnew);
            strnew = strtok(NULL, ",\n");
            j++;
        }
        j = 0;
    }
    //Quebrando a string em varias para converter o valores 2
    for (i = 0; i < linhas2; i++){
        //fscanf(file, "%[^\n]", str);
        fgets(str2, 1000, file2);
        char *strnew2 = NULL;
        strnew2 = strtok(str2, ",\n");
        while(strnew2 != NULL){
            vetor2[i][j] = atof(strnew2);
            strnew2 = strtok(NULL, ",\n");
            j++;
        }
        j = 0;
    }
    // Colocando rotulos no vetor 4
    for (i = 0; i < linhas2; i++){
        //  printf("Rotulos vetor %d:\n", i+1);
        for (j = 0; j < linhas; j++){
            vetor4[i][j] = vetor[j][n];
            // printf("%.2f\n", vetor4[i][j]);
        }
    }

    // Distancia Euclidiana
    float soma = 0;
    for(i = 0; i < linhas2; i++){
        for(j = 0; j < linhas; j++){
            for (int k = 0; k < n; k++){
                soma = pow(vetor2[i][k] - vetor[j][k], 2) + soma;
            }
            vetor3[i][j] = sqrt(soma);
            soma = 0;
        }
    }
    // Vetor de distancias de cada ponto j em realção a estrela i
    // for (i = 0; i < linhas2; i++){
    //     printf("Vetor %d:\n", i+1);
    //     for (j = 0; j < linhas; j++){
    //         printf("%.2f ---- %.2f\n", vetor3[i][j], vetor4[i][j]);
    //     }
    // }
    //sorted
    for (i = 0; i < linhas2; i++){
        printf("Vetor %d:\n", i+1);
        bubblesort(vetor3[i], linhas, vetor4[i]);
        for (j = 0; j < linhas; j++){
            printf("%.2f ---- %.2f\n", vetor3[i][j], vetor4[i][j]);
        }
    }
    //Printando a matriz 1
    for(i = 0; i < linhas; i++){
        for (j = 0; j < n+1; j++)
            printf("%.2f ", vetor[i][j]);
        putchar('\n');
        free(vetor[i]);
    }
    puts("*****************************************");
    //Printando a matriz 2
    for(i = 0; i < linhas2; i++){
        for (j = 0; j < n; j++)
            printf("%.2f ", vetor2[i][j]);
        putchar('\n');
        free(vetor2[i]);
    }
    free(str);
    free(str2);
    free(vetor);
    free(vetor2);
    fclose(file);
    fclose(file2);
    return 0;

}