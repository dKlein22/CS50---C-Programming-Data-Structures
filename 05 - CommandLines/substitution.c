#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Declaração
bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // Verifica número de argumentos
    if (argc != 2)
    {
        printf("Uso: ./substitution CHAVE\n");
        return 1;
    }

    string key = argv[1];

    // Valida a chave
    if (!is_valid_key(key))
    {
        printf("A chave deve conter 26 letras únicas e apenas caracteres alfabéticos.\n");
        return 1;
    }

    // Pede o plaintext
    string plaintext = get_string("plaintext: ");
    int n = strlen(plaintext);

    // Imprime ciphertext
    printf("ciphertext: ");

    for (int i = 0; i < n; i++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            int index = c - 'A';               // 0..25
            char mapped = key[index];          // pega da chave
            putchar(toupper(mapped));          // preserva maiúscula
        }
        else if (islower(c))
        {
            int index = c - 'a';
            char mapped = key[index];
            putchar(tolower(mapped));          // preserva minúscula
        }
        else
        {
            putchar(c);                        // não-alfabético fica igual
        }
    }

    printf("\n");
    return 0;
}

// Valida a chave: 26 chars, só letras, sem repetição (case-insensitive)
bool is_valid_key(string key)
{
    if (key == NULL)
    {
        return false;
    }

    int len = strlen(key);
    if (len != 26)
    {
        return false;
    }

    bool used[26] = {false};

    for (int i = 0; i < len; i++)
    {
        if (!isalpha((unsigned char) key[i]))
        {
            return false;
        }

        int idx = toupper((unsigned char) key[i]) - 'A';
        if (idx < 0 || idx > 25) // segurança adicional
        {
            return false;
        }

        if (used[idx]) // letra repetida
        {
            return false;
        }
        used[idx] = true;
    }

    // opcional: checar todas as letras marcadas (mas o loop já garante)
    return true;
}
