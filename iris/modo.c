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

void lerConfig(int *linhasconfig, int *todasColunas, int *numeroDeVizinhos, float *raio, char *modoDecalcular, char *arquivoteste, char *arquivotreino, char *predicoes){
    char c, url[]="config.txt";
    int colunas=0, i=0, j=0, linhas=0;
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
            y = linhas + 1;
            todasColunas = (int *) realloc(todasColunas, y * sizeof(int));
            if(linhas<3){
                todasColunas[linhas] = colunas + 1;
                linhas++;
                colunas = 0;
            }else{
                todasColunas[linhas] = colunas ;
                linhas++;
                colunas = 0;
            }
        }
    }

    linhasconfig = &linhas;

    arquivotreino = (char *) malloc(todasColunas[0] * sizeof(char));
    arquivoteste = (char *) malloc(todasColunas[1] * sizeof(char));
    predicoes = (char *) malloc(todasColunas[2] * sizeof(char));
    modoDecalcular = (char *) malloc((linhas - 2) * sizeof(char));
    numeroDeVizinhos = (int *) malloc((linhas - 3) * sizeof(int));
    raio = (float *) malloc((linhas - 3) * sizeof(float));
    
    rewind(arq);
    int linhas1 = 0;
    //Aloca os vetores de arquivos e de entradas
    while(linhas1<linhas){
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
}

void lerArquivo(char *arquivo, int *linhasArquivo, int *colunasArquivo, float **matriz){
    FILE *file = fopen(arquivo, "r");
    char *str = malloc(sizeof(char)*1000);
    if (file == NULL) {
    printf ("Erro na abertura de arquivo! Programa terminado...");
    exit (1);
    }
    int n = 0, linhas2 = 0, quebra = 0, j = 0, i;
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
        linhas2++;
    }
    int linhas;
    linhas = linhas2 -1;
    linhasArquivo = &linhas;
    rewind(file);
    matriz = malloc(sizeof(float*) * linhas);
    for (i = 0; i < linhas; i++){
        matriz[i] = malloc(sizeof(float)*(n+1));
    }
    for (i = 0; i < linhas; i++){
        fgets(str, 1000, file);
        char *strnew = NULL;
        strnew = strtok(str, ",\n");
        while(strnew != NULL){
            matriz[i][j] = atof(strnew);
            strnew = strtok(NULL, ",\n");
            j++;
        }
        j = 0;
    }
    for(i = 0; i < linhas; i++){
        for (j = 0; j < n+1; j++)
            printf("%.2f ", matriz[i][j]);
        putchar('\n');
    }
    putchar('\n');
    
    fclose(file);
    n = n +1;
    colunasArquivo = &n;
}

int main(){

    float **treino, **teste, r, **distancia, **somastreino, **somasteste, **somas, **multiplicacoes, **subtracoes;
    int linhasteste, linhastreino, colunastreino, *linhasteste1, *linhastreino1, *colunastreino1, *colunasteste1, i, j, *todasColunas;
    char tipo;
    char *arquivotreino, *arquivoteste, *predicoes, *modoDecalcular;
    int *numeroDeVizinhos, *linhasconfig, *linhasArquivo,  *colunasArquivo;
    float *raio, **matriztreino, **matrizteste;

    scanf(" %c", &tipo);
    if(tipo == 'M'){
        scanf(" %f", &r);
    }
    scanf(" %i", &linhastreino);
    scanf(" %i", &linhasteste); 
    scanf(" %i", &colunastreino);

    lerConfig(linhasconfig, todasColunas, numeroDeVizinhos, raio, modoDecalcular, arquivoteste, arquivotreino, predicoes);
    lerArquivo("dataset/iris_treino.csv", linhastreino1, colunastreino1, matriztreino);
    lerArquivo("dataset/iris_teste.csv", linhasteste1, colunasteste1, matrizteste);

    treino = (float **) malloc(sizeof(float *) * 2);
    for(i=0; i<linhastreino; i++){
        treino[i] = (float *) malloc(sizeof(float) * 2);
    }
    teste = (float **) malloc(sizeof(float *) * 2);
    for(i=0; i<linhasteste; i++){
        teste[i] = (float *) malloc(sizeof(float) * 2);
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
                for(i=0; i<(linhasteste * linhastreino); i++){
                    for(j=0; j<2; j++){
                        printf("%.2f ", distancia[i][j]);
                    }
                    printf("\n");
                }
                break;
        //distância de Chebyshev
        case 'C':
                somamat(teste, somasteste, linhasteste, colunastreino);
                somamat(treino, somastreino, linhastreino, colunastreino);
                subtracaovet(somasteste, somastreino, subtracoes, linhasteste, linhastreino);
                for(i=0; i<linhasteste; i++){
                    bubblesort(distancia, (i+1)*linhastreino, i*linhastreino);
                }
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

    free(raio);
    free(todasColunas);
    free(modoDecalcular);
    free(numeroDeVizinhos);
    free(arquivoteste);
    free(arquivotreino);
    free(predicoes);

    return 0;
}