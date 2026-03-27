#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 50
#define MAX_PHONE 20

typedef struct
{
    int code;
    char name[MAX_CHAR];
    char phone[MAX_PHONE];
} customer;

void registercustomer();
void listcustomers();
void searchcustomer();
void updatephone();

int main(void)
{
    int op;

    do
    {
        op = get_int("\n1 - Register a customer\n"
                     "2 - List customers\n"
                     "3 - Search customer by code\n"
                     "4 - Update a phone number\n"
                     "5 - Exit\n"
                     "Choice: ");

        switch (op)
        {
            case 1:
            {
                registercustomer();
                break;
            }
            case 2:
            {
                listcustomers();
                break;
            }
            case 3:
            {
                searchcustomer();
                break;
            }
            case 4:
            {
                updatephone();
                break;
            }
            case 5:
            {
                printf("Ending program...\n");
                break;
            }
            default:
            {
                printf("Invalid option!(1 a 5)\n");
                break;
            }
        }
    }
    while (op != 5);
}

void registercustomer()
{
    printf("\nRegister\n");
    customer ct;

    ct.code = 0;

    FILE *count = fopen("customer.dat", "rb");

    if (count != NULL)
    {
        fseek(count, 0, SEEK_END);
        long size = ftell(count);
        ct.code = size / sizeof(customer) + 1;
        fclose(count);
    }
    else
    {
        ct.code = 1;
    }

    printf("Code customer: %i\n", ct.code);

    char *tmp = get_string("Name: ");
    snprintf(ct.name, sizeof(ct.name), "%s", tmp);
    char *tmp2 = get_string("Phone number: ");
    snprintf(ct.phone, sizeof(ct.phone), "%s", tmp2);

    FILE *input = fopen("customer.dat", "ab");
    if (input == NULL)
    {
        printf("Could no open file!\n");
        return;
    }

    fwrite(&ct, sizeof(customer), 1, input);

    printf("Register annottation succesfully!\n");

    fclose(input);
}

void listcustomers()
{
    printf("\nList\n");

    customer ct;
    FILE *list = fopen("customer.dat", "rb");
    if (list == NULL)
    {
        printf("No records found!\n");
        return;
    }

    while (fread(&ct, sizeof(customer), 1, list))
    {
        printf("Code: %i\n", ct.code);
        printf("Name: %s\n", ct.name);
        printf("Phone number: %s\n", ct.phone);
    }

    fclose(list);
}

void searchcustomer()
{
    printf("\nSearch by Code\n");

    customer ct;
    int searchcode = get_int("Enter the code you wish to search: ");

    FILE *search = fopen("customer.dat", "rb");
    if (search == NULL)
    {
        printf("Could no open file!\n");
        return;
    }

    int found = 0;

    while (fread(&ct, sizeof(customer), 1, search))
    {
        if (searchcode == ct.code)
        {
            printf("Code found\n");
            printf("Code: %i\n", ct.code);
            printf("Name: %s\n", ct.name);
            printf("Phone number: %s\n", ct.phone);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Code not found, try another!\n");
    }

    fclose(search);
}

void updatephone()
{
    printf("\nUpdate Phone Number\n");

    customer ct;
    int code = get_int("Enter the code customer: ");

    FILE *update = fopen("customer.dat", "rb+");
    if (update == NULL)
    {
        printf("Could no open file!\n");
        return;
    }

    int found = 0;

    while(fread(&ct, sizeof(customer), 1, update))
    {
        if (ct.code == code)
        {
            char *tmp = get_string("New phone: ");
            snprintf(ct.phone, sizeof(ct.phone), "%s", tmp);

            fseek(update, -sizeof(customer), SEEK_CUR);
            fwrite(&ct, sizeof(customer), 1, update);

            printf("Update phone number!\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Customer not found!\n");
    }


    printf("Customer not found!\n");
    fclose(update);
}
