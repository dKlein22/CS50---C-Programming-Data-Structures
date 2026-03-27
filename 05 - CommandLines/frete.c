#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 4) {
        printf("Uso correto: %s <peso_kg> <distancia_km> <tipo>\n", argv[0]);
        printf("Tipos: R (Rodoviário), E (Expresso), C (Econômico)\n");
        return 1;
    }

    float peso = atof(argv[1]);
    float distancia = atof(argv[2]);

    char tipo = argv[3][0];
    float tarifa;

    if (tipo == 'R' || tipo == 'r')
    {
        tarifa = 0.12;
    }
    else if (tipo == 'E' || tipo == 'e')
    {
        tarifa = 0.20;
    }
    else if (tipo == 'C' || tipo == 'c')
    {
        tarifa = 0.08;
    }
    else
    {
        printf("Erro: tipo de transporte invalido. Use R, E ou C.\n");
        return 1;
    }

    float valor = peso * distancia * tarifa;

    if (tipo == 'R' || tipo == 'r')
        {
            printf("Frete rodoviário calculado: R$ %.2f\n", valor);
        }
    else if (tipo == 'E' || tipo == 'e')
        {
            printf("Frete expresso calculado: R$ %.2f\n", valor);
        }
    else
        {
            printf("Frete economico calculado: R$ %.2f\n", valor);
        }

    return 0;
}

