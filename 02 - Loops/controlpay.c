#include <stdio.h>
#include <cs50.h>


void print_anwser(string name, float salario, int HR);

int main(void)
{
    int F = get_int("Quantos funcionários deseja cadastrar? ");

    string name;
    float salario;
    int HR;
    float re = 0;

    for(int i = 0; i < F; i++)
    {
        printf("----Funcionário %i----\n", i+1);
        name = get_string("Nome: ");
        salario = get_float("Salário base: R$ ");
        HR = get_int("Horas extras: ");

        print_anwser(name, salario, HR);

        re = re + salario+(HR*25);
    }

    printf("Total gasto pela empresa: R$%.3f\n", re);

}

void print_anwser(string name, float salario, int HR)
{
    printf("-----------------------------\n");
    float r = salario + HR*25;
    printf("Nome: %s\n"
        "Salário base: R$%.3f\n"
        "Horas extras: %i\n"
        "Total a receber: %.3f\n", name, salario, HR, r);
    printf("-----------------------------\n");

    if (r > 5000)
    {
        printf("Funcionário %s recebe acima da média\n", name);
    }
}

