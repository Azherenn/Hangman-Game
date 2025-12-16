#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char palavra[50];
    char dica[100];
    int nivel;
} storage;

int main() {

 storage p;

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
       p.id = atoi(token);
    printf("O id é: = %d\n", p.id);
        token = strtok(NULL, ";");
        strcpy(p.palavra, token);
    printf("A palavra é = %s\n", p.palavra);
        token = strtok(NULL, ";");
        strcpy(p.dica, token);
    printf("A dica é: = %s\n", p.dica);
        token = strtok(NULL, ";");
        p.nivel = atoi(token);
    printf("O nível é: = %d\n", p.nivel);
        token = strtok(NULL, ";");
    }
    fclose(database);

    return 0;
}