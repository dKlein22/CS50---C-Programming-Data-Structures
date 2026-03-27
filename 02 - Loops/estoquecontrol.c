#include <cs50.h>
#include <stdio.h>

void print_anwser(int qtds, int adds, char rs);

int main(void)
{
    int f = 1;

    while (f == 1)
    {
        string prod = get_string("Produto: ");
        int qtd = get_int("Quantidade inicial: ");
        char r = get_char("(A) Adicionar ou (R) Retirar? ");
        int add = get_int("Quantidade: ");

        print_anwser(qtd, add, r);

        f = get_int("Continuar ? 1 - Sim / 2 - Não ");
    }

    printf("Programa encerrado!\n");
}


void print_anwser(int qtds, int adds, char rs)
{
    if (rs == 'A')
    {
        qtds = qtds + adds;
        printf("Novo estoque: %i\n", qtds);
    }
    else if (rs == 'R')
    {
        qtds = qtds - adds;
        printf("Novo estoque: %i\n", qtds);
    }
    else
    {
        printf("Erro! Estoque insuficiente\n");
    }
}




