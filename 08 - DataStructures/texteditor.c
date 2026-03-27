#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char *action;
    struct stack *next;
} stack;

stack *top = NULL;

void push(char *action);
char *pop();
void peek();
void print_history();
void clear_stack();

int main(void)
{
    int op;

    do
    {
        op = get_int("1 - Add edit\n"
                     "2 - Undo edit\n"
                     "3 - Show last edit\n"
                     "4 - Show edit history\n"
                     "5 - Exit\n"
                     "Choice: ");

        if (op < 0 || op > 5)
        {
            printf("Select the correct option! 1 to 5\n");
        }

        switch (op)
        {
            case 1:
            {
                char *action = get_string("Edit: ");
                push(action);

                break;
            }

            case 2:
            {
                char *undo = pop();
                if (undo != NULL)
                {
                     printf("Undo: %s\n", undo);
                    free(undo);
                }


                break;
            }

            case 3:
            {
                peek();
                break;
            }

            case 4:
            {
                print_history();
                break;
            }

            case 5:
            {
                printf("Program eding...\n");
                break;
            }
        }

    } while (op != 5);

    clear_stack();
}

void push(char *action)
{
    stack *new = malloc(sizeof(stack));
    if (new == NULL)
    {
        printf("Error!\n");
        return;
    }

    new->action = malloc(strlen(action) + 1);
    strcpy(new->action, action);

    new->next = top;
    top = new;
}

char *pop()
{
    if (top == NULL)
    {
        printf("Empty stack!\n");
        return NULL;
    }

    stack *tmp = top;

    char *action = malloc(strlen(tmp->action) + 1);
    strcpy(action, tmp->action);

    top = top->next;

    free(tmp->action);
    free(tmp);

    tmp = NULL;

    return action;
}

void peek()
{
    if (top == NULL)
    {
        printf("Empty stack!\n");
        return;
    }

    printf("Last edit: %s\n", top->action);
}

void print_history()
{
    if (top == NULL)
    {
        printf("No history available\n");
        return;
    }

    stack *tmp = top;

    printf("History:\n");

    while (tmp != NULL)
    {
        printf("%s\n", tmp->action);
        tmp = tmp->next;
    }

}

void clear_stack()
{
    stack *tmp;

    while (top != NULL)
    {
        tmp = top;
        top = top->next;

        free(tmp->action);
        free(tmp);
    }
}
