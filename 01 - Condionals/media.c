#include <cs50.h>
#include <stdio.h>

void print_media(float Av1, float Av2);

int main(void)
{
    float A1;
    float A2;
    do
    {
        A1 = get_float("Digite a nota da A1: ");
        A2 = get_float("Digite a nota da A2: ");
    }
    while (A1 < 1 || A2 < 1);

    print_media(A1, A2);
}

void print_media(float Av1, float Av2)
{
    float M = (Av1 + Av2)/2;
    if (M >= 7)
    {
        printf("Média:%.2f\n", M);
        printf("Aprovado!\n");
    }
    else if (M >= 5)
    {
        printf("Média:%.2f\n", M);
        printf("Recuperação!\n");
    }
    else
    {
        printf("Média:%.2f\n", M);
        printf("Reprovado!\n");
    }
}
