#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct node
{
    char action[MAX];
    struct node *next;
    struct node *prev;
} node;

void add(node **current, char action[]);
void undo(node **current);
void redo(node **current);
void show_history(node *current);
void show_current(node *current);
void free_all(node *current);

int main(void)
{
    int op;
    node *current = NULL;

    do
    {
        op = get_int("1 - Action register\n"
                     "2 - Undo action\n"
                     "3 - Redo action\n"
                     "4 - Show history\n"
                     "5 - Show current\n"
                     "6 - Exit\n"
                     "Choice: ");

        if (op < 1 || op > 6)
        {
            printf("Select correct option! 1 to 5\n");
            continue;
        }

        switch (op)
        {
            case 1:
            {
                char *action = get_string("Register action: ");
                add(&current, action);
                printf("Register added successfully\n");
                free(action);
                break;
            }

            case 2:
            {
                undo(&current);
                break;
            }

            case 3:
            {
                redo(&current);
                break;
            }

            case 4:
            {
                show_history(current);
                break;
            }

            case 5:
            {
                show_current(current);
                break;
            }

            case 6:
            {
                printf("Program ending...\n");
                break;
            }
        }
    }
    while (op != 6);

    free_all(current);
}

void add(node **current, char action[])
{
    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Memory error!\n");
        return;
    }

    snprintf(new->action, sizeof(new->action), "%s", action);
    new->next = NULL;
    new->prev = NULL;

    if (*current == NULL)
    {
        *current = new;
        return;
    }

    node *tmp = (*current)->next;

    while (tmp != NULL)
    {
        node *delete = tmp;
        tmp = tmp->next;
        free(delete);
    }

    (*current)->next = NULL;

    new->prev = *current;
    (*current)->next = new;
    *current = new;
}

void undo(node **current)
{
    if (*current == NULL || (*current)->prev == NULL)
    {
        printf("Nothing to undo!\n");
        return;
    }

    *current = (*current)->prev;

    printf("Previous register: %s\n", (*current)->action);
}

void redo(node **current)
{
    if (*current == NULL || (*current)->next == NULL)
    {
        printf("Nothing to redo!\n");
        return;
    }

    *current = (*current)->next;

    printf("Next register: %s\n", (*current)->action);
}

void show_history(node *current)
{
    node *tmp = current;

    while (tmp->prev != NULL)
    {
        tmp = tmp->prev;
    }

    while (tmp != NULL)
    {
        printf("%s", tmp->action);

        if (tmp == current)
            printf("  <-- CURRENT");

        printf("\n");

        tmp = tmp->next;
    }
}

void show_current(node *current)
{
    if (current == NULL)
    {
        printf("Empty registers!\n");
        return;
    }

    printf("Current register is: %s\n", current->action);
}

void free_all(node *current)
{
    if (current == NULL) return;

    while (current->prev != NULL)
    {
        current = current->prev;
    }

    node *tmp;
    while (current != NULL)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
}
