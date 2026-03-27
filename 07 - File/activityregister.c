#include <cs50.h>
#include <stdio.h>
#include <strings.h>

#define MAX_LINE 256
#define MAX_CHAR 50
#define MAX_ACTION 100

int main(void)
{
    int op;

    do
    {
        op = get_int("1 - Register actions\n"
                     "2 - List logs\n"
                     "3 - Search by user\n"
                     "4 - Exit\n"
                     "Choice:");

        switch(op)
        {
            case 1:
            {
                FILE *input = fopen("logs.txt", "a");
                if (input == NULL)
                {
                    printf("Could not open file!\n");
                    break;
                }

                int id = 0;
                FILE *count = fopen("logs.txt", "r");
                char line[MAX_LINE];
                if (count != NULL)
                {
                    while (fgets(line, sizeof(line), count))
                    {
                        id++;
                    }
                    fclose(count);
                }

                id++;

                printf("ID: %i\n", id);
                char name[MAX_CHAR];
                char action[MAX_ACTION];

                char *tmp1 = get_string("User: ");
                snprintf(name, sizeof(name), "%s", tmp1);
                char *tmp2 = get_string("Action: ");
                snprintf(action, sizeof(action), "%s", tmp2);

                fprintf(input, "%i | %s | %s\n", id, name, action);

                fclose(input);

                printf("Register successfully!\n");

                break;
            }
            case 2:
            {
                FILE *list = fopen("logs.txt", "r");
                if (list == NULL)
                {
                    printf("No registers found!\n");
                    break;
                }

                char txt[MAX_LINE];

                while(fgets(txt, sizeof(txt), list))
                {
                    int id;
                    char name[MAX_CHAR];
                    char action[MAX_ACTION];

                    sscanf(txt, "%i | %49[^ |] | %99[^\n]", &id, name, action);
                    printf("ID: %i | User: %s | Action: %s\n", id, name, action);
                }

                fclose(list);
                break;
            }
            case 3:
            {
                char *user = get_string("Enter the user name to search: ");

                FILE *search = fopen("logs.txt", "r");
                if(search == NULL)
                {
                    printf("No registers found!\n");
                    break;
                }

                char txt[MAX_LINE];
                int found = 0;

                while(fgets(txt, sizeof(txt), search))
                {
                    int id;
                    char name[MAX_CHAR];
                    char action[MAX_ACTION];

                    sscanf(txt, "%i | %49[^ |] | %99[^\n]", &id, name, action);

                    if (strcasecmp(user, name) == 0)
                    {
                        printf("User found!\n");
                        printf("ID: %i | User: %s | Action: %s\n", id, name, action);

                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    printf("User with name %s not found!\n", user);
                }

                fclose(search);
                break;
            }
            case 4:
            {
                printf("Ending program...\n");
                break;
            }
            default:
            {
                printf("Invalid option! Select please correct option (1 a 4)\n");
                break;
            }
        }
    } while (op != 4);
}
