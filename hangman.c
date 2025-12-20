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
        printf("Arquivo não existe\n");
        getchar();
        exit(0);
    }
    char words[100];
    char *token;
    while(fgets (words, 100, database) !=NULL){
desenharForca(7, mask);
        token = strtok(words, ";");
       p.id = atoi(token);
       if (p.id == id_sorteado){
    printf("O id secreto escolhido é: = %d |", id_sorteado);

        token = strtok(NULL, ";");
        strcpy(p.palavra, token);

        //TESTAR MASCARA
        criarMascara(p.palavra, mask); 
        printf("Palavra: %s\n", p.palavra);
        printf("Mascara: %s\n", mask);
        ///////////////////

        tam = strlen(p.palavra);
    printf("A palavra é = %s |", p.palavra);
    printf("A quantidade de letra é: %zu ", tam);

        token = strtok(NULL, ";");
        strcpy(p.dica, token);
    printf("A dica é = %s |", p.dica);

        token = strtok(NULL, ";");
        p.nivel = atoi(token);
    printf("O nível é = %d \n", p.nivel);
        
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