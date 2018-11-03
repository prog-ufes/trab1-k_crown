#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//Ordena do menor para o maior
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

int main(){

    char url[]="iris/config.txt";
    char **matrizConfig, ch;
    int i, j, w=0, linhas=0, colunas=0;
    //Abre o arquivo
    FILE *arq;
    arq = fopen(url, "r");
    if(arq==NULL){
        printf ("Erro na abertura de arquivo! Programa terminado...");
        exit (1);
    }
    //Conta o numero de linhas de arq
    while( (ch=fgetc(arq))!= feof(arq) ){
		if(ch == '\n'){
			linhas++;
        }
    }
    int todasColunas[linhas];
    //conta o numero de colunas de arq e as coloca em ordem em um vetor 
    while( (ch=fgetc(arq))!= feof(arq)){
        if(ch != '\n'){
            colunas++;
        }else{
            todasColunas[w]=colunas;
            colunas=0;
            w++;
        }
    }
    //Aloca a matriz
    matrizConfig = (char **) malloc(linhas * (sizeof(char)));
    for(i=0; i<linhas; i++){
        matrizConfig[i] = (char *) malloc(todasColunas[i] * (sizeof(char)));
    }
    //Copia o arquivo para a matriz em forma de vetores
    for(i=0; i<linhas; i++){
        fgets(matrizConfig[i], sizeof(matrizConfig[i]), arq);
    }
    //Fecha o arquivo
    fclose(arq);
    //Printa a matriz 
    for(i=0; i<linhas; i++){
        printf("%s", matrizConfig[i]);
    }
    //Abre o arquivo
    FILE *arq1;
    arq1 = fopen(matrizConfig[0], "r");
    if(arq1==NULL){
        printf ("Erro na abertura de arquivo! Programa terminado...");
        exit (1);
    }
    //Conta o numero de linhas de arq
    while( (ch=fgetc(arq1))!= feof(arq1) ){
		if(ch == '\n'){
			linhas++;
        }
    }
    int todasColunas1[linhas], y;
    //conta o numero de colunas de arq e as coloca em ordem em um vetor 
    while( (ch=fgetc(arq1))!= feof(arq1)){
        if(ch != '\n'){
            colunas++;
        }else{
            todasColunas1[y]=colunas;
            colunas=0;
            y++;
        }
    }
    //Aloca a matriz
    matrizIrisTeste = (char **) malloc(linhas * (sizeof(char)));
    for(i=0; i<linhas; i++){
       matrizIrisTeste[i] = (char *) malloc(todasColunas1[i] * (sizeof(char)));
    }
    //Copia o arquivo para a matriz em forma de vetores
    for(i=0; i<linhas; i++){
        fgets(matrizIrisTeste[i], sizeof(matrizIrisTeste[i]), arq);
    }
    //Fecha o arquivo
    fclose(arq1);


   /* char escolhaDeCalculo;
    int k, r, DE, de, DM, dm, DC, dc, Acc, A, T, numDeRotulos;

    switch(escolhaDeCalculo){
       case 'E'://Distância Euclidiana soma
                
                //Distância Euclidiana final
                DE = sqrt(de)
                break;
        case 'M'://Distância Minkowsky soma

                //Distância Minkowsky final
                DM = (dm)^(1/r)
                break;

        case 'C'://Distância de Chebyshev

                //Distância Euclidiana soma
                
                //Distância Euclidiana final
                DE = sqrt(de)
                //Similaridade de Cosseno final
                DC = dc/DE
                break;
    }

    int matDeConf[numDeRotulos][numDeRotulos];*/

    //Desaloca a matriz 
    for(i=0; i<linhas; i++){
        free(matrizConfig[i]);
    }

    return 0;
}