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
size_t tam;
char mask[50];
char chute;
int right = 0;

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
<<<<<<< HEAD
    printf("A palavra Ã© = %s |", p.palavra);

        token = strtok(NULL, ";");
        strcpy(p.dica, token);
    printf("A palavra Ã© = %s |", p.dica);
=======
        tam = strlen(p.palavra);
    printf("A palavra é = %s |", p.palavra);
    printf("A quantidade de letra é: %zu ", tam);

        token = strtok(NULL, ";");
        strcpy(p.dica, token);
    printf("A dica é = %s |", p.dica);
>>>>>>> 673bbf77586e9c2a8183a5e08bad423286a52b10

        token = strtok(NULL, ";");
        p.nivel = atoi(token);
    printf("O nÃ­vel Ã© = %d \n", p.nivel);
        
    }
    }
    fclose(database);

//     for (;;){
//             printf(mask);
// scanf("Digite uma letra:");
// if (p.palavra == chute){
// printf("Acertou a palavra");
// printf(chute[i]);
// }
//     }
    return 0;
}