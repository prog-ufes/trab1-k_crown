#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

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

void soma(float **Entrada, float *Saida, int linhasamostras, int linhasVizinhos, int colunasVizinhos){
    int i, j;
    for(i=0; i<(linhasamostras * linhasVizinhos); i++){
        Saida[i] = 0;
    }
    for(i=0; i<(linhasamostras * linhasVizinhos); i++){
        for(j=0; j<colunasVizinhos; j++){
            Saida[i] = Saida[i] + Entrada[i][j];
        }
    }
}

void subtracao(float **Amostra, float **Vizinhos, float **subtracoes, int linhasamostras, int linhasVizinhos, int colunasVizinhos){
    int i=0, j=0, l=0, m=0;
    while(l<linhasamostras){
        while(i<linhasVizinhos){
            while(j<(colunasVizinhos-1)){
                somas[m][j] = Amostra[l][j] - Vizinhos[i][j];
                j++;
            }
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
        for(j=0; j<colunasVizinhos; j++){
            multiplicacoes[i][j] = pow(Entrada[i][j],n);
        }
    }
}

void multiplicacaovet(float *Entrada, float *multiplicacoes, int linhasamostras, int linhasVizinhos, float n){
    int i;
    for(i=0; i<(linhasamostras * linhasVizinhos); i++){
        multiplicacoes[i] = pow(Entrada[i],n);
    }
}

int main(){

    char Modo;
    float **multiplicacoes, **subtracoes, **Amostra, **Vizinhos, **Distancias, *somas, *multiplicacoesvet, saida, raio;
    int k, i, j, linhasVizinhos, colunasVizinhos, linhasamostras, x;

    scanf("%c", &Modo);
    scanf("%i", &k);
    scanf("%i", &colunasVizinhos);
    scanf("%i", &linhasVizinhos);
    scanf("%i", &linhasamostras);
    
    x = linhasamostras * linhasVizinhos;
    
    somas = (float *) malloc(x * sizeof(float));
    multiplicacaovet = (float *) malloc(x * sizeof(float));
    
    subtracoes = (float **) malloc(x * sizeof(float *));
    for(i=0; i<x; i++){
        subtracoes[i] = (float *) malloc(colunasVizinhos * sizeof(float));
    }
    multiplicacoes = (float **) malloc(x * sizeof(float *));
    for(i=0; i<x; i++){
        multiplicacoes[i] = (float *) malloc(colunasVizinhos * sizeof(float));
    }
    Amostra = (float **) malloc(linhasamostras * sizeof(float*));
    for(i=0; i<linhasamostras; i++){
        Amostra[i] = (float *) malloc(colunasVizinhos * sizeof(float));
    }
    Distancias = (float **) malloc(linhasVizinhos * sizeof(float*));
    for(i=0; i<linhasamostras; i++){
        Distancias[i] = (float *) malloc(linhasVizinhos * sizeof(float));
    }
    Vizinhos = (float **) malloc(linhasVizinhos * sizeof(float *));
    for(i=0; i<linhasVizinhos; i++){
        Vizinhos[i] = (float *) malloc(colunasVizinhos * sizeof(float));
    }

    switch(Modo){
        case 'E' :
            subtracao(Amostra, Vizinhos, subtracoes, linhasamostras, linhasVizinhos, colunasVizinhos);
            multiplicacao(subtracoes, multiplicacoes, linhasamostras, linhasVizinhos, colunasVizinhos, 2);
            soma(multiplicacoes, soma, linhasamostras, linhasVizinhos, colunasVizinhos);
            multiplicacaovet(soma, multiplicacoesvet, linhasamostras, linhasVizinhos, (1/2));
            break;
        case 'M' :
            subtracao(Amostra, Vizinhos, subtracoes, linhasamostras, linhasVizinhos, colunasVizinhos);
            multiplicacao(subtracoes, multiplicacoes, linhasamostras, linhasVizinhos, colunasVizinhos, raio);
            soma(multiplicacoes, soma, linhasamostras, linhasVizinhos, colunasVizinhos);
            multiplicacaovet(soma, multiplicacoesvet, linhasamostras, linhasVizinhos, (1/raio));
            break;
        case 'C' :
            break;
    }
    
    for(i=0; i<x; i++){
        free(somas[i]);
    }
    free(somas);
    for(i=0; i<x; i++){
        free(subtracoes[i]);
    }
    free(subtracoes);
    for(i=0; i<x; i++){
        free(multiplicacoes[i]);
    }
    free(multiplicacoes);
    for(i=0; i<; i++){
        free(Amostra[i]);
    }
    free(Amostra);
    for(i=0; i<; i++){
        free(Distancias[i]);
    }
    free(Distancias);
    for(i=0; i<; i++){
        free(Vizinhos[i]);
    }
    free(Vizinhos);

    return 0;
}