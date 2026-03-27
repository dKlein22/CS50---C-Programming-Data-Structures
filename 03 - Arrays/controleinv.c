#include <cs50.h>
#include <stdio.h>

void switch_chosen(int chosen, int prod, string name_prod[], int estoque_prod[]);

int main(void)
{
    const int prod = 4;
    string nomes_prod[] = {"Processador", "Placa de Video", "SSD 1TB", "Memoria RAM 16GB"};
    int estoque_prod[] = {10, 5, 20, 15};

    int chosen;

    printf("==========Controle de Estoque==========\n");
    printf("===========================================\n\n");

    do
    {
        chosen = get_int("1. Listar inventário\n"
                            "2. Registrar entrada\n"
                            "3. Registrar saida\n"
                            "4. Sair\n");
        printf("===========================================\n\n");

        if (chosen < 1 || chosen > 4)
        {
            printf("Selecionar as opções enrtre 1 e 4\n");
        }

        printf("===========================================\n\n");

        switch_chosen(chosen, prod, nomes_prod, estoque_prod);

    }
    while (chosen != 4);

}


void switch_chosen(int chosen, int prod, string nomes_prod[], int estoque_prod[])
{
     switch (chosen)
        {
            case 1:

                printf("=============Estoque da loja==============\n");
                for (int i = 0; i < prod; i++)
                {
                printf("%-20s | %-2i UNIDADES\n", nomes_prod[i], estoque_prod[i]);
                }
                printf("===========================================\n");
                break;

            case 2:

                printf("============Registro de Entrada============\n");
                int questionadd = get_int("Qual produto deseja adicionar?\n"
                                "[1] Processador\n"
                                "[2] Placa de Video\n"
                                "[3] SSD 1TB\n"
                                "[4] Memoria RAM 16GB\n");

                printf("===========================================\n");
                printf("___________________________________________\n");

                if (questionadd == 1)
                {
                    int add = get_int("Quantas unidades deseja adicionar de %s?\n", nomes_prod[0]);
                    estoque_prod[0] += add;
                }

                if (questionadd == 2)
                {
                    int add = get_int("Quantas unidades deseja adicionar de %s?\n", nomes_prod[1]);
                    estoque_prod[1] += add;
                }

                if (questionadd == 3)
                {
                    int add = get_int("Quantas unidades deseja adicionar de %s?\n", nomes_prod[2]);
                    estoque_prod[2] += add;
                }

                if (questionadd == 4)
                {
                    int add = get_int("Quantas unidades deseja adicionar de %s?\n", nomes_prod[3]);
                    estoque_prod[3] += add;
                }

                printf("===========================================\n");
                break;

            case 3:

                printf("============Registro de Saida============\n");
                int questionless = get_int("Qual produto deseja retirar?\n"
                                "[1] Processador\n"
                                "[2] Placa de Video\n"
                                "[3] SSD 1TB\n"
                                "[4] Memoria RAM 16GB\n");

                printf("===========================================\n");
                printf("___________________________________________\n");

                if (questionless == 1)
                {
                    int less = get_int("Quantas unidades deseja retirar de %s?\n", nomes_prod[0]);
                    estoque_prod[0] -= less;
                }

                if (questionless == 2)
                {
                    int less = get_int("Quantas unidades deseja retirar de %s?\n", nomes_prod[1]);
                    estoque_prod[1] -= less;
                }

                if (questionless == 3)
                {
                    int less = get_int("Quantas unidades deseja retirar de %s?\n", nomes_prod[2]);
                    estoque_prod[2] -= less;
                }

                if (questionless == 4)
                {
                    int less = get_int("Quantas unidades deseja retirar de %s?\n", nomes_prod[3]);
                    estoque_prod[3] -= less;
                }

                printf("===========================================\n");
                break;

        }
}
