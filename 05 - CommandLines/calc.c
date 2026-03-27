#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    if (argc != 4)
    {
        printf("Use: ./calc <operação> <numero 1> <numero 2>\n");
        return 1;
    }

    int n1 = atoi(argv[2]);
    int n2 = atoi(argv[3]);
    string ope = argv[1];

    if (strcmp(ope, "soma") == 0)
    {
        printf("Resultado: %i\n", n1 + n2);
    }
    else if (strcmp(ope, "sub") == 0)
    {
        printf("Resultado: %i\n", n1 - n2);
    }
    else if (strcmp(ope, "mult") == 0)
    {
        printf("Resultado: %i\n", n1 * n2);
    }
    else if (strcmp(ope, "div") == 0)
    {
        printf("Resultado: %i\n", n1/n2);
    }
    else
    {
        printf("Operação %s desconhecida!\n", ope);
    }
    return 0;
}
