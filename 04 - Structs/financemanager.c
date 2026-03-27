#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define Max 100

typedef struct
{
    char *describe;
    char *category;
    float value;
} expanse;

void addexpanse(expanse expansive[], int *n);
void listexpanses(expanse expansive[], int n);
void reported(expanse expensive[], int n);

int main(void)
{
    expanse expansive[Max];
    int op;
    int n = 0;

    do
    {
        printf("\n=========================MENU========================\n");
        op = get_int("1 - Add Expanse\n"
                     "2 - List expanses\n"
                     "3 - Report by category\n"
                     "4 - Exit\n"
                     "Choose your option:");

        if (op < 1 || op > 4)
        {
            printf("Attention! Invalid option\n");
        }

        printf("\n=====================================================\n");

        switch (op)
        {
            case 1:
                addexpanse(expansive, &n);
                break;

            case 2:
                listexpanses(expansive, n);
                break;

            case 3:
                reported(expansive, n);
                break;

        }

    } while (op != 4);

    printf("Program ending...\n");
    printf("\n=====================================================\n");
}

void addexpanse(expanse expansive[], int *n)
{
    printf("\n====================ADD=EXPANSIVE====================\n");
    printf("=====================================================\n");

    if (*n >= Max)
    {
        printf("Maximum limit reached!");
        return;
    }

    expansive[*n].category = get_string("Category:");
    expansive[*n].describe = get_string("Describe:");
    expansive[*n].value = get_float("Value:U$");
    (*n)++;

    printf("Expanse added successfully!\n");
    printf("=====================================================\n");

}

void listexpanses(expanse expansive[], int n)
{
    float sum = 0;

    printf("\n====================LIST=EXPANSIVE===================\n");
    printf("|=================|===================================\n");

    if (n <= 0)
    {
        printf("No additional expenses!\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        sum += expansive[i].value;

        printf(" Category: %s\n"
               " Descripition: %s\n"
               " Value: U$%.2f\n"
               "|=================|\n"
               , expansive[i].category, expansive[i].describe, expansive[i].value);

        if (expansive[i].value >= 100)
        {
            printf("He spent more than U$100.00 with: %s\n", expansive[i].describe);
        }
    }
    printf("Total expenses:U$%.2f\n", sum);
    printf("=====================================================\n");
}

void reported(expanse expensive[], int n)
{
    char *search;

    printf("\n==================REPORT=BY=CATEGORY=================\n");
    printf("=====================================================\n");
    search = get_string(" Specify the category: ");

    for (int i = 0; i < n; i++)
    {
        if (strcmp(search, expensive[i].category) == 0)
        {
            printf(" Category: %s\n"
               " Descripition: %s\n"
               " Value: U$%.2f\n"
               "|=================|\n"
               , expensive[i].category, expensive[i].describe, expensive[i].value);
        }
    }


}
