#include <cs50.h>
#include <stdio.h>

#define Max 20

void bubblesort(float v[], int n, int *c);

int main(void)
{
    int n;

    n = get_int("Number of deliveries [Max is 20]: ");

    if (n > Max)
    {
        printf("Maximum deliveries is 20!\n");
        return 1;
    }

    float v[n];

    for (int i = 0; i < n; i++)
    {
        v[i] = get_float("Specify the delivery time %io: ", i + 1);
    }


    printf("Before sorting:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", v[i]);
    }
    printf("\n");

    int c;

    bubblesort(v, n, &c);

    printf("After sorting:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", v[i]);
    }
    printf("\n");

    printf("Were %i exchanges\n", c);

    float shortest = v[0];
    float longest = v[n - 1];
    float add = 0;
    float average = 0;

    for (int i = 0; i < n; i++)
    {
        add += v[i];
    }

    average = add/n;

    printf("The longest delivery time was:%.2f\n", longest);
    printf("The shortest delivery time was:%.2f\n", shortest);
    printf("The average time is:%.2f\n", average);
}

void bubblesort(float v[], int n, int *c)
{
    float aux;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;

                (*c)++;
            }
        }
    }
}
