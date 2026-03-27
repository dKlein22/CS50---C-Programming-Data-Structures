#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Use: /.contador (mensagem)\n");
        return 1;
    }

    int n = strlen(argv[1]);

    printf("A palavra %s contem %i caracteres\n", argv[1], n);

}

