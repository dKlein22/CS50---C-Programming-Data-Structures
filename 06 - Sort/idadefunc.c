#include <cs50.h>
#include <stdio.h>

void selection(int v[], int n, int *c);

#define Max 20

int main(void)
{
    int n;

    n = get_int("Quantidade de funcionários: [Maximo é 20] ");
    if (n > 20)
    {
        printf("Quantidade máxima excedida!\n");
        return 1;
    }

    int v[n];

    for (int i = 0; i < n; i++)
    {
        v[i] = get_int("Informe a idade do funcionário[%i]:", i + 1);
    }

    printf("Antes da ordenação:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%i ", v[i]);
    }
    printf("\n");

    int c;
    selection(v, n, &c);

    printf("Após a ordenação:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%i ", v[i]);
    }
    printf("\n");

    printf("Houve %i trocas\n", c);

    int menor;
    int maiorq20 = 0;
    int maior;
    int par = 0;
    float soma = 0;
    float media;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > 20)
        {
            maiorq20++;
        }

        if (v[i] % 2 == 0)
        {
            par++;
        }

        soma += v[i];
    }

    media = soma/n;
    menor = v[0];
    maior = v[n - 1];

    printf("\nIdade do funcionário mais velho:%i\n", maior);
    printf("Idade do funcionário mais novo:%i\n", menor);
    printf("Funcionários com idade maior que 20:%i\n", maiorq20);
    printf("A soma da idade dos funcionários é:%.2f\n", soma);
    printf("A média de idade dos funcionários é:%.2f\n", media);
    printf("Idade de funcionários pares são:%i\n", par);

}

void selection(int v[], int n, int *c)
{
    int menor;
    int aux;

    for (int i = 0; i < n - 1; i++)
    {
        menor = i;

        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[menor])
            {
                menor = j;
            }
        }


        if (menor != i)
        {
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;

            (*c)++;

            printf("\nApós a troca %i\n", *c);
            for (int k = 0; k < n; k++)
            {
                printf("%i", v[k]);
            }
            printf("\n");
        }

    }
}
