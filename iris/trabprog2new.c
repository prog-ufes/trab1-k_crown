#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//Ordena do menor para o maior
void quick_sort(float *Distancias, int primeiro, int ultimo) {
    int i, j, z;
    float x, y;
     
    i = primeiro;
    j = ultimo;
    z= (primeiro + ultimo) / 2;
    x = Distancias[z];
     
    while(i <= j) {
        while(Distancias[i] < x && i < ultimo) {
            i++;
        }
        while(Distancias[j] > x && j > primeiro) {
            j--;
        }
        if(i <= j) {
            y = Distancias[i];
            Distancias[i] = Distancias[j];
            Distancias[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > primeiro) {
        quick_sort(Distancias, primeiro, j);
    }
    if(i < ultimo) {
        quick_sort(Distancias, i, ultimo);
    }
}

void soma(float **multiplicacoes, float *somas, int linhasTeste, int linhasTreino, int m){
    int i, j;
    for(i=0; i<(linhasTeste * linhasTreino); i++){
        somas[i] = 0;
    }
    for(i=0; i<(linhasTeste * linhasTreino); i++){
        for(j=0; j<m; j++){
            somas[i] = somas[i] + multiplicacoes[i][j];
        }
    }
}

void subtracao(float **matrizTeste, float **matrizTreino, float **subtracoes, int linhasTeste, int linhasTreino, int m){
    int i=0, j=0, l=0, n=0;
    while(l<linhasTeste){
        while(i<linhasTreino){
            while(j<m){
                subtracoes[n][j] = matrizTeste[l][j] - matrizTreino[i][j];
                j++;
            }
            n++;
            i++;
            j=0;
        }
        l++;
        i=0;
        j=0;
    }
}

void multiplicacaoMat(float **subtracoes, float **multiplicacoes, int linhasTeste, int linhasTreino, int m, float n){
    int i, j;
    for(i=0; i<(linhasTeste * linhasTreino); i++){
        for(j=0; j<m; j++){
            multiplicacoes[i][j] = pow(subtracoes[i][j],n);
        }
    }
}

void multiplicacaoVet(float *somas, float **Distancias, int linhasTeste, int linhasTreino, float n){
    int i, l=0, j=0;
    for(i=0; i<(linhasTeste * linhasTreino); i++){
        Distancias[l][j] = pow(somas[i],n);
        j++;
        if(j==(linhasTreino-1)){
            j=0;
            l++;
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

    int x = linhasTreino * linhasTeste;
    int w;

    float *somas = (float *) malloc(x * sizeof(float));
    float *multiplicacaovet = (float *) malloc(x * sizeof(float));
    
    float **subtracoes = (float **) malloc(x * sizeof(float *));
    for(i=0; i<x; i++){
        subtracoes[i] = (float *) malloc(m * sizeof(float));
    }
    float **multiplicacoes = (float **) malloc(x * sizeof(float *));
    for(i=0; i<x; i++){
        multiplicacoes[i] = (float *) malloc(m * sizeof(float));
    }
    float **Distancias = (float **) malloc(linhasTeste * sizeof(float*));
    for(i=0; i<linhasTeste; i++){
        Distancias[i] = (float *) malloc(m * sizeof(float));
    }
    float **kDistancias = (float **) malloc(linhasTeste * sizeof(float*));
    for(j=0; j<linhasTeste; j++){
        kDistancias[j] = (float *) malloc(1 * sizeof(float));
    }

    for(i=0; i<strlen(modoDecalcular); i++){
        switch(modoDecalcular[i]){
        case 'E' :
            subtracao(matrizTeste, matrizTreino, subtracoes, linhasTeste, linhasTreino,  m);
            printf("%f ", subtracoes[0][0]);
            multiplicacaoMat(subtracoes, multiplicacoes, linhasTeste, linhasTreino, m, 2);
            soma(multiplicacoes, somas, linhasTeste, linhasTreino, m);
            multiplicacaoVet(somas, Distancias, linhasTeste, linhasTreino, (1/2));
            for(j=0; j<linhasTeste; j++){
                quick_sort(Distancias[j], 0, (m-1));
            }
            for(j=0; j<linhasTeste; j++){
                kDistancias[j] = (float *) realloc(kDistancias[j], numeroDeVizinhos[i] * sizeof(float));
            }
            for(j=0; j<linhasTeste; j++){
                for(w=0; w<numeroDeVizinhos[i]; w++){
                    kDistancias[j][w] = Distancias[j][w];
                }
            }
            printf("%f ", kDistancias[0][0]);
            break;
        case 'M' :
            subtracao(matrizTeste, matrizTreino, subtracoes, linhasTeste, linhasTreino,  m);
            printf("%f ", subtracoes[0][0]);
            multiplicacaoMat(subtracoes, multiplicacoes, linhasTeste, linhasTreino, m, raio[i]);
            soma(multiplicacoes, somas, linhasTeste, linhasTreino, m);
            multiplicacaoVet(somas, Distancias, linhasTeste, linhasTreino, (1/raio[i]));
            for(j=0; j<linhasTeste; j++){
                quick_sort(Distancias[j], 0, (m-1));
            }
            for(j=0; j<linhasTeste; j++){
                kDistancias[j] = (float *) realloc(kDistancias[j], numeroDeVizinhos[i] * sizeof(float));
            }
            for(j=0; j<linhasTeste; j++){
                for(w=0; w<numeroDeVizinhos[i]; w++){
                    kDistancias[j][w] = Distancias[j][w];
                }
            }
            printf("%f ", kDistancias[0][0]);
            break;
        /*case 'C' :
            
            float **kDistancias = (float **) malloc(linhasTeste * sizeof(float*));
            for(i=0; i<linhasTeste; i++){
                kDistancias[i] = (float *) malloc(numeroDeVizinhos[i] * sizeof(float));
            }break;*/
        }
    }

    for(j=0; j<linhasTeste; j++){
        for(w=0; w<numeroDeVizinhos[i]; w++){
            printf("%f ", kDistancias[j][w]);
        }
        printf("\n");
    }

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

    free(somas);
    free(multiplicacaovet);

    for(i=0; i<x; i++){
        free(subtracoes[i]);
    }
    free(subtracoes);

    for(i=0; i<x; i++){
        free(multiplicacoes[i]);
    }
    free(multiplicacoes);

    for(i=0; i<linhasTeste; i++){
        free(Distancias[i]);
    }
    free(Distancias);

    for(i=0; i<linhasTeste; i++){
        free(kDistancias[i]);
    }
    free(kDistancias);

    return 0;
}