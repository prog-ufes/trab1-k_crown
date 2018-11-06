#include <stdio.h>

#include <string.h>

int main () {

    FILE *arq;

    char c, letra = '\n';

    int vezes =0;

    arq = fopen("iris/config.txt","r");

        //Lendo o arquivo 1 por 1
        while(fread (&c, sizeof(char), 1, arq)) {
            printf("%c", c);
            if(c == letra) {
                vezes++;
            }
        } 

    printf("\nLinhas: %i\n",vezes);

    fclose(arq);

}