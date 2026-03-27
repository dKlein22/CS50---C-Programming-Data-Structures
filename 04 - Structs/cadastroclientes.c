//Bibliotecas utilizadas
#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define Max 50  //Maximo de clientes

typedef struct
{
    char *nome;
    char *cpf;          //Estrutura de dados do cliente
    char *email;
    int idade;
} person;

//Prototipos das funções
void cadastrar(person pessoa[], int *n);
void listar(person pessoa[], int n);
void buscar(person pessoa[], int n);

int main(void)
{
    person pessoa[Max];
    int op;
    int n;

    do
    {
        printf("\n=================MENU================\n");
        printf("=======================================\n");
        printf("1 - Cadastro de Cliente\n"
                "2 - Listar Clientes\n"
                "3 - Buscar cliente por CPF\n"                  //Menu
                "4 - Sair\n");
        op = get_int("Escolha a opção:");
        printf("=======================================\n");

        if (op < 1 || op > 4)
        {
            printf("\nOpção inválida!\n");
        }

        switch (op)
        {
            case 1:
                cadastrar(pessoa, &n);
                break;

            case 2:
                listar(pessoa, n);          //Escolhas
                break;

            case 3:
                buscar(pessoa, n);
                break;
        }

    } while (op != 4); //Verificação

    printf("PROGRAMA ENCERRANDO...\n");
    printf("=======================================\n");
}









//Função cadastro
void cadastrar(person pessoa[], int *n)
{
    printf("\n==========CADASTRO=DE=CLIENTES==========\n");

    //Verificacao de quantidade
    if (*n >= Max)
    {
        printf("Máximo de cadastro de clientes!");
        return;
    }

    pessoa[*n].nome = get_string("Nome do cliente:");
    pessoa[*n].cpf = get_string("CPF:");
    pessoa[*n].idade = get_int("Idade:");               //Cadastro
    pessoa[*n].email = get_string("Email:");
    (*n)++;

    printf("Cliente cadastrado com sucesso!\n");
    printf("=========================================\n");
}

//Função listar
void listar(person pessoa[], int n)
{
    printf("\n=============LISTA=DE=CLIENTES===========\n");

    //Verificacao se tem clientes
    if (n <= 0)
    {
        printf("Nenhum cliente cadastrado!\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        //Lista de pessoas
        printf("___________________________\n");
        printf("|NOME:%-15s     |\n"
                "|CPF:%-15s      |\n"
                "|IDADE:%-15i    |\n"
                "|EMAIL:%-14s    |\n",
                pessoa[i].nome, pessoa[i].cpf, pessoa[i].idade, pessoa[i].email);
        printf("___________________________\n");
    }
    printf("=========================================\n");
}

//Função buscar
void buscar(person pessoa[], int n)
{
    char *busca;
    printf("\n==========BUSCA==========\n");
    busca = get_string("Informe o CPF do cliente:");

    for (int i = 0; i < n; i++)
    {
        if (strcmp(busca, pessoa[i].cpf) == 0) //Comparação de strings
        {
            printf("\nCliente encontrado!\n");
            printf("___________________________\n");
            printf("|NOME:%-15s     |\n"
                "|CPF:%-15s      |\n"
                "|IDADE:%-15i    |\n"                   //Imprime a pesquisaf
                "|EMAIL:%-14s    |\n",
                pessoa[i].nome, pessoa[i].cpf, pessoa[i].idade, pessoa[i].email);
            printf("___________________________\n");
            return;
        }
    }

    printf("Cliente não encontrado!\n");
    printf("=========================================\n");
}
