#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 11
#define MAX_CODE 20
#define MAX_CLIENT 50
#define MAX_STATUS 30

typedef struct node
{
    char code[MAX_CODE];
    char client[MAX_CLIENT];
    char status[MAX_STATUS];
    float weight;
    struct node *next;
} node;

node *table[SIZE];

void init();
int hash(char *code);
void add(char *code, char *client, char *status, float weight);
void search(char *code);
void n_status(char *code, char *update);
void removed(char *code);
void print();
void free_all();

int main(void)
{
    int op;
    init();

    do
    {
        op = get_int("1 - Add Delivery\n"
                     "2 - Search delivery\n"
                     "3 - Update status\n"
                     "4 - Remove delivery\n"
                     "5 - Print all deliverys\n"
                     "6 - Exit\n"
                     "Choice: ");
        if (op < 1 || op > 6)
        {
            printf("Select correct option! 1 to 5\n");
            continue;
        }

        switch(op)
        {
            case 1:
            {
                char *code = get_string("CODE: ");
                char *client = get_string("NAME: ");
                char *status = get_string("STATUS (Delivered | Pending | Do no deliver): ");
                float weight = get_float("WEIGHT: ");
                add(code, client, status, weight);
                printf("Delivery added successfully!\n");
                break;
            }

            case 2:
            {
                char *code = get_string("Provide the product code: ");
                search(code);
                break;
            }

            case 3:
            {
                char *code = get_string("Provide the product code: ");
                char *update = get_string("UPDATE STATUS (Delivered | Pending | Do no deliver): ");
                n_status(code, update);
                break;
            }

            case 4:
            {
                char *code = get_string("Provide the product code: ");
                removed(code);
                break;
            }

            case 5:
            {
                print();
                break;
            }

            case 6:
            {
                printf("Program ending...");
                break;
            }
        }
    } while (op != 6);

    free_all();

}

void init()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = NULL;
    }
}

int hash(char *code)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *code++))
    {
        hash = hash * 33 + c;
    }

    return hash % SIZE;
}

void add(char *code, char *client, char *status, float weight)
{
    int index = hash(code);

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Memory error!\n");
        return;
    }

    snprintf(n->code, sizeof(n->code), "%s", code);
    snprintf(n->client, sizeof(n->client), "%s", client);
    snprintf(n->status, sizeof(n->status), "%s", status);
    n->weight = weight;

    n->next = table[index];
    table[index] = n;

}

void search(char *code)
{
    int index = hash(code);

    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcmp(cursor->code, code) == 0)
        {
            printf("Found delivery!\n");
            printf("CODE: %s\n"
                   "NAME: %s\n"
                   "STATUS: %s\n"
                   "WEIGHT: %.2f\n", cursor->code, cursor->client, cursor->status, cursor->weight);

            return;
        }

        cursor = cursor->next;
    }

    printf("Delivery not found!\n");
}

void n_status(char *code, char *update)
{
    int index = hash(code);

    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcmp(cursor->code, code) == 0)
        {
            snprintf(cursor->status, sizeof(cursor->status), "%s", update);
            printf("Update delivery\n");
            printf("CODE: %s\n"
                   "NAME: %s\n"
                   "STATUS: %s\n"
                   "WEIGHT: %.2f\n", cursor->code, cursor->client, cursor->status, cursor->weight);

            return;
        }

        cursor = cursor->next;
    }

    printf("Delivery not found!\n");
}

void removed(char *code)
{
    int index = hash(code);

    node *cursor = table[index];
    node *prev = NULL;

    while (cursor != NULL)
    {
        if (strcmp(cursor->code, code) == 0)
        {
            if (prev == NULL)
            {
                table[index] = cursor->next;
            }
            else
            {
                prev->next = cursor->next;
            }

            free(cursor);
            printf("Delivery successfully removed!\n");
            return;
        }

        prev = cursor;
        cursor = cursor->next;
    }

    printf("It was not possible to remove the delivery!\n");
}

void print()
{
    for (int i = 0; i < SIZE; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            printf("CODE: %s\n"
                   "NAME: %s\n"
                   "STATUS: %s\n"
                   "WEIGHT: %.2f\n", cursor->code, cursor->client, cursor->status, cursor->weight);

            cursor = cursor->next;
        }
    }
}

void free_all()
{
    for (int i = 0; i < SIZE; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

        table[i] = NULL;
    }
}
