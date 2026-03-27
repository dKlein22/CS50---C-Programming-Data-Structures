#include <cs50.h>
#include <stdio.h>

#define size 5

typedef struct
{
    int trucks[size];
    int front;
    int rear;
} queue;

void init(queue *q);
void enqueue(queue *q, int value);
int isfull(queue *q);
int isempty(queue *q);
int dequeue(queue *q);
void peek(queue *q);
void show(queue *q);

int main(void)
{
    int op;
    queue q;

    init(&q);

    do
    {
        op = get_int("1 - Arrival number\n"
                     "2 - Release truck\n"
                     "3 - First truck in line\n"
                     "4 - Show queue\n"
                     "5 - Exit\n"
                     "Choice: ");
        if (op < 0 || op > 5)
        {
            printf("Select correct option! 1 to 5\n");
        }

        switch(op)
        {
            case 1:
            {
                int value = get_int("Please provide the arrival number: ");
                enqueue(&q, value);
                break;
            }
            case 2:
            {
                int release = dequeue(&q);

                if (release != -1)
                {
                    printf("Number released: %i\n", release);
                }
                break;
            }
            case 3:
            {
                peek(&q);
                break;
            }
            case 4:
            {
                show(&q);
                break;
            }
            case 5:
            {
                printf("Ending program...\n");
                break;
            }
        }

    } while (op != 5);
}

void init(queue *q)
{
    q->front = 0;
    q->rear = -1;
}

int isfull(queue *q)
{
    return q->rear == size - 1;
}

int isempty(queue *q)
{
    return q->rear < q->front;
}

void enqueue(queue *q, int value)
{
    if (isfull(q))
    {
        printf("Full queue!\n");
        return;
    }

    q->rear++;
    q->trucks[q->rear] = value;
}

int dequeue(queue *q)
{
    if (isempty(q))
    {
        printf("Empty queue!\n");
        return -1;
    }

    int value = q->trucks[q->front];
    q->front++;

    return value;
}

void peek(queue *q)
{
    if (isempty(q))
    {
        printf("Empty queue!\n");
        return;
    }

    int first = q->trucks[q->front];

    printf("First number in queue: %i\n", first);
}

void show(queue *q)
{
    if (isempty(q))
    {
        printf("Empty queue!\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf(" |%i| ", q->trucks[i]);
    }
    printf("\n");
}
