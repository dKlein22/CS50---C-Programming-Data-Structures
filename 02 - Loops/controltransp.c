#include <cs50.h>
#include <stdio.h>

void print_moto(string name, int entrega, float totrecebe);

int main(void)
{
    printf("----Controle de Entregas----\n");

    int M = get_int("Quantos motoristas deseja cadastrar? ");

    string name;
    int entrega;
    float totrecebe = 0;
    float tot = 0;

    for(int i = 0; i < M; i++)
    {
        printf("----Motorista %i----\n", i+1);

        name = get_string("Nome do motorista: ");
        entrega = get_int("Quantidade de entregas: ");

        totrecebe = entrega*12;

        if (entrega > 50)
        {
            totrecebe += 300;
        }

        print_moto(name, entrega, totrecebe);

        tot = tot + totrecebe;

    }


    printf("==========================\n");
    printf("Custo total da transportadora: R$%.2f\n", tot);
    printf("==========================\n");
}

void print_moto(string name, int entrega, float totrecebe)
{
    printf("Nome: %s\n"
        "Entregas: %i\n", name, entrega);

    printf("----Pagamentos----\n");

    printf("%s recebera: %.1f\n", name, totrecebe);

}
