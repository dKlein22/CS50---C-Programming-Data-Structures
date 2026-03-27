#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct node
{
    int id;
    char name[MAX];
    struct node *next;
} node;

typedef struct
{
    node *front;
    node *rear;
}queue;

void init(queue *q);
void enqueue(queue *q, char name[], int id);
char *dequeue(queue *q);
void peek(queue *q);
void show(queue *q);
void clear_queue(queue *q);

int main(void)
{
    int op;
    queue q;
    init(&q);

    do
    {
        printf("=====================\n");
        op = get_int("1 - Add patient\n"
                     "2 - Call next patient\n"
                     "3 - Show next patient\n"
                     "4 - Show queue\n"
                     "5 - Exit\n"
                     "Choice: ");
        printf("=====================\n");

        if (op < 0 || op > 5)
        {
            printf("Select correct option! 1 to 5\n");
        }

        switch(op)
        {
            case 1:
            {
                printf("=====================\n");
                char *name = get_string("Name: ");
                int id = get_int("%s ID: ", name);
                enqueue(&q, name, id);
                printf("=====================\n");
                printf("Success adition!\n");
                printf("=====================\n");
                break;
            }

            case 2:
            {
                char *next = dequeue(&q);
                printf("=====================\n");
                if (next != NULL)
                {
                    printf("%s\n", next);
                }
                printf("=====================\n");
                break;
            }

            case 3:
            {
                printf("=====================\n");
                peek(&q);
                printf("=====================\n");
                break;
            }

            case 4:
            {
                printf("=====================\n");
                show(&q);
                printf("=====================\n");
                break;
            }

            case 5:
            {
                printf("Ending program...\n");
                break;
            }
        }

    } while (op != 5);

    clear_queue(&q);
}

void init(queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(queue *q, char name[], int id)
{
    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Error memory!\n");
        return;
    }

    new->id = id;
    snprintf(new->name, sizeof(new->name), "%s", name);
    new->next = NULL;

    if (q->rear == NULL)
    {
        q->front = new;
        q->rear = new;
        return;
    }

    q->rear->next = new;
    q->rear = new;
}

char *dequeue(queue *q)
{
    if (q->front == NULL)
    {
        printf("Empty queue!\n");
        return NULL;
    }

    node *tmp = q->front;
    char *name = malloc(MAX);
    snprintf(name, MAX, "%s", tmp->name);

    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(tmp);

    return name;
}

void peek(queue *q)
{
    if (q->front == NULL)
    {
        printf("Empty queue!\n");
        return;
    }

    printf("Next patient: %s\n"
           "ID: %i\n", q->front->name, q->front->id);
}

void show(queue *q)
{
    if (q->front == NULL)
    {
        printf("Empty queue!\n");
        return;
    }

    node *tmp = q->front;

    printf("Queue:\n");

    while (tmp != NULL)
    {
        printf("Name: %s | ID: %i\n", tmp->name, tmp->id);
        tmp = tmp->next;
    }
}

void clear_queue(queue *q)
{
    node *tmp;

    while (q->front != NULL)
    {
        tmp = q->front;
        q->front = q->front->next;
        free(tmp);
    }
}
