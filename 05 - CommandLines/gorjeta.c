#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 3)
    {
        printf("Use: $./gorjeta (Valor da conta) (Porcentagem da gorjeta)\n");
        return 1;
    }

    float conta = atof(argv[1]);
    float porcentagem = atof(argv[2]);
    float gorjeta = conta * (porcentagem/100);
    float tot = 0;

    tot = conta + gorjeta;

    printf("Conta:R$%.2f\n"
            "Gorjeta (%.0f%%):R$%.2f\n"
            "Total a pagar:R$%2.f\n", conta, porcentagem, gorjeta, tot);

}

