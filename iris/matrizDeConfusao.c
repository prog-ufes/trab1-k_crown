#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){

    float *Encontrado, *Esperado, Acc;
    int i, j, l, k, linhasTeste, numeroDeRotulos, **MatrizDeConfusao, Acertos=0;

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
            if(i==j){
                Acertos = Acertos + MatrizDeConfusao[i][j];
            }
        }
    }
    printf("%i\n", Acertos);
    printf("%i\n", linhasTeste);
    float A = Acertos;
    float T = linhasTeste;
    Acc = A/T;

    printf("%.2f\n", Acc);
    printf("\n");
    for(i=0; i<numeroDeRotulos; i++){
        for(j=0; j<numeroDeRotulos; j++){
            printf("%i ", MatrizDeConfusao[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0; i<linhasTeste; i++){
        printf("%.2f\n", Encontrado[i]);
    }

    return 0;
}