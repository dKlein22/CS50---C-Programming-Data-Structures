#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int travel = 5;
    float consumo[5];
    float maiorm = 0;
    float media = 0;
    int cont = 0;
    float soma = 0;

    for (int i = 0; i < travel; i++)
    {
        consumo[i] = get_float("Digite o consumo (Km/l) da viagem %i: ", i+1);

        soma += consumo[i];
    }

    float menorm = consumo[0];
    media = (media + soma)/travel;

    for (int i = 0; i < travel; i++)
    {
        if (media > maiorm)
        {
            maiorm = consumo[i];
        }

        if (consumo[i] < menorm)
        {
            menorm = consumo[i];
        }

        if (consumo[i] > media)
        {
            cont += 1;
        }
    }


    printf("\n");
    printf("----Média Geral----\n");
    printf("\n");
    printf("Média geral do consumo: %.1f\n", media);
    printf("Maior média de consumo: %.1f\n", maiorm);
    printf("Menor média de consumo: %.1f\n", menorm);
    printf("Viagens acima da média: %i\n", cont);

}
