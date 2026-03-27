#include <cs50.h>
#include <stdio.h>

void print_anwser(float sal, int sales);

int main(void)
{
    char f = 'Y';

    while (f == 'Y')
    {
        string name = get_string("Employee name : ");
        float sal = get_float("Base salary: U$");
        int sales = get_int("Sales in the month: ");

        print_anwser(sal, sales);

        f = get_char("Calculate another? (Y - Yes / N - No)");
    }

    printf("Ending...\n");
}

void print_anwser(float sal, int sales)
{
    if (sales <= 15)
    {
        float total = sal + sal*0.10;
        printf("Final salary: U$%.2f\n", total);
    }
    else if (sales > 15)
    {
        float total = sal + sal*0.15;
        printf("Final salary: U$%.2f\n", total);
    }
}
