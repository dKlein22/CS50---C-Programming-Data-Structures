#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 20
#define MAX_CHAR 50
typedef struct
{
    char action[MAX_STRINGS][MAX_CHAR];
    int top;
} operation;

void init(operation *o);
int isempty(operation *o);
int isfull(operation *o);
void push(operation *o, char *act);
char *pop(operation *o);
char *peek(operation *o);
void print_history(operation *o);

int main(void)
{
    int op;
    operation o;
    init(&o);

    do
    {
        op = get_int("1 - Register Operation\n"
                     "2 - Undo last operation\n"
                     "3 - Show last operation\n"
                     "4 - Show history\n"
                     "5 - Exit\n"
                     "Choice: ");

        if (op < 1 || op > 5)
        {
            printf("Incorrect choice! Select 1 to 5\n");
        }

        switch(op)
        {
            case 1:
            {
                char *act = get_string("Specify the operation you wish to perform: ");
                push(&o, act);
                printf("Operation register successfully!\n");
                free(act);
                break;
            }

            case 2:
            {
                char *undo = pop(&o);

                if (undo != NULL)
                {
                    printf("Last operation: %s\n", undo);
                    printf("Last operation successfully undone!\n");
                    free(undo);
                }

                break;
            }

            case 3:
            {
                char *last = peek(&o);

                if (last != NULL)
                {
                    printf("Last operation: %s\n", last);
                    free(last);
                }
                break;
            }

            case 4:
            {
                print_history(&o);
                break;
            }

            case 5:
            {
                printf("Ending program...\n");
            }
        }
    } while (op != 5);

}



void init(operation *o)
{
    o->top = -1;
}

int isempty(operation *o)
{
    return o->top == - 1;
}

int isfull(operation *o)
{
    return o->top == MAX_STRINGS - 1;
}

void push(operation *o, char *act)
{
    if (isfull(o))
    {
        printf("Full Stack!\n");
        return;
    }

    o->top++;
    strcpy(o->action[o->top], act);
}

char *pop(operation *o)
{
    if (isempty(o))
    {
        printf("Empty stack\n");
        return NULL;
    }

    char *value = malloc(MAX_CHAR);
    strcpy(value, o->action[o->top]);
    o->top--;

    return value;
}

char *peek(operation *o)
{
    if(isempty(o))
    {
        printf("Empty stack!\n");
        return NULL;
    }

    char *last = malloc(sizeof(MAX_CHAR));
    strcpy(last, o->action[o->top]);

    return last;
}

void print_history(operation *o)
{
    for (int i = o->top; i >= 0; i--)
    {
        printf("Actions: %s\n", o->action[i]);
    }
}
