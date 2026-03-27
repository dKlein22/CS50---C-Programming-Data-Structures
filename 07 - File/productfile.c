#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXCHARACTER 256
#define MAXCHARNAME 50

typedef struct
{
    int id;
    char name[MAXCHARNAME];
    float price;

} PRODUCT;

int main(void)
{
    PRODUCT prod;
    int op;

    do
    {
        op = get_int("1 - Register Products\n"
                     "2 - List Products\n"
                     "3 - Exit\n"
                     "Choice: ");

        switch (op)
        {
            case 1:
            {
                FILE *input = fopen("products.txt", "a");
                if (input == NULL)
                {
                    printf("Could not open file!\n");
                    return 1;
                }


                prod.id = 0;

                FILE *count = fopen("products.txt", "r");
                char line[MAXCHARACTER];
                while (count && fegts(line, sizeof(line), count))
                {
                    prod.id++;
                }

                if(count != NULL)
                {
                    fclose(count);
                }

                prod.id++;

                printf("ID: %i\n", prod.id);

                char *tmp = get_string("Product name: "); //Arrays nao podem receber atribuicao
                snprintf(prod.name, sizeof(prod.name), "%s", tmp); //Cola os dados com segurança para a array

                prod.price = get_float("Product price: U$");

                fprintf(input, "%i;%s;%.2f\n", prod.id, prod.name, prod.price);

                fclose(input);
                printf("Product registered successfully!\n");

                break;
            }

            case 2:
            {
                FILE *file = fopen("products.txt", "r");
                if (file == NULL)
                {
                    printf("No registers found!\n");
                    return 2;
                }

                char txt[MAXCHARACTER];

                while(fgets(txt, sizeof(txt), file) != NULL)
                {
                    int id;
                    char name[MAXCHARNAME];
                    float price;

                    sscanf(txt, "%i;%49[^;];%f\n", &id, name, &price); //Transforma strings em dados
                    printf("ID: %i | Product: %s | Price: U$%.2f\n", id, name, price);
                }

                fclose(file);

                break;
            }

            case 3:
            {
                printf("Ending program...\n");

                break;
            }

            default:
            {
                printf("Invalid option\n");
            }

        }
    } while (op != 3);
}
