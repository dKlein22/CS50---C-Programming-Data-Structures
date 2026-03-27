#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int semana = 7;
    float vendas[7];
    float soma = 0;
    float maior = 0;
    string dia[7] = {"Segunda-Feira", "Terça-Feira", "Quarta-Feira", "Quinta-Feira", "Sexta-Feira", "Sabado", "Domingo" };
    string melhordia;

    printf("----Vendas da Semana----\n");

    for (int i = 0; i < semana; i++)
    {
        vendas[i] = get_float("Informe o valor da venda de %s: R$", dia[i]);

        soma += vendas[i];

        if (vendas[i] > maior)
        {
            maior = vendas[i];
            melhordia = dia[i];
        }
    }

    printf("\n");
    printf("----Relatório----\n");
    printf("Total de vendas foi: R$%.2f\n", soma);
    printf("O dia com maior venda foi: %s\n", melhordia);
    printf("\n");

    if (soma > 1000)
    {
        printf("Semana Lucrativa!\n");
    }
    else
    {
        printf("Precisamos vender mais!!!\n");
    }
}
