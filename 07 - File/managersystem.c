#include <cs50.h>
#include <stdio.h>

#define MAX_NAME 50
#define MAX_LINE 256

typedef struct
{
    int id;
    char name[MAX_NAME];
    float price;

} PRODUCT;

int main(void)
{
    PRODUCT prod;
    int op;

    do
    {
        op = get_int("1 - Register product\n"
                     "2 - List product\n"
                     "3 - Search product by ID\n"
                     "4 - Exit\n"
                     "Choice: ");

        switch(op)
        {
            case 1:
            {
                FILE *input = fopen("register.txt", "a");
                if (input == NULL)
                {
                    printf("Could not open file!\n");
                    break;
                }

                prod.id = 0;
                FILE *count = fopen("register.txt", "r");
                char line[MAX_LINE];
                if (count != NULL)
                {
                    while (fgets(line, sizeof(line), count))
                    {
                        prod.id++;
                    }
                    fclose(count);
                }

                prod.id++;

                printf("ID: %i\n", prod.id);

                char *tmp = get_string("Product name: ");
                snprintf(prod.name, sizeof(prod.name), "%s", tmp);

                prod.price = get_float("Product price: U$");

                fprintf(input, "%i;%s;%.2f\n", prod.id, prod.name, prod.price);

                fclose(input);

                printf("Product registered successfully!\n");
                break;
            }

            case 2:
            {
                FILE *file = fopen("register.txt", "r");
                if (file == NULL)
                {
                    printf("No registers found!\n");
                    break;
                }

                char txt[MAX_LINE];

                while(fgets(txt, sizeof(txt), file) != NULL)
                {
                    int id;
                    char name[MAX_NAME];
                    float price;

                    sscanf(txt, "%i;%49[^;];%f\n", &id, name, &price);
                    printf("ID: %i | Product: %s | Price: U$%.2f\n", id, name, price);
                }

                fclose(file);
                break;
            }

            case 3:
            {
                int search_id = get_int("Enter product ID to search: ");

                FILE *search = fopen("register.txt", "r");
                if (search == NULL)
                {
                    printf("No registers found!\n");
                    break;
                }

                char txt[MAX_LINE];
                int found = 0;

                while (fgets(txt, sizeof(txt), search))
                {
                    int id;
                    char name[MAX_NAME];
                    float price;

                    sscanf(txt, "%i;%49[^;];%f", &id, name, &price);

                    if (id == search_id)
                    {
                        printf("Product found!\n");
                        printf("ID: %i | Product: %s | Price: U$%.2f\n",
                               id, name, price);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    printf("Product with ID %i not found.\n", search_id);
                }

                fclose(search);
                break;
            }

            case 4:
            {
                printf("Programming ending...\n");
                break;
            }
        }
    } while (op != 4);

    return 0;
}
