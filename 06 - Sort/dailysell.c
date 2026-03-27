#include <cs50.h>
#include <stdio.h>

#define Max 10
#define CRESCENT 1
#define DESCENDING 0

void mergesort(float v[], int inicio, int fim, int ordem);
void merge(float v[], int inicio, int meio, int fim, int ordem);

int c = 0;

int main(void)
{
    int n = 0;
    n = get_int("How many sales do you want to register?");

    if (n > Max)
    {
        printf("The maximun number of records is 10!\n");
        return 1;
    }

    float v[n];
    float crescent[n];
    float descending[n];

    for (int i = 0; i < n; i++)
    {
        v[i] = get_float("What's the sale price %i:U$", i + 1);
        crescent[i] = v[i];
        descending[i] = v[i];
    }

    printf("\nBefore sorting:\n");
    for(int i = 0; i < n; i++)
    {
        printf("U$%.2f ", v[i]);
    }
    printf("\n");

    //Crescent order
    mergesort(crescent, 0, n - 1, CRESCENT);
    int ccrescent = c;

    //Descending order
    mergesort(descending, 0, n - 1, DESCENDING);
    int cdescending = c;

    printf("\nAscending order:\n");
    for (int i = 0; i < n; i++)
    {
        printf("U$%.2f ", crescent[i]);
    }
    printf("\nComparisons (ascending): %d\n", ccrescent);

    printf("\nDescending order:\n");
    for (int i = 0; i < n; i++)
    {
        printf("U$%.2f ", descending[i]);
    }
    printf("\nComparisons (descending): %d\n", cdescending);

    float cheap = crescent[0];
    float expensive = crescent[n - 1];
    float add = 0;
    float average = 0;

    for (int i = 0; i < n; i++)
    {
        add += crescent[i];
    }

    average = add / n;

    printf("\nThe expensive sale each was of:U$%.2f\n", expensive);
    printf("The cheapest sale each was of:U$%.2f\n", cheap);
    printf("The average sales is:U$%.2f\n", average);

    return 0;

}

void mergesort(float v[], int inicio, int fim, int ordem)
{
    int meio;
    if (inicio < fim)
    {
        meio = (fim + inicio) / 2;
        mergesort(v, inicio, meio, ordem);
        mergesort(v, meio + 1, fim, ordem);
        merge(v, inicio, meio, fim, ordem);
    }
}

void merge(float v[], int inicio, int meio, int fim, int ordem)
{
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    float l[n1];
    float r[n2];

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

        c++;

        if (ordem == CRESCENT)
        {
            if (l[i] <= r[j])
                v[k++] = l[i++];
            else
                v[k++] = r[j++];
        }
        else
        {
            if (l[i] >= r[j])
                v[k++] = l[i++];
            else
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

