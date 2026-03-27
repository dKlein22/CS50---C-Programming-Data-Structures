#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 50

typedef struct node
{
    int id;
    char name[MAX_CHAR];
    int priority;
    struct node *next;
} node;

typedef struct
{
    node *front;
    node *rear;
} queue;

void init(queue *q);
void enqueue(queue *q, int id, char name[], int pri);
void dequeue(queue *q);
void showqueue(queue *q);
void search(queue *q, int id);
void clear_queue(queue *q);

int main(void)
{
    int op;
    queue q;
    init(&q);

    do
    {
        op = get_int("1 - Add costumer\n"
                     "2 - Serve costumer\n"
                     "3 - Show queue\n"
                     "4 - Search for costumer\n"
                     "5 - Exit\n"
                     "Choice: ");

        if (op < 0 || op > 5)
        {
            printf("Select correct order! 1 to 5\n");
            continue;
        }

        switch (op)
        {
            case 1:
            {
                int id = get_int("ID: ");
                char *name = get_string("Name: ");
                int pri = get_int("Priority (1 - Urgent | 2 - Normal): ");

                if (pri < 1 || pri > 2)
                {
                    printf("Select correct order! 1 or 2\n");
                    return 1;
                }

                enqueue(&q, id, name, pri);
                printf("Add costumer!\n");
                free(name);
                break;
            }

            case 2:
            {
                dequeue(&q);
                break;
            }

            case 3:
            {
                showqueue(&q);
                break;
            }

            case 4:
            {
                int id = get_int("Provide the costumer ID: ");
                search(&q, id);
                break;
            }

            case 5:
            {
                printf("Program ending...\n");
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

void enqueue(queue *q, int id, char name[], int pri)
{
    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Memory error!\n");
        return;
    }

    new->id = id;
    snprintf(new->name, sizeof(new->name), "%s", name);
    new->priority = pri;
    new->next = NULL;

    if (q->rear == NULL)
    {
        q->front = new;
        q->rear = new;
        return;
    }

    if (pri == 1)
    {
        node *tmp = q->front;
        q->front = new;
        q->front->next = tmp;
        return;
    }

    q->rear->next = new;
    q->rear = new;
}

void dequeue(queue *q)
{
    if (q->front == NULL)
    {
        printf("Empty queue!\n");
        return;
    }

    node *tmp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    printf("ID: %i\n"
           "Name: %s\n"
           "Priority: %i\n", tmp->id, tmp->name, tmp->priority);

    free(tmp);
}

void showqueue(queue *q)
{
    if (q->front == NULL)
    {
        printf("Empty queue!\n");
        return;
    }

    node *tmp = q->front;

    printf("QUEUE:\n");
    while (tmp != NULL)
    {
        printf("ID: %i\n"
               "Name: %s\n"
               "Priority: %i\n", tmp->id, tmp->name, tmp->priority);

        tmp = tmp->next;
    }
}

void search(queue *q, int id)
{
    if (q->front == NULL)
    {
        printf("Empty queue!\n");
        return;
    }

    node *tmp = q->front;

    while (tmp != NULL)
    {
        if (id == tmp->id)
        {
            printf("Costumer find!\n");
            printf("ID: %i\n"
                   "Name: %s\n"
                   "Priority: %i\n", tmp->id, tmp->name, tmp->priority);
            return;

            tmp = tmp->next;
        }
     }

    printf("Costumer not found!\n");
}

void clear_queue(queue *q)
{
    node *tmp;

    while (q->front != NULL)
    {
        tmp = q->front;
        q->front = q->front->next;
        free(tmp);
        tmp = NULL;
    }
}
