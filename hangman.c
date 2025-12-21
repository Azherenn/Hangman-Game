#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char palavra[50];
    char dica[100];
    int nivel;
} storage;


void criarMascara(char *palavra, char *mascara) {
        int tamanho = strlen(palavra);

        for(int i = 0; i < tamanho; i++){
            mascara[i] = '_';
     }

    mascara[tamanho] = '\0'; //serve para reconhecer o final da string.

    }


void desenharForca(int erros, char *mascara){
    switch (erros){
        case 0: 
        printf("-------\n");
        printf("|/     |\n");
        printf("|      \n");
        printf("|\n"); 
        printf("|\n");
        printf("|     %s\n", mascara);
        printf("\n");
        break;

        case 1: 
        printf("-------\n");
        printf("|/     |\n");
        printf("|     (_)\n");
        printf("|\n"); 
        printf("|\n");
        printf("|     %s\n", mascara);
        printf("\n");
        break;

        case 2: 
        printf("-------\n");
        printf("|/     |\n");
        printf("|     (_)\n");
        printf("|      |\n"); 
        printf("|\n");
        printf("|     %s\n", mascara);
        printf("\n");
        break;

        case 3: 
        printf("-------\n");
        printf("|/     |\n");
        printf("|     (_)\n");
        printf("|      |\n"); 
        printf("|      |\n");
        printf("|     %s\n", mascara);
        printf("\n");
        break;

        case 4: 
        printf("-------\n");
        printf("|/     |\n");
        printf("|     (_)\n");
        printf("|     /|\n"); 
        printf("|      |\n");
        printf("|     %s\n", mascara);
        printf("\n");
        break;

        case 5: 
        printf("-------\n");
        printf("|/     |\n");
        printf("|     (_)\n");
        printf("|     /|\\\n"); 
        printf("|      |\n");
        printf("|     %s\n", mascara);
        printf("\n");
        break;

        case 6: 
        printf("-------\n");
        printf("|/     |\n");
        printf("|     (_)\n");
        printf("|     /|\\\n"); 
        printf("|      |\n");
        printf("|     /\n");
        printf("|     %s\n", mascara);
        printf("\n");
        break;

        case 7: 
        printf("-------\n");
        printf("|/     |\n");
        printf("|     (_)\n");
        printf("|     /|\\\n"); 
        printf("|      |\n");
        printf("|     /\\\n");
        printf("|     %s\n", mascara);
        printf("\n");
        break;

    }
}

void carregarBanco(storage *p, int id_procurado, char *mascara){
    FILE *database;
    database = fopen("database.txt", "r");

    if(database == NULL){
        printf("Arquivo não existe\n");
        getchar();
        exit(0);
    }
    
    char words[100];
    char *token;
    
    while(fgets (words, 100, database) !=NULL){
        token = strtok(words, ";");
        p->id = atoi(token);

        if(p->id == id_procurado){
            token = strtok(NULL, ";");
            strcpy(p->palavra, token); 
            
            criarMascara(p->palavra, mascara);

            token = strtok(NULL, ";");
            strcpy(p->dica, token);

            token = strtok(NULL, ";");
            p->nivel = atoi(token);

            break;
        }

    }
 
    fclose(database);
}

int main() {

srand(time(NULL));
 int id_sorteado = (rand() % 23) +1;
storage p;
size_t tam;
char mask[50];
char chute;

carregarBanco(&p, id_sorteado, mask);

printf("DEBUG: Palavra Sorteada: %s\n", p.palavra);
    desenharForca(0, mask);

    return 0;
}