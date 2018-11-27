/* *********** T r a b a l h o  d e  P r o g r a m a ç ã o II ***********
    Professor da Disciplina: Jordana Salamon
    Monitor da Disciplina: André Pacheco
    Membros da dupla: Philipe Marques && André Neves
    2 0 1 8 / 2
   ********************************************************************** */
                                                        
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
// Retorna o indice do maior numero no vetor
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
        }
    }
}

int main(){
    FILE *config = fopen("config.txt", "r");
    char *pathteste = malloc(sizeof(char)*500), *pathtreino = malloc(sizeof(char)*500),
    *pathsaida = malloc(sizeof(char)*50), *pathaux = malloc(sizeof(char)*50);
    if (config == NULL) {
        printf ("Erro na abertura do arquivo config\n");
        exit (1);
    }
    fscanf(config, "%s", pathtreino);
    // printf("%s\n", pathtreino);
    fscanf(config, "%s", pathteste);
    // printf("%s\n", pathteste);
    FILE *filetreino = fopen(pathtreino, "r"), *fileteste = fopen(pathteste, "r");
    if (filetreino == NULL) {
        printf ("Erro na abertura de arquivo treino\n");
        exit (1);
        }
    if (fileteste == NULL) {
        printf ("Erro na abertura do arquivo teste\n");
        exit (1);
        }
    char lixoc;
    int  linhas_treino = 0, linhas_teste = 0;
    /* Calculo do numero de linhas_treino de treino */
    while(!feof(filetreino)){
        fscanf(filetreino, "%c,", &lixoc);
        if (lixoc == '\n'){
            linhas_treino++;
        }
    }
    rewind(filetreino);
    /* Calculo do numero de linhas_treino teste */
    while(!feof(fileteste)){
        fscanf(fileteste, "%c,", &lixoc);
        if (lixoc == '\n'){
            linhas_teste++;
        }
    }
    rewind(fileteste);
    fscanf(config, "%s", pathsaida);
    strcpy(pathaux, pathsaida);
    int loop = 0;
    while(!feof(config)){
        int k_proximos;
        float r;
        /* Alocando memoria para conter o local de saida do arquivo */
        char *conv = malloc(sizeof(char)*30), numero[20], tipod;
        fscanf(config, "%d, %c,", &k_proximos, &tipod);
        if (k_proximos == -1){
            break;
        }
        strcpy(pathsaida,pathaux);
        strcpy(conv,"predicao_");
        sprintf(numero, "%d", loop + 1);
        strcat(conv, numero);
        strcat(conv, ".txt");
        strcat(pathsaida, conv);
        free(conv);
        FILE *saida = fopen(pathsaida, "w");
        if (saida == NULL) {
            printf("Erro na escrita do arquivo de saida\n");
            exit (1);
        }
        float lixo;
        int nvirgulas = 0, i, j = 0;

        do {
            fscanf(filetreino, "%c", &lixoc);
            if (lixoc == ','){
                nvirgulas++;
            }
        }
        while(lixoc != '\n');
        printf("%d -- %d --- %d\n", linhas_treino, linhas_teste, nvirgulas);
        rewind(filetreino);
        /* Alocando memoria para a matriz de floats do arq treino */
        float **vetor_treino = malloc(sizeof(float*) * linhas_treino);
        for (i = 0; i < linhas_treino; i++){
            vetor_treino[i] = malloc(sizeof(float)*(nvirgulas+1));
        }
        /* Alocando memoria para a matriz de floats do arq teste */
        float **vetor_teste = malloc(sizeof(float*) * linhas_teste);
        for (i = 0; i < linhas_teste; i++){
            vetor_teste[i] = malloc(sizeof(float)*(nvirgulas + 1));
        }
        /* Alocando memoria para os resultado das distancias */
        float **distancias = malloc(sizeof(float*) * linhas_teste);
        for (i = 0; i < linhas_teste; i++){
            distancias[i] = malloc(sizeof(float)*linhas_treino);
        }
        /* Alocando memoria para a matriz de rotulos do vetor_treino */
        float **rotulos_treino = malloc(sizeof(float*) * linhas_teste);
        for (i = 0; i < linhas_teste; i++){
            rotulos_treino[i] = malloc(sizeof(float)*linhas_treino);
        }
        /* Colocando valores no vetor de treino */
        for(i = 0; i < linhas_treino; i++){
            for (j = 0; j < nvirgulas+1; j++){
                fscanf(filetreino, "%f,", &vetor_treino[i][j]);
            }
        }
        /* printar o vetor_treino de treino */
        // for(i = 0; i < linhas_treino; i++){
        //     for (j = 0; j < nvirgulas+1; j++){
        //         printf("%.2f ", vetor_treino[i][j]);
        //     }
        //     putchar('\n');
        // }

        /* Colocando valores no vetor de teste */
        for(i = 0; i < linhas_teste; i++){
            for (j = 0; j < nvirgulas+1; j++){
                fscanf(fileteste, "%f,", &vetor_teste[i][j]);
            }
        }

        /* Printar o vetor de teste */
        // for(i = 0; i < linhas_teste; i++){
        //     for (j = 0; j < nvirgulas+1; j++){
        //         printf("%.2f ", vetor_teste[i][j]);
        //     }
        //     putchar('\n');
        // }

        /* Colocando rotulos no vetor de rotulos */
        for (i = 0; i < linhas_teste; i++){
            //  printf("Rotulos vetor_treino %d:\n", i+1);
            for (j = 0; j < linhas_treino; j++){
                rotulos_treino[i][j] = vetor_treino[j][nvirgulas];
            }
        }

        /* Distancia Euclidiana */
        if (tipod == 'E'){
            float soma = 0, subtracao;
            for(i = 0; i < linhas_teste; i++){
                for(j = 0; j < linhas_treino; j++){
                    for (int k = 0; k < nvirgulas; k++){
                        subtracao = vetor_teste[i][k] - vetor_treino[j][k];
                        subtracao = subtracao * subtracao;
                        soma = subtracao + soma;
                    }
                    distancias[i][j] = sqrt(soma);
                    soma = 0;
                }
            }

        /* Print vetor de distancias euclidianas de cada ponto j em realção a estrela i */
        // for (i = 0; i < linhas_teste; i++){
        //     printf("Vetor %d:\n", i+1);
        //     for (j = 0; j < linhas_treino; j++){
        //         printf("%.2f ---- %.2f\n", distancias[i][j], rotulos_treino[i][j]);
        //     }
        // }

        /* Sorted(Euclidiana) */
            for (i = 0; i < linhas_teste; i++){
                // printf("Vetor %d:\n", i+1);
                bubblesort(distancias[i], linhas_treino, rotulos_treino[i]);
                for (j = 0; j < linhas_treino; j++){
                    // printf("%.2f ---- %.2f\n", distancias[i][j], rotulos_treino[i][j]);
                }
            }
        } 

        /*Distancia de Mikowski */ 
        if (tipod == 'M'){
            fscanf(config, "%f", &r);
            float soma = 0;
            for(i = 0; i < linhas_teste; i++){
                for(j = 0; j < linhas_treino; j++){
                    for (int k = 0; k < nvirgulas; k++){
                        soma = pow(fabs(vetor_teste[i][k] - vetor_treino[j][k]), r) + soma;
                    }
                    distancias[i][j] = pow(soma, 1/r);
                    soma = 0;
                }
            }

        /* Print vetor de distancias mikowskianas de cada ponto j em realção a estrela i */
        // for (i = 0; i < linhas_teste; i++){
        //     printf("Vetor %d:\n", i+1);
        //     for (j = 0; j < linhas_treino; j++){
        //         printf("%.2f ---- %.2f\n", distancias[i][j], rotulos_treino[i][j]);
        //     }
        // }

        /* Sorted(Mikowskiana) */
            for (i = 0; i < linhas_teste; i++){
                // printf("Vetor %d:\n", i+1);
                bubblesort(distancias[i], linhas_treino, rotulos_treino[i]);
                for (j = 0; j < linhas_treino; j++){
                    // printf("%.2f ---- %.2f\n", distancias[i][j], rotulos_treino[i][j]);
                }
            }
        }

        /* Distancia de Chebyshev */
        if (tipod == 'C'){
            float max;
            for(i = 0; i < linhas_teste; i++){
                for(j = 0; j < linhas_treino; j++){
                    for (int k = 0; k < nvirgulas; k++){
                        if (k == 0){
                        max = fabs(vetor_teste[i][k] - vetor_treino[j][k]);
                        }
                        if (fabs(vetor_teste[i][k] - vetor_treino[j][k]) > max){
                            max = fabs(vetor_teste[i][k] - vetor_treino[j][k]);
                        }
                    }
                    distancias[i][j] = max;
                }
            }

        /* Print vetor de distancias chebyshevianas de cada ponto j em realção a estrela i */
        // for (i = 0; i < linhas_teste; i++){
        //     printf("Vetor %d:\n", i+1);
        //     for (j = 0; j < linhas_treino; j++){
        //         printf("%.2f ---- %.2f\n", distancias[i][j], rotulos_treino[i][j]);
        //     }
        // }

        /* Sorted(Chebysheviana) */
            for (i = 0; i < linhas_teste; i++){
                // printf("Vetor %d:\n", i+1);
                bubblesort(distancias[i], linhas_treino, rotulos_treino[i]);
                // for (j = 0; j < linhas_treino; j++){
                //     // printf("%.2f ---- %.2f\n", distancias[i][j], rotulos_treino[i][j]-1);
                // }
            }
        }

        /* k primeiros e calculo de rotulos */
        int nrotulos, aux;
        nrotulos = maior(rotulos_treino[0], linhas_treino);
        float **vetoraux = calloc(linhas_teste,sizeof(float*)), *rotulos = malloc(sizeof(float)*linhas_teste);
        for(i = 0; i < linhas_teste; i++){
            vetoraux[i] = calloc(nrotulos,sizeof(float));
        }
        for (i = 0; i < linhas_teste; i++){
            for (j = 0; j < k_proximos; j++){
                aux = rotulos_treino[i][j] - 1;
                vetoraux[i][aux]++;
            }
            rotulos[i] = maiorindex(vetoraux[i], nrotulos);
        }
        // for (i = 0; i < linhas_teste; i++){
        //     printf("%.2f\n", rotulos[i]);
        // }

        /* Alocando memoria para a matriz de confusão */
        int **confusao = malloc(sizeof(int*)*nrotulos);
        for (i = 0; i < nrotulos; i++){
            confusao[i] = malloc(sizeof(int)*nrotulos);
        }for(i = 0; i < nrotulos; i++){
            for(j = 0; j < nrotulos; j++){
                confusao[i][j] = 0;
            }
        }

        /* Comparando rotulos descobertos com rotulos testes */
        float correto = 0;
        for (i = 0; i < linhas_teste; i++){
            // printf("%.2f -- %.2f\n", rotulos[i], vetor_teste[i][n]-1);
            confusao[(int)vetor_teste[i][nvirgulas]-1][(int) rotulos[i]]++;
            // confusao[(int) rotulos[i]][(int)vetor_teste[i][n]-1]++;
            if (( rotulos[i] + 1) == vetor_teste[i][nvirgulas])
                correto++;
        }

        /* Printando no arquivo de saída */
        fprintf(saida, "%.2f\n\n",correto/linhas_teste);
        // printf("%.2f\n",correto/linhas_teste);
        for(i = 0; i < nrotulos; i++){
            for(j = 0; j < nrotulos; j++){
                fprintf(saida,"%d ", confusao[i][j]);
                //printf("%d ", confusao[i][j]);

            }
            fputc('\n', saida);
            // putchar('\n');
        }
        fputc('\n', saida);
        for (i = 0; i < linhas_teste; i++){
            fprintf(saida,"%d\n", (int) rotulos[i]);
            // printf("%d\n", (int) rotulos[i] );
        }

        /* Printando a matriz treino */
        // for(i = 0; i < linhas_treino; i++){
        //     for (j = 0; j < n+1; j++){
        //          printf("%.2f ", vetor_treino[i][j]);
        //     }
        //      putchar('\n');
        // }

        /* Printando a matriz teste */
        // for(i = 0; i < linhas_teste; i++){
        //     for (j = 0; j < n; j++){
        //         printf("%.2f ", vetor_teste[i][j]);
        //     }
        //     putchar('\n');
        // }

        /* Liberando memoria das matrizes*/
        for(i = 0; i < linhas_treino; i++){   
            free(vetor_treino[i]);
        }

        for(i = 0; i < linhas_teste; i++){
            free(vetor_teste[i]);
            free(distancias[i]);
            free(rotulos_treino[i]);
            free(vetoraux[i]);
        }
        for(i = 0; i < nrotulos; i++){   
            free(confusao[i]);
        }
    /* Liberando a memoria */
        free(vetor_treino);
        free(vetor_teste);
        free(distancias);
        free(rotulos_treino);
        free(confusao);
        free(vetoraux);
        free(rotulos);
        rewind(filetreino);
        rewind(fileteste);
        fclose(saida);
        printf("**** %d arquivo conlcuido.\n", loop + 1);
        loop++;
        k_proximos = -1;
        }
    free(pathtreino);
    free(pathteste);
    free(pathsaida);
    free(pathaux);
    fclose(filetreino);
    fclose(fileteste);
    fclose(config);
}