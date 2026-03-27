#include <cs50.h>
#include <stdio.h>

typedef struct
{
    int id;
    float value;

} sell;

#define MAX 10

void showsales(sell v[], int n);
void mergesort(sell v[], int inicio, int fim);
void merge(sell v[], int inicio, int meio, int fim);


int main(void)
{
    int m = MAX;
    int n;
    sell v[MAX];

    do
    {
        n = get_int("How many sales do you want to register?");

        if (n == 0)
        {
            printf("Attention! Type more than 0\n");
            return 1;
        }

    } while (n == 0);


    if (n > MAX)
    {
        printf("Attention! The maximum number of register is %d\n", MAX);
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("====Sale %i:====\n", i + 1);
        v[i].id = get_int("ID: ");
        v[i].value = get_float("Value: U$");
    }

    printf("Sales before sorting:\n");
    showsales(v, n);
    printf("\n");

    mergesort(v, 0, n - 1);

    printf("Sales after sorting:\n");
    showsales(v, n);
    printf("\n");

    return 0;
}

void showsales(sell v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("ID: %i | Value: U$%.2f\n", v[i].id, v[i].value);
    }
}

void mergesort(sell v[], int inicio, int fim)
{
    int meio;
    if (inicio < fim)
    {
        meio = (fim + inicio)/2;
        mergesort(v, inicio, meio);
        mergesort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

void merge(sell v[], int inicio, int meio, int fim)
{
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    sell l[n1];
    sell r[n2];

    for (int i = 0; i < n1; i++)
    {
        l[i] = v[inicio + i];
    }
    for (int j = 0; j < n2; j++)
    {
        r[j] = v[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < n1 && j < n2)
    {
        if (l[i].value <= r[j].value)
        {
            v[k++] = l[i++];
        }
        else
        {
            v[k++] = r[j++];
        }

    }

    while (i < n1)
    {
        v[k++] = l[i++];
    }

    while (j < n2)
    {
        v[k++] = r[j++];
    }
}
