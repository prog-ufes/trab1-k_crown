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

int main(){

    char c, url[]="config.txt";
    int colunas=0, i=0, j=0, linhas=0, *todasColunas;
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

    char *arquivotreino, *arquivoteste, *predicoes, *modoDecalcular;
    int *numeroDeVizinhos;
    float *raio;

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

    FILE *filetreino = fopen(arquivotreino, "r");
    char *str = malloc(sizeof(char)*1000);
    if (filetreino == NULL) {
    printf ("Erro na abertura de arquivo! Programa terminado...");
    exit (1);
    }
    int n = 0, linhas2 = 0, quebra = 0;
    j = 0;
    while(!feof(filetreino)){
        //fscanf(file, "%[^\n]", str);
        fgets(str, 1000, filetreino);
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
    int linhasTreino;
    linhasTreino = linhas2 -1;
    rewind(filetreino);
    float **matrizTreino = malloc(sizeof(float*) * linhasTreino);
    for (i = 0; i < linhasTreino; i++){
        matrizTreino[i] = malloc(sizeof(float)*(n+1));
    }
    for (i = 0; i < linhasTreino; i++){
        //fscanf(file, "%[^\n]", str);
        fgets(str, 1000, filetreino);
        char *strnew = NULL;
        strnew = strtok(str, ",\n");
        while(strnew != NULL){
            matrizTreino[i][j] = atof(strnew);
            strnew = strtok(NULL, ",\n");
            j++;
        }
        j = 0;
    }
    for(i = 0; i < linhasTreino; i++){
        for (j = 0; j < n+1; j++)
            printf("%.2f ", matrizTreino[i][j]);
        putchar('\n');
    }
    putchar('\n');
    
    fclose(filetreino);

    FILE *fileteste = fopen(arquivoteste, "r");
    char *str1 = malloc(sizeof(char)*1000);
    if (fileteste == NULL) {
    printf ("Erro na abertura de arquivo! Programa terminado...");
    exit (1);
    }
    int m = 0, linhas3 = 0;
    j = 0;
    quebra = 0;
    while(!feof(fileteste)){
        //fscanf(file, "%[^\n]", str);
        fgets(str1, 1000, fileteste);
        if( quebra == 0){
            for(i = 0; i < strlen(str1); i++){
                if (str1[i] == ','){
                    m++;
                }
            }
            quebra++;
        }
        linhas3++;
    }
    int linhasTeste;
    linhasTeste = linhas3 -1;
    rewind(fileteste);
    float **matrizTeste = malloc(sizeof(float*) * linhasTeste);
    for (i = 0; i < linhasTeste; i++){
        matrizTeste[i] = malloc(sizeof(float)*(m+1));
    }
    j=0;
    for (i = 0; i < linhasTeste; i++){
        //fscanf(file, "%[^\n]", str);
        fgets(str1, 1000, fileteste);
        char *strnew1 = NULL;
        strnew1 = strtok(str1, ",\n");
        while(strnew1 != NULL){
            matrizTeste[i][j] = atof(strnew1);
            strnew1 = strtok(NULL, ",\n");
            j++;
        }
        j = 0;
    }
    for(i = 0; i < linhasTeste; i++){
        for (j = 0; j < m+1; j++)
            printf("%.2f ", matrizTeste[i][j]);
        putchar('\n');
    }
    
    fclose(fileteste);

    free(str);
    for(i = 0; i < linhasTreino; i++){
        free(matrizTreino[i]);
    }
    free(matrizTreino);

    free(str1);
    for(i = 0; i < linhasTeste; i++){
        free(matrizTeste[i]);
    }
    free(matrizTreino);

    free(todasColunas);

    free(arquivoteste);
    free(arquivotreino);
    free(predicoes);
    free(modoDecalcular);
    free(numeroDeVizinhos);
    free(raio);

    return 0;
}