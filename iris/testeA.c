
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//Retorna a parte inteira do maior numero do vetor
int maior(float vetor[], int n){
    int maior;
    for (int i = 0; i < n; i++){
        if (i == 0){
            maior = vetor[i];
        }
        if (vetor[i] > maior){
            maior = vetor[i];
        }
    }
    return maior;
}
// Returna o indice do maior numero no vetor
int maiorindex(float vetor[], int n){
    float maior;
    int j = 0;
    for (int i = 0; i < n; i++){
        if (i == 0){
            maior = vetor[i];
        }
        if (vetor[i] > maior){
            maior = vetor[i];
            j = i;
        }
    }
    return j;
}

void troca(float *n, float *m){
    float aux;
    aux = *n;
    *n = *m;
    *m = aux;
}

void bubblesort(float vetor[], int n, float rotulo[]){
    int i, j;
    for (i = 0; i< n  - 1; i++){
        for (j = 0; j < n - i -1; j++){
            if (vetor[j] > vetor[j+1]){
                troca(&vetor[j], &vetor[j+1]);
                troca(&rotulo[j], &rotulo[j+1]);
                }
            if (vetor[j] == vetor[j+1] && rotulo[j] > rotulo[j+1]){
                troca(&rotulo[j], &rotulo[j+1]);
            }
        }
    }
}

int main(){
    char c, url[]="config.txt";
    int colunas=0, i=0, j=0, linha=0, *todasColunas;
    int y;

    todasColunas = (int *) malloc(1 * sizeof(int));

    FILE *arq;
    arq = fopen(url, "r");
    if(arq == NULL){
        printf("Erro");
        exit(1);
    }
    //Conta o número de linhas e colunas
    while(fread (&c, sizeof(char), 1, arq)) {
        if(c != '\n') {
            colunas++;
        }else{
            y = linha + 1;
            todasColunas = (int *) realloc(todasColunas, y * sizeof(int));
            if(linha<3){
                todasColunas[linhas] = colunas + 1;
                linha++;
                colunas = 0;
            }else{
                todasColunas[linhas] = colunas ;
                linha++;
                colunas = 0;
            }
        }
    
    }

    char *arquivotreino, *arquivoteste, *predicoes, *modoDecalcular;
    int *numeroDeVizinhos;
    float **kDistanciasMenores, *raio, **distancia, **somastreino, **somasteste, **somas, **multiplicacoes, **subtracoes, **rotulos;

    arquivotreino = (char *) malloc(todasColunas[0] * sizeof(char));
    arquivoteste = (char *) malloc(todasColunas[1] * sizeof(char));
    predicoes = (char *) malloc(todasColunas[2] * sizeof(char));
    modoDecalcular = (char *) malloc((linha - 2) * sizeof(char));
    numeroDeVizinhos = (int *) malloc((linha - 3) * sizeof(int));
    raio = (float *) malloc((linha - 3) * sizeof(float));
    
    rewind(arq);
    int linhas1 = 0;
    //Aloca os vetores de arquivos e de entradas
    while(linhas1<linha){
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
        printf("%i, %c, %.2f\n", numeroDeVizinhos[i], modoDecalcular[i], raio[i]);
    }
    putchar('\n');
    fclose(arq);

    FILE *file = fopen(arquivotreino, "r"), *file2 = fopen(arquivoteste, "r");
    float r = 0.5;
    char *str = malloc(sizeof(char)*1000), *str2 = malloc(sizeof(char)*1000);
    if (file == NULL) {
    printf ("Erro na abertura de arquivo! Programa terminado...");
    exit (1);
    }
    int n = 0, linhas = 0, linhas2 = 0, quebra = 0;
    j = 0;
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
    for (i = 0; i < linhas2; i++){
        vetor3[i] = malloc(sizeof(float)*linhas);
    }
    //alocando memoria para o rotulo do vetor;
    float **vetor4 = malloc(sizeof(float*) * linhas2);
    for (i = 0; i < linhas2; i++){
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
    // float soma = 0;
    // for(i = 0; i < linhas2; i++){
    //     for(j = 0; j < linhas; j++){
    //         for (int k = 0; k < n; k++){
    //             soma = pow(vetor2[i][k] - vetor[j][k], 2) + soma;
    //         }
    //         vetor3[i][j] = sqrt(soma);
    //         soma = 0;
    //     }
    // }
    // print vetor de distancias euclidianas de cada ponto j em realção a estrela i
    // for (i = 0; i < linhas2; i++){
    //     printf("Vetor %d:\n", i+1);
    //     for (j = 0; j < linhas; j++){
    //         printf("%.2f ---- %.2f\n", vetor3[i][j], vetor4[i][j]);
    //     }
    // }
    //sorted(Euclidiana)
    // for (i = 0; i < linhas2; i++){
    //     // printf("Vetor %d:\n", i+1);
    //     bubblesort(vetor3[i], linhas, vetor4[i]);
    //     for (j = 0; j < linhas; j++){
    //         // printf("%.2f ---- %.2f\n", vetor3[i][j], vetor4[i][j]);
    //     }
    // }
    //Distancia de Mikowski 
    // float soma = 0;
    // for(i = 0; i < linhas2; i++){
    //     for(j = 0; j < linhas; j++){
    //         for (int k = 0; k < n; k++){
    //             soma = pow(fabs(vetor2[i][k] - vetor[j][k]), r) + soma;
    //         }
    //         vetor3[i][j] = pow(soma, 1/r);
    //         soma = 0;
    //     }
    // }
    // print vetor de distancias mikowskianas de cada ponto j em realção a estrela i
    // for (i = 0; i < linhas2; i++){
    //     printf("Vetor %d:\n", i+1);
    //     for (j = 0; j < linhas; j++){
    //         printf("%.2f ---- %.2f\n", vetor3[i][j], vetor4[i][j]);
    //     }
    // }
    //sorted(Mikowskiana)
    // for (i = 0; i < linhas2; i++){
    //     printf("Vetor %d:\n", i+1);
    //     bubblesort(vetor3[i], linhas, vetor4[i]);
    //     for (j = 0; j < linhas; j++){
    //         printf("%.2f ---- %.2f\n", vetor3[i][j], vetor4[i][j]);
    //     }
    // }
    // Distancia de Chebyshev
    /*float max = 0;
    for(i = 0; i < linhas2; i++){
        for(j = 0; j < linhas; j++){
            for (int k = 0; k < n; k++){
                if (k == 0){
                max = fabs(vetor2[i][k] - vetor[j][k]);
                }
                if (fabs(vetor2[i][k] - vetor[j][k]) > max){
                    max = fabs(vetor2[i][k] - vetor[j][k]);
                }
            }
            vetor3[i][j] = max;
        }
    }*/
    //print vetor de distancias chebyshevianas de cada ponto j em realção a estrela i
    // for (i = 0; i < linhas2; i++){
    //     printf("Vetor %d:\n", i+1);
    //     for (j = 0; j < linhas; j++){
    //         printf("%.2f ---- %.2f\n", vetor3[i][j], vetor4[i][j]);
    //     }
    // }
    //sorted Chebyshev
    /*for (i = 0; i < linhas2; i++){
        printf("Vetor %d:\n", i+1);
        bubblesort(vetor3[i], linhas, vetor4[i]);
        for (j = 0; j < linhas; j++){
            printf("%.2f ---- %.2f\n", vetor3[i][j], vetor4[i][j]);
        }
    }*/
    // k primeiros
    int k = 8, nrotulos, aux;
    nrotulos = maior(vetor4[0], linhas);
    float **vetoraux = malloc(sizeof(float*)*linhas2), *rotulos = malloc(sizeof(float)*linhas2);
    for(i = 0; i < linhas2; i++){
        vetoraux[i] = malloc(sizeof(float)*nrotulos);
    }

    for (i = 0; i < linhas2; i++){
        for (j = 0; j < k; j++){
            aux = vetor4[i][j] - 1;
            vetoraux[i][aux]++;
        }
        rotulos[i] = maiorindex(vetoraux[i], nrotulos);
    }
    for (i = 0; i < linhas2; i++){
        printf("%.2f\n", rotulos[i]);
    }
    //Comparando rotulos descobertos com rotulos testes
    float correto = 0;
    for (i = 0; i < linhas2; i++){
        if (( rotulos[i] + 1) == vetor2[i][n])
            correto++;
    }
    printf("====%d==== -> %.2f\n", (int) correto, correto*100/linhas2);
    //Printando a matriz 1
    // for(i = 0; i < linhas; i++){
        // for (j = 0; j < n+1; j++){
        //      printf("%.2f ", vetor[i][j]);
        // }
        //  putchar('\n');
    // }
    puts("*****************************************");
    //Printando a matriz 2
    // for(i = 0; i < linhas2; i++){
        // for (j = 0; j < n; j++){
        //     printf("%.2f ", vetor2[i][j]);
        // }
        // putchar('\n');
    // }
    //liberando memoria
    for(i = 0; i < linhas; i++){   
        free(vetor[i]);
    }

    for(i = 0; i < linhas2; i++){
        free(vetor2[i]);
        free(vetor3[i]);
        free(vetor4[i]);
        free(vetoraux[i]);
    }
    free(str);
    free(str2);
    free(vetor);
    free(vetor2);
    free(vetor3);
    free(vetor4);
    free(vetoraux);
    free(rotulos);
    fclose(file);
    fclose(file2);
    return 0;

}