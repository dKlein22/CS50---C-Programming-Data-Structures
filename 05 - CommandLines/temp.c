#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 4)
    {
        printf("Uso: ./temp <temperatura 1> <temperatura 2> <temperatura 3>\n");
        return 1;
    }

    float maiort = 0;
    float menort = 0;
    float totc = 0;
    float totf = 0;

    for (int i = 1; i < argc; i++)
    {
        float temp_atual = atof(argv[i]);
        float f_atual = (temp_atual * 1.8) + 32;

        if (i == 1)
        {
            maiort = temp_atual;
            menort = temp_atual;
        }
        else
        {
            if (temp_atual > maiort)
            {
                maiort = temp_atual;
            }
            if (temp_atual < menort)
            {
                menort = temp_atual;
            }
        }

        totc += temp_atual;
        totf += f_atual;
    }

    int qtd_numeros = argc - 1;
    float mediac = totc / qtd_numeros;
    float mediaf = totf / qtd_numeros;

    printf("Maior temperatura (C): %.2f\n", maiort);
    printf("Menor temperatura (C): %.2f\n", menort);
    printf("Media (C): %.2f\n", mediac);
    printf("Media (F): %.2f\n", mediaf);

    return 0;
}
