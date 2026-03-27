#include <cs50.h>
#include <stdio.h>

#define MAX 10

void quicksort(float v[], int inicio, int fim);
float partition(float v[], int inicio, int fim);
void swap(float *a, float *b);

int c;

int main(void)
{
    int n;
    n = get_int("How many points do you want register? [Maximum is 10]");

    if (n > MAX)
    {
        printf("The maximum points do you can register is 10\n");
        return 1;
    }

    float v[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = get_float("What was player %i's score?", i + 1);
    }
    printf("\n");

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%i-%.2f ", i + 1, v[i]);
    }
    printf("\n");

    quicksort(v, 0, n - 1);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%i-%.2f ", i + 1, v[i]);
    }
    printf("\n");

    printf("Number of comparisons made by quicksort:%i\n", c);

    float min = get_float("\nPlease specify the minimum score:\n");

    float big = v[0];
    float secondp = v[1];
    float add = 0;
    float average = 0;

    for (int i = 0; i < n; i++)
    {
        add += v[i];
    }

    average = add / n;

    printf("\nPlayers with a points equal to or greater than %.2f:\n", min);
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= min)
        {
            printf("Player %i: %.2f\n", i + 1, v[i]);
        }
    }

    printf("\nThe average points of player's: %.2f\n", average);
    printf("\n====RANKING====\n");
    printf("The first place: %.2f\n"
            "The second place: %.2f\n", big, secondp);

    if (n > 2)
    {
        float thirdp = v[2];
        printf("The third place: %.2f\n", thirdp);
    }


    return 0;
}




void quicksort(float v[], int inicio, int fim)
{
    if (inicio < fim)
    {
        float p = partition(v, inicio, fim);

        quicksort(v, inicio, p - 1);
        quicksort(v, p + 1, fim);
    }
}

float partition(float v[], int inicio, int fim)
{
    float pivot = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        c++;
        if (v[j] >= pivot)
        {
            i++;
            swap(&v[i], &v[j]);
        }
    }

    swap(&v[i + 1], &v[fim]);

    return i + 1;
}

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}
