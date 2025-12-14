#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *database;
    database = fopen("database.txt", "r");

    if(database == NULL){
        printf("Arquivo não existe\n");
        getchar();
        exit(0);
    }

    char words[100];

    while(fgets (words, 100, database) !=NULL){
        printf("%s\n", words);
    }
    fclose(database);

    return 0;
}