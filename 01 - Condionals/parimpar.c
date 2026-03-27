#include <cs50.h>
#include <stdio.h>

void print_imparpar(int number);

int main(void)
{
    int N;
    do
    N = get_int("Digite um número: ");
    while (N < 1);

    print_imparpar(N);
}

void print_imparpar(int number)
{
    if (number % 2 == 0)
    {
        printf("O número %i é par!\n", number);
    }
    else
    {
        printf("O número %i é impar!\n", number);
    }

}
