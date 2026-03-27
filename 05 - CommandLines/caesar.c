#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Verifica se há exatamente 2 argumentos
    if (argc != 2)
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }

    //Verifica se todas caracteres da array são digitos
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./ceasar key\n");
            return 1;
        }
    }

    //Converte key para inteiro
    int key = atoi(argv[1]);
    key = key % 26; //Garante que fique dentro de 0 a 25

    //Pede o plaintext
    string plaintext = get_string("Plaintext: ");

    //Cria espaço para o ciphertext
    printf("Ciphertext: ");


    //Percorre cada caractere
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];

        //Se for letra maiscula
        if(isupper(c))
        {
            printf("%c", ((c - 'A' + key) % 26) + 'A');
        }
        //Se for letra minuscula
        else if(islower(c))
        {
            printf("%c", ((c - 'a' + key) % 26) + 'a');
        }
        //Se não for letra imprime igual
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}
