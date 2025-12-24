#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct
{
    int id;
    char palavra[50];
    char dica[100];
    int nivel;
} caixa;

void criarMascara(char *palavra, char *mascara)
{
    int tamanho = strlen(palavra);

    for (int i = 0; i < tamanho; i++)
    {
        mascara[i] = '_';
    }

    mascara[tamanho] = '\0'; // serve para reconhecer o final da string.
}

void desenharForca(int erros, char *mascara)
{
    switch (erros)
    {
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

void carregarBanco(caixa *p, int id_procurado, char *mascara)
{
    FILE *database;
    database = fopen("database.txt", "r");

    if (database == NULL)
    {
        printf("Arquivo não existe\n");
        getchar();
        exit(0);
    }

    char words[100];
    char *token;

    while (fgets(words, 100, database) != NULL)
    {
        token = strtok(words, ";");
        p->id = atoi(token);

        if (p->id == id_procurado)
        {
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

void limparTela()
{
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux ou Mac
#endif
}

int main(){

do {

    int vida = 7;
    int ganhou = 0;
    int acertou = 0;
    char errado[26];
    int qtd_erros = 0;

    srand(time(NULL));
    int id_sorteado = (rand() % 23) + 1;
    caixa p;
    char mask[50];

    carregarBanco(&p, id_sorteado, mask);

    char chute;
    do
    {
        limparTela();
        
        printf("AVISOS!\n");
        printf("Caso o jogador escreva uma palavra, será considerada apenas a primeira letra\n");
        printf("O jogo só aceita letras, então não adianta chutar a palavra toda!\n\n");

        desenharForca(7 - vida, mask);
        printf("\nDica: %s\n", p.dica);
        if (qtd_erros > 0)
        {
            printf("Erros: ");
            for (int k = 0; k < qtd_erros; k++)
            {
                printf("%c ", errado[k]);
            }
            printf("\n");
        }

    do{
        printf("Digite uma letra: ");
        scanf(" %c", &chute);
        chute = toupper(chute);
        while (getchar() != '\n');

        if(!isalpha(chute)){
            printf("\nErro! Digite apenas letras de A a Z.\n\n");
        }

        }while (!isalpha(chute)); 

        acertou = 0;
        for (int i = 0; i < strlen(p.palavra); i++)
        {
            if (p.palavra[i] == chute)
            {
                mask[i] = chute;
                acertou = 1;
            }
        }
        if (acertou == 0)
        {
            vida--;
            errado[qtd_erros] = chute;
            qtd_erros++;
            printf("\nVocê errou! Aperte enter para continuar.\n");
            getchar();
        }
        if (strcmp(mask, p.palavra) == 0)
        {
            ganhou = 1;
        }
    } while (vida > 0 && ganhou == 0);

    limparTela();

    if (ganhou)
    {
        desenharForca(7 - vida, mask);
        printf("Parabéns! Você ganhou!");
    }
    else
    {
        desenharForca(7, mask);
        printf("Perdeu! Tente novamente!\n");
    }

    printf("Pressione ENTER para jogar novamente ou feche o jogo.\n");

    } while (getchar() == '\n');

    return 0;
}