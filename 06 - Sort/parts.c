#include <cs50.h>
#include <stdio.h>

#define Max 31

void insertionsort(int v[], int n, int *c, int *m);
void reverseinsertion(int v[], int n);

int main(void)
{
    int n;

    n = get_int("How many days, do you want analyze?");

    if (n > 31)
    {
        printf("Attention! The maximum number of days is 31\n");
        return 1;
    }

    int v[n];

    for(int i = 0; i < n; i++)
    {
        v[i] = get_int("How many parts, did you make on day %i:", i + 1);
    }

    printf("Before sorting:\n");

    for(int i = 0; i < n; i++)
    {
        printf("%i ", v[i]);
    }
    printf("\n");

    int c;
    int m;

    insertionsort(v, n, &c, &m);

    printf("After sorting:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%i ", v[i]);
    }
    printf("\n");

    reverseinsertion(v, n);

    int lowest = v[0];
    int highest = v[n - 1];
    int pair = 0;
    int sum = 0;
    float average;

    for (int i = 0; i < n; i++)
    {
        sum += v[i];

        if (v[i] % 2 ==0)
        {
            pair++;
        }
    }

    average = sum / n;

    printf("\nHighest recorded production:%i of parts\n", highest);
    printf("Lowest recorded production:%i of parts\n", lowest);
    printf("The total number of parts produced was:%i\n", sum);
    printf("The average number of parts produced was: %.2f\n", average);
    printf("The number of even-numbered parts pruduced is:%i\n", pair);
    printf("Were %i moviments\n", m);
    printf("Were %i comparisions\n", c);
}





void insertionsort(int v[], int n, int *c, int *m)
{
    int key;
    int j;
    int pass = 0;

    for (int i = 0; i < n; i++)
    {
        key = v[i];
        j = i - 1;

        while (j >= 0)
        {
            (*m)++;
            if (v[j] > key)
            {
                v[j + 1] = v[j];
                (*c)++;
                pass++;

                printf("\nAfter moving %i:\n", pass);
                for (int k = 0; k < n; k++)
                {
                    printf("%i ", v[k]);
                }
                printf("\n");
                j--;
            }
            else
            {
                break;
            }
        }

        v[j + 1] = key;
        (*c)++;
        pass++;

        printf("\nAfter moving %i (insertion):\n", pass);
        for (int k = 0; k < n; k++)
        {
            printf("%i ", v[k]);
        }
        printf("\n");

    }
}

void reverseinsertion(int v[], int n)
{
    printf("Arrays in reverse:\n");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%i ", v[i]);
    }
    printf("\n");
}
