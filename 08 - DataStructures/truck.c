#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 30000
#define MAX_PLATE 10
const int MAX_WEIGHT = 30000;

typedef struct
{
    char plate[MAX_PLATE];
    float currentload;       //Estrutura de dados
    float capacity;
} truck;

truck **create_trk(int size); //Alocação e inicializacao de memoria
void register_truck(truck **trk, int size); //Registro da placa
void load_truck(truck *trk, float weight);  //Carregar o peso e verificacao
float *percent_load(truck **trk, int size); //Porcentagem de carga carregada
void most_load(truck **trk, int size); //Carga mais pesada
void overload(truck **trk, int size); //Porcentagem acima de 80%
void print_trk(truck **trk, int size, float *percent); //Impressao dos dados
void free_trk(truck **trk, int size, float *percent); //Liberação de toda memoria

int main(void)
{
    printf("====TRANSNICK=TRANSPORTES====\n");
    int size = get_int("How many trucks do you wish register? ");

    truck **trk;

    if (size > 0)
    {
        trk = create_trk(size);
    }
    else
    {
        printf("Enter a number greater than 0!\n");
        return 1;
    }

    register_truck(trk, size);

    float weight;
    printf("\n====LOAD=TRUCK'S====\n");
    printf("====================\n");
    for (int i = 0; i < size; i++)
    {
        printf("--------------------\n");
        printf("Plate Number: %s\n" , trk[i]->plate);
        printf("Maximum wight is: %i\n", MAX_WEIGHT);
        weight = get_float("Enter the weight of the load: ");
        load_truck(trk[i], weight);
    }

    float *percent = percent_load(trk, size);


    print_trk(trk, size, percent);

    overload(trk, size);

    most_load(trk, size);

    free_trk(trk, size, percent);

}






truck **create_trk(int size)
{
    truck **trk = malloc(size * sizeof(truck *));
    if (trk == NULL)
    {
        printf("It was not possible to allocate an array of pointers!\n");
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        trk[i] = malloc(sizeof(truck));
        if (trk[i] == NULL)
        {
            printf("It was not possible to allocate the truck structure!\n");
            exit(1);
        }

        trk[i]->capacity = MAX_CAPACITY;
        trk[i]->currentload = 0;
    }
    return trk;

}

void register_truck(truck **trk, int size)
{
    printf("\n====REGISTER=TRUCK====\n");
    printf("======================\n");
    for (int i = 0; i < size; i++)
    {
        char *tmp = get_string("Enter the truck's plate %io: ", i+1);
        snprintf(trk[i]->plate, sizeof(trk[i]->plate), "%s", tmp);
        printf("--------------------\n");
    }
}

void load_truck(truck *trk, float weight)
{
    if (trk->currentload + weight > trk->capacity)
    {
        printf("Maximum weight reached!\n");
        return;
    }

    trk->currentload += weight;
}

float *percent_load(truck **trk, int size)
{
    float *percent = malloc(size * sizeof(float));
    for (int i = 0; i < size; i++)
    {
        if (trk[i]->currentload == 0)
        {
            percent[i] = 0;
        }

        percent[i] = (trk[i]->currentload / trk[i]->capacity) * 100;
    }
    return percent;
}

void print_trk(truck **trk, int size, float *percent)
{
    printf("\n====LIST=TRUCKS====\n");
    printf("===================\n");

    float remaining[size];
    for (int i = 0; i < size; i++)
    {
        remaining[i] = trk[i]->capacity - trk[i]->currentload;
        printf("-------------------\n");
        printf("Truck's plate: %s\n"
               "Current load: %.2f\n"
               "Remaining capacity: %.2f\n"
               "Percent load: %.2f%%\n", trk[i]->plate, trk[i]->currentload, remaining[i], percent[i]);
    }
}

void overload(truck **trk, int size)
{
    float percent[size];

    printf("\n=====Greater=than=80%%=====\n");
    printf("==========================\n");
    for (int i = 0; i < size; i++)
    {
        percent[i] = (trk[i]->currentload / trk[i]->capacity) * 100;

        if (percent[i] > 80)
        {
             printf("--------------------------\n");
            printf("Plate number: %s\n"
                   "Percent load: %.2f\n", trk[i]->plate, percent[i]);
        }
    }
}

void most_load(truck **trk, int size)
{
    truck *most = trk[0];

    for (int i = 1; i < size; i++)
    {
        if (trk[i]->currentload > most->currentload)
        {
            most = trk[i];
        }

    }

    float percent = (most->currentload / most->capacity) * 100;

    printf("\n====MOST=LOAD====\n");
    printf("=================\n");
    printf("The most load truck is:\n");
    printf("Plate number: %s\n", most->plate);
    printf("Current load: %.2f\n"
           "Load percent: %.2f%%\n", most->currentload, percent);
    printf("=================\n");
}

void free_trk(truck **trk, int size, float *percent)
{
    for (int i = 0; i < size; i++)
    {
        if (trk[i] != NULL)
        {
            free(trk[i]);
            trk[i] = NULL;
        }
    }

    free(percent);
    percent = NULL;
    free(trk);
    trk = NULL;
}
