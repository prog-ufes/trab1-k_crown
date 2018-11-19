
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file = fopen("teste1.txt", "r");
    char *str = malloc(sizeof(char)*1000);
    if (file == NULL) {
    printf ("Erro na abertura de arquivo! Programa terminado...");
    exit (1);
    }
    int n = 0, linhas = 0, i, quebra = 0, j = 0;
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
        linhas++;
    }
    rewind(file);
    float **vetor = malloc(sizeof(float*) * linhas);
    for (i = 0; i < linhas; i++){
        vetor[i] = malloc(sizeof(float)*(n+1));
    }
    for (i = 0; i < linhas; i++){
        //fscanf(file, "%[^\n]", str);
        fgets(str, 1000, file);
        char *strnew = NULL;
        strnew = strtok(str, ",\n");
        while(strnew != NULL){
            vetor[i][j] = atof(strnew);
            strnew = strtok(NULL, ",\n");
            j++;
        }
        j = 0;
    }
    for(i = 0; i < linhas; i++){
        for (j = 0; j < n+1; j++)
            printf("%.2f ", vetor[i][j]);
        putchar('\n');
        free(vetor[i]);
    }
    free(str);
    free(vetor);
    fclose(file);
    return 0;

}