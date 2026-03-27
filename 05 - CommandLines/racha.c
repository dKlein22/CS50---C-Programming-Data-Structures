#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    if (argc < 3)
    {
        printf("Erro: Argumentos insuficientes.\n");
        printf("Uso: %s <valor_total> <pessoas> [gorjeta_opcional]\n", argv[0]);
        return 1;
    }

    float valor = atof(argv[1]);
    int pessoas = atoi(argv[2]);
    float gorjeta = 0;

    if (argc >= 4)
    {
        gorjeta = atof(argv[3]);
    }

    if (pessoas <= 0)
    {
        printf("Erro: Número de pessoas inválido.\n");
        return 1;
    }

    float valor_gorjeta = valor * (gorjeta / 100);
    float total_final = valor + valor_gorjeta;
    float por_pessoa = total_final / pessoas;


    printf("--- RESUMO ---\n");
    printf("Valor: R$ %-4.2f\n", valor);

    if (gorjeta > 0)
    {
        printf("Gorjeta (%.0f%%): R$ %-4.2f\n", gorjeta, valor_gorjeta);
        printf("Total Final: R$ %-4.2f\n", total_final);
    }

    printf("----------------\n");
    printf("Total a pagar por pessoa: R$ %-4.2f\n", por_pessoa);

    return 0;
}
