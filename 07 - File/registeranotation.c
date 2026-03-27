#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int op;

    do
    {
        op = get_int("1 - Add annotation\n"
                     "2 - List notes\n"
                     "3 - Leave\n"
                     "Choice: ");

        if (op < 1 || op > 3)
        {
            printf("Invalid option! Chose from 1 to 3\n");
            return 1;
        }

        switch (op)
        {
            case 1:
            {


                FILE *file = fopen("annotation.txt", "a");
                if (file == NULL)
                {
                    printf("Could not open file");
                    return 2;
                }

                char *anot = get_string("Type the note: ");
                fprintf(file, "%s\n", anot);

                fclose(file);
                printf("Note saved successfully!\n");
            break;
            }

            case 2:
            {
                FILE *read = fopen("annotation.txt", "r");
                if (read == NULL)
                    {
                        printf("No notes found\n");
                        return 2;
                    }

                    char text[256];

                    while (fgets(text, sizeof(text), read) != NULL)
                    {
                        printf("%s", text);
                    }

                    fclose(read);
            break;
            }

            case 3:
            {
                printf("Ending program...\n");
            break;
            }
        }
    } while (op != 3);
}
