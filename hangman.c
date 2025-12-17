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

int main() {

srand(time(NULL));
 int id_sorteado = (rand() % 23) +1;
storage p;

    FILE *database;
    database = fopen("database.txt", "r");

    if(database == NULL){
        printf("Arquivo nÃ£o existe\n");
        getchar();
        exit(0);
    }
    char words[100];
    char *token;
    while(fgets (words, 100, database) !=NULL){

        token = strtok(words, ";");
       p.id = atoi(token);
       if (p.id == id_sorteado){
    printf("O id secreto escolhido Ã©: = %d |", id_sorteado);

        token = strtok(NULL, ";");
        strcpy(p.palavra, token);
    printf("A palavra Ã© = %s |", p.palavra);

        token = strtok(NULL, ";");
        strcpy(p.dica, token);
    printf("A palavra Ã© = %s |", p.dica);

        token = strtok(NULL, ";");
        p.nivel = atoi(token);
    printf("O nÃ­vel Ã© = %d \n", p.nivel);
        
    }
    }
    fclose(database);
    return 0;
}