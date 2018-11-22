#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"distancias.h"

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

void classificacao(float **rotulos, float *classificado, int linhasTeste, int linhasTreino){
    int i, j, k, n=0, **numeroRotulos;
    numeroRotulos = (float **) malloc(linhasTeste * sizeof(float *));
    for(i=0; i<linhasTeste; i++){
        numeroRotulos[i] = (float *) malloc(linhasTreino * sizeof(float));
    }
    classificado = (float *) malloc(linhasTeste * sizeof(float));
    for(i=0; i<linhasTeste; i++){
        for(k=0; k<linhasTreino; k++){
            for(j=0; j<linhasTreino; j++){
                if(rotulos[i][k] == rotulos[i][j]){
                    n++;
                }
                numeroRotulos[i][k] = n;
                n=0;
            }    
        }
    }
    for(i=0; i<linhasTeste; i++){
        for(k=0; k<linhasTreino; k++){
            for(j=0; j<linhasTreino; j++){
                if(numeroRotulos[i][k] <= numeroRotulos[i][j]){
                    k++;
                }
            }    
        }
        classificado[i] = numeroRotulos[i][k];
    }

}