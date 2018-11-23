#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){

    float *Encontrado, *Esperado;
    int i, j, l, k, linhasTeste, numeroDeRotulos, **MatrizDeConfusao;

    scanf("%i", &linhasTeste);
    scanf("%i", &numeroDeRotulos);
    
    //Aloca a memoria da Matriz de confusao
    MatrizDeConfusao = (int **) malloc(numeroDeRotulos * sizeof(int *));
    for(i=0; i<linhasTeste; i++){
        MatrizDeConfusao[i] = (int *) malloc(numeroDeRotulos * sizeof(int));
    }
    
    //Aloca a memoria do vetor das respostas encontradas e das respostas esperadas
    Encontrado = (float *) malloc(linhasTeste * sizeof(float));
    Esperado = (float *) malloc(linhasTeste * sizeof(float));
    
    //Coloque para testar
    for(i=0; i<numeroDeRotulos; i++){
        for(j=0; j<numeroDeRotulos; j++){
            MatrizDeConfusao[i][j] = 0;
        }
    }
    for(i=0; i<linhasTeste; i++){
        scanf("%f", &Encontrado[i]);
    }
    for(i=0; i<linhasTeste; i++){
        scanf("%f", &Esperado[i]);
    }

    for(i=0; i<linhasTeste; i++){
        l = Encontrado[i] - 1;
        k = Esperado[i] - 1;
        MatrizDeConfusao[l][k]++;
    }
    for(i=0; i<numeroDeRotulos; i++){
        for(j=0; j<numeroDeRotulos; j++){
            printf("%i ", MatrizDeConfusao[i][j]);
        }
        printf("\n");
    }

    return 0;
}