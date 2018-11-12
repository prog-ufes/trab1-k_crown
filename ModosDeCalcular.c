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

void soma(float **Amostra, float **Vizinhos, float **somas, int linhasamostras, int linhasVizinhos, int colunasVizinhos){
    int i=0, j=0, l=0, m=0;
    while(l<linhasamostras){
        while(i<linhasVizinhos){
            while(j<(colunasVizinhos-1)){
                somas[m][j] = Amostra[l][j] + Vizinhos[i][j];
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

int main(){

    char Modo;
    float **subtracoes, **Amostra, **Vizinhos, **Distancias, **somas, saida, raio;
    int k, i, j, linhasVizinhos, colunasVizinhos, linhasamostras, x;

    scanf("%c", &Modo);
    scanf("%i", &k);
    scanf("%i", &colunasVizinhos);
    scanf("%i", &linhasVizinhos);
    scanf("%i", &linhasamostras);
    
    x = linhasamostras * linhasVizinhos;
    somas = (float **) malloc(x * sizeof(float *));
    for(i=0; i<x; i++){
        somas = (float *) malloc(colunasVizinhos * sizeof(float));
    }
    subtracoes = (float **) malloc(x * sizeof(float *));
    for(i=0; i<x; i++){
        subtracoes = (float *) malloc(colunasVizinhos * sizeof(float));
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
            while(j<linhasamostras){

            }
            break;
        case 'M' :
            break;
        case 'C' :
            break;
    }
    while(j<linhasamostras){

    }
    

    return 0;
}