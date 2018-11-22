#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void subtracao(float **Amostra, float **Vizinhos, float **subtracoes, int linhasamostras, int linhasVizinhos, int colunasVizinhos){
    int i=0, j=0, l=0, m=0;
    while(l<linhasamostras){
        while(i<linhasVizinhos){
            while(j<(colunasVizinhos-1)){
                subtracoes[m][j] = Amostra[l][j] - Vizinhos[i][j];
                j++;
            }
            subtracoes[m][j] = Vizinhos[i][j];
            m++;
            i++;
            j=0;
        }
        l++;
        i=0;
        j=0;
    }
}

void subtracaovet(float **Amostra, float **Vizinhos, float **subtracoes, int linhasamostras, int linhasVizinhos){
    int i=0, j=0, l=0, m=0;
    while(l<linhasamostras){
        while(i<linhasVizinhos){
            while(j<1){
                subtracoes[m][j] = Amostra[l][j] - Vizinhos[i][j];
                j++;
            }
            subtracoes[m][j] = Vizinhos[i][j];
            m++;
            i++;
            j=0;
        }
        l++;
        i=0;
        j=0;
    }
}

void subtracaomodulo(float **Amostra, float **Vizinhos, float **subtracoes, int linhasamostras, int linhasVizinhos, int colunasVizinhos){
    int i=0, j=0, l=0, m=0;
    while(l<linhasamostras){
        while(i<linhasVizinhos){
            while(j<(colunasVizinhos-1)){
                subtracoes[m][j] = abs(Amostra[l][j] - Vizinhos[i][j]);
                j++;
            }
            subtracoes[m][j] = Vizinhos[i][j];
            m++;
            i++;
            j=0;
        }
        l++;
        i=0;
        j=0;
    }
}


void multiplicacao(float **Entrada, float **multiplicacoes, int linhasamostras, int linhasVizinhos, int colunasVizinhos, float n){
    int i, j;
    for(i=0; i<(linhasamostras * linhasVizinhos); i++){
        for(j=0; j<(colunasVizinhos-1); j++){
            multiplicacoes[i][j] = pow(Entrada[i][j],n);
        }
        multiplicacoes[i][j] = Entrada[i][j];
    }
}

void soma(float **Entrada, float **Saida, int linhasamostras, int linhasVizinhos, int colunasVizinhos){
    int i, j, k=0;
    for(i=0; i<(linhasamostras * linhasVizinhos); i++){
        for(j=0; j<2; j++){
            Saida[i][j] = 0;
        }
    }
    for(i=0; i<(linhasamostras * linhasVizinhos); i++){
        for(j=0; j<(colunasVizinhos-1); j++){
            Saida[i][k] = Saida[i][k] + Entrada[i][j];
        }
        k++;
        Saida[i][k] = Entrada[i][j];
        k=0;
    }
}

void somamat(float **Entrada, float **Saida, int linhasamostras, int colunasVizinhos){
    int i, j, k=0;
    for(i=0; i<linhasamostras; i++){
        for(j=0; j<2; j++){
            Saida[i][j] = 0;
        }
    }
    for(i=0; i<linhasamostras; i++){
        for(j=0; j<(colunasVizinhos-1); j++){
            Saida[i][k] = Saida[i][k] + Entrada[i][j];
        }
        k++;
        Saida[i][k] = Entrada[i][j];
        k=0;
    }
}

void multiplicacaovet(float **Entrada, float **multiplicacoes, int linhasamostras, int linhasVizinhos, float n){
    int i, j=0;
    for(i=0; i<(linhasamostras * linhasVizinhos); i++){
        multiplicacoes[i][j] = pow(Entrada[i][j],n);
        j++;
        multiplicacoes[i][j] = Entrada[i][j];
        j=0;
    }
}

void troca(float *n, float *m){
    float aux;
    aux = *n;
    *n = *m;
    *m = aux;
}

void bubblesort(float **vetor, int n, int w){
    int i, j;
    for (j = 0; j< n  - 1; j++){
        for (i = w; i < n - j -1; i++){
            if (vetor[i][0] > vetor[i+1][0]){
                troca(&vetor[i][0], &vetor[i+1][0]);
                troca(&vetor[i][1], &vetor[i+1][1]);
            }
        }
    }
}

void bubblesortmat(float **matriz, int n, int linhasteste, int linhastreino){
    int i, j, k;
    for(k=0; k<(linhastreino * linhasteste); k++){
        for (i = 0; i< n  - 1; i++){
            for (j = 0; j < n - i -1; j++){
                if (matriz[k][j] > matriz[k][j+1]){
                    troca(&matriz[k][j], &matriz[k][j+1]);
                }
            }
        }
    }
}

void kmenores(int k, float **distancias, float **kDistanciasMenores,int linhasTeste, int linhasTreino){
    int i, j, l=0;

    kDistanciasMenores = (float **) malloc(k * linhasTeste * sizeof(float*));
    for(i=0; i<(k * linhasTeste); i++){
        kDistanciasMenores[i] = (float *) malloc(2 * sizeof(float));
    }

    for(i=0; i<linhasTeste ; i++){
        for(j=0; (j + i*linhasTreino)<(k + i*linhasTreino); j++){
            kDistanciasMenores[j][0] = distancias[l][0];
            kDistanciasMenores[j][1] = distancias[l][1];
            l++;
        }
    }
}

void matrizrotulos(int linhasTeste, int linhasTreino, float **kDistanciasMenores, float **rotulos){
    int i=0, j, k=0;
    rotulos = (float **) malloc(linhasTeste * sizeof(float *));
    for(i=0; i<linhasTeste; i++){
        rotulos[i] = (float *) malloc(linhasTreino * sizeof(float));
    }
    while(i<(linhasTeste * linhasTreino)){
        for(j=0; j<linhasTreino; j++){
            rotulos[k][j] = kDistanciasMenores[i][1];
            i++;
        }
        k++;
    }
}


void maioresmat(int linhasTeste, int linhasTreino, int n, float **subtracoes, float **distancias){
    int i. j;
    for(i=0; i<(linhasTeste * linhasTreino); i++){
        distancias[i][0] = subtracoes[i][n-2];
        distancias[i][1] = subtracoes[i][n-1];
    }
}

int main(){

    float **treino, **teste, r, **distancia, **somastreino, **somasteste, **somas, **multiplicacoes, **subtracoes;
    int linhasteste, linhastreino, colunastreino, *linhasteste1, *linhastreino1, *colunastreino1, *colunasteste1, i, j, *todasColunas;
    char tipo;

    scanf(" %c", &tipo);
    if(tipo == 'M'){
        scanf(" %f", &r);
    }
    scanf(" %i", &linhastreino);
    scanf(" %i", &linhasteste); 
    scanf(" %i", &colunastreino);

    treino = (float **) malloc(sizeof(float *) * 2);
    for(i=0; i<linhastreino; i++){
        treino[i] = (float *) malloc(sizeof(float) * 2);
    }
    for(i=0; i<linhastreino; i++){
        for(j=0; j<colunastreino; j++){
            scanf("%f ", &treino[i][j]);
        }
    }
    teste = (float **) malloc(sizeof(float *) * 2);
    for(i=0; i<linhasteste; i++){
        teste[i] = (float *) malloc(sizeof(float) * 2);
    }
    for(i=0; i<linhasteste; i++){
        for(j=0; j<colunastreino; j++){
            scanf("%f ", &teste[i][j]);
        }
    }
    
    subtracoes = (float **) malloc(sizeof(float *) * linhasteste * linhastreino);
    for(i=0; i<(linhasteste * linhastreino); i++){
        subtracoes[i] = (float *) malloc(sizeof(float) * colunastreino);
    }
    multiplicacoes = (float **) malloc(sizeof(float *) * linhasteste * linhastreino);
    for(i=0; i<(linhasteste * linhastreino); i++){
        multiplicacoes[i] = (float *) malloc(sizeof(float) * colunastreino);
    }
    somas = (float **) malloc(sizeof(float *) * linhasteste * linhastreino);
    for(i=0; i<(linhasteste * linhastreino); i++){
        somas[i] = (float *) malloc(sizeof(float) * 2);
    }
    somasteste = (float **) malloc(sizeof(float *) * linhasteste);
    for(i=0; i<linhasteste; i++){
        somasteste[i] = (float *) malloc(sizeof(float) * 2);
    }
    somastreino = (float **) malloc(sizeof(float *) * linhastreino);
    for(i=0; i<linhastreino; i++){
        somastreino[i] = (float *) malloc(sizeof(float) * 2);
    }
    distancia = (float **) malloc(sizeof(float *) * linhasteste * linhastreino);
    for(i=0; i<(linhasteste * linhastreino); i++){
        distancia[i] = (float *) malloc(sizeof(float) * 2);
    }
    switch(tipo){
        //distancia euclidiana
        case 'E':
                subtracao(teste, treino, subtracoes, linhasteste, linhastreino, colunastreino);
                multiplicacao(subtracoes, multiplicacoes, linhasteste, linhastreino, colunastreino, 2);
                soma(multiplicacoes, somas, linhasteste, linhastreino, colunastreino);
                multiplicacaovet(somas, distancia, linhasteste, linhastreino, 0.5);
                for(i=0; i<linhasteste; i++){
                    bubblesort(distancia, (i+1)*linhastreino, i*linhastreino);
                }
                kmenores(numeroDeVizinhos[k], distancia, kDistanciasMenores, linhasTeste, linhasTreino);
                matrizrotulos(linhasTeste, linhasTreino, kDistanciasMenores, rotulos);
                for(i=0; i<(linhasteste * linhastreino); i++){
                    for(j=0; j<2; j++){
                        printf("%.2f ", distancia[i][j]);
                    }
                    printf("\n");
                }
                break;
        //distância de Minkowsky
        case 'M':
                subtracaomodulo(teste, treino, subtracoes, linhasteste, linhastreino, colunastreino);
                multiplicacao(subtracoes, multiplicacoes, linhasteste, linhastreino, colunastreino, r);
                soma(multiplicacoes, somas, linhasteste, linhastreino, colunastreino);
                multiplicacaovet(somas, distancia, linhasteste, linhastreino, (1/r));
                for(i=0; i<linhasteste; i++){
                    bubblesort(distancia, (i+1)*linhastreino, i*linhastreino);
                }
                kmenores(numeroDeVizinhos[k], distancia, kDistanciasMenores, linhasTeste, linhasTreino);
                matrizrotulos(linhasTeste, linhasTreino, kDistanciasMenores, rotulos);
                for(i=0; i<(linhasteste * linhastreino); i++){
                    for(j=0; j<2; j++){
                        printf("%.2f ", distancia[i][j]);
                    }
                    printf("\n");
                }
                break;
        //distância de Chebyshev
        case 'C':
                subtracaomodulo(teste, treino, subtracoes, linhasteste, linhastreino, colunastreino);
                bubblesortmat(subtracoes, colunastreino, linhasteste, linhastreino);
                maioresmat(linhasTeste, linhasTreino, colunastreino, subtracoes,distancias);
                for(i=0; i<linhasteste; i++){
                    bubblesort(distancia, (i+1)*linhastreino, i*linhastreino);
                }
                kmenores(numeroDeVizinhos[k], distancia, kDistanciasMenores, linhasTeste, linhasTreino);
                matrizrotulos(linhasTeste, linhasTreino, kDistanciasMenores, rotulos);
                for(i=0; i<(linhasteste * linhastreino); i++){
                    for(j=0; j<2; j++){
                        printf("%.2f ", subtracoes[i][j]);
                    }
                    printf("\n");
                }
                break;
    }

    for(i=0; i<linhastreino; i++){
        free(treino[i]);
    }
    free(treino);

    for(i=0; i<linhasteste; i++){
        free(teste[i]);
    }
    free(teste);
    
    for(i=0; i<(linhasteste * linhastreino); i++){
        free(subtracoes[i]);
    }
    free(subtracoes);

    for(i=0; i<(linhasteste * linhastreino); i++){
        free(multiplicacoes[i]);
    }
    free(multiplicacoes);
    
    for(i=0; i<(linhasteste * linhastreino); i++){
        free(somas[i]);
    }
    free(somas);
    
    for(i=0; i<(linhasteste * linhastreino); i++){
        free(distancia[i]);
    }
    free(distancia);

    return 0;
}