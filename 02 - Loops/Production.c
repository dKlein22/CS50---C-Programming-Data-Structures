#include <cs50.h>
#include <stdio.h>

//Macros
#define DAYS 7;

//Protótipo
void print_anwser(int totdays, int plusday, int lessday, int dayplus, int dayless);
float print_cal(int totdays);

//Funcao principal
int main(void)
{
    int totdays = 0;
    int dayplus;
    int dayless;
    int plusday = 0;
    int lessday;

    for (int i = 1; i <= DAYS i++)
    {
        int week = get_int("Informe a produção do dia %i: ", i);
        printf("\n");

        totdays = totdays + week;

        if (week > plusday)
        {
            dayplus = i;
            plusday = week;
        }

        if (week < lessday)
        {
            dayless = i;
            lessday = week;
        }
    }

    print_anwser(totdays, plusday, lessday, dayplus, dayless);

    float salario = print_cal(totdays);

    printf("\n");
    printf("----Calculo Salarial----\n");
    printf("\n");
    printf("Salário base = R$500,00.\n"
        "Comissão por peça = R$2.00\n"
        "Salário bruto = R$%.2f\n"
        "Desconto de precidência = R$%.2f\n"
        "Total = R$%.2f\n", salario, salario*0.08, salario - salario*0.08);
}






void print_anwser(int totdays, int plusday, int lessday, int dayplus, int dayless)
{
    printf("----Desempenho da Produção----\n");
    printf("\n");
    printf("Total produzido na semana: %i\n", totdays);
    printf("Maior produção na semana: %i (Dia %i)\n", plusday, dayplus);
    printf("Menor produção na semana: %i (Dia %i)\n", lessday, dayless);

    if (totdays < 350)
    {
        printf("Desempenho abaixo do esperado!\n");
    }
    else if (totdays >= 350 && totdays < 500)
    {
        printf("Desempenho dentro da média!\n");
    }
    else if (totdays > 500)
    {
        printf("Excelente desempenho!\n");
    }
    else
    printf("Péssimo desempenho!\n");

}

float print_cal(int totdays)
{
    float salary = 500 + totdays*2;

    if (totdays < 350)
    {
        salary = salary - 50;
    }
    else if (totdays >= 350 && totdays < 500)
    {
        salary += 100;
    }
    else if (totdays > 500)
    {
        salary += 250;
    }
    return salary;
}
