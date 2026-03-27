//Bibliotecas utilizadas
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Definição de maximo de produtos
#define Max_Prod 50

//Estrutura de dados do produto
typedef struct
{
    string nome;
    float preco;
    int qtd;
} produto;

//Protótipo das funções
void cadastrar(produto prod[], int *n);
void lista(produto prod[], int n);
void buscar(produto prod[], int *n);
void valor(produto prod[], int n);

//Função principal
int main(void)
{
    //Declaracão de variaveis
    produto prod[Max_Prod];     //Varial da estrutura de dados
    int op;
    int n = 0;

    do
    {
        //Menu em loop para escolha do usuario
        printf("\n===================MENU===================\n");
        op = get_int("1 - Cadastrar produto\n"
                     "2 - Listar produtos\n"
                     "3 - Buscar produto por nome\n"
                     "4 - Valor total do estoque\n"
                     "5 - Sair\n"
                     "Selecione a opção:");
        printf("==========================================\n");

        //Escolha Caso para acionar a função
        switch (op)
        {
            //Cadastra os produtos
            case 1:
                cadastrar(prod, &n);    //&n = Passa o valor de N por indice
                break;

            //Lista os produtos
            case 2:
                lista(prod, n);
                break;

            //Busca o produto
            case 3:
                buscar(prod, &n);
                break;

            //Mostra o valor total dos produtos em estoque
            case 4:
                valor(prod, n);
                break;
        }
    }
    while (op != 5);

    printf("PROGRAMA ENCERRANDO...\n");
    printf("=======================================\n");
}

void cadastrar(produto prod[], int *n)      //Função de cadastrar produtos
{
    printf("\n===========CADASTRO=DE=PRODUTOS===========\n");

    //Verificão de tamanho de estoque
    if (*n >= Max_Prod)
    {
        printf("Estoque cheio!\n");
        return;
    }

    prod[*n].nome = get_string("Nome do produto:");
    prod[*n].preco = get_float("Valor do produto:R$");
    prod[*n].qtd = get_int("Quantidade do produto:");
    (*n)++;

    printf("Produtos cadastrados com sucesso :)!\n");
    printf("==========================================\n");
}

void lista(produto prod[], int n)       //Funcão de lista de produtos
{
    printf("\n=============LISTA=DE=PRODUTOS============\n");

    //Verificação se ja tem produto cadastrado
    if (n == 0)
    {
        printf("Nenhum produto cadastrado!\n");
        return;
    }
    printf("| PRODUTOS | PREÇOS | QUANTIDADE | \n");
    printf(" ________________________________\n");

    //Laço FOR para imprimir a lista
    for (int i = 0; i < n; i++)
    {
        printf("|  %-9s R$%-10.2f %i      |\n", prod[i].nome, prod[i].preco, prod[i].qtd);
    }
    printf("==========================================\n");
}

void buscar(produto prod[], int *n)     //Função de busca
{
    string busca;

    printf("\n==================BUSCA===================\n");
    busca = get_string("Digite o nome do produto:");

    for (int i = 0; i < *n; i++)
    {
        //Verificação de comparação de duas STRINGS
        if (strcmp(busca, prod[i].nome) == 0)
        {
            printf("Produto encontrado!\n| %s | Preço:R$%.2f | Quantidade:%i |\n", prod[i].nome,
                   prod[i].preco, prod[i].qtd);
            printf("==========================================\n");
            return;
        }
    }

    printf("Produto não encontrado!\n");
    printf("=========================================\n");
}

void valor(produto prod[], int n)       //Função de valor total de estoque
{
    float totprod = 0;

    printf("\n==================VALOR===================\n");

    //Laço FOR para calcular o total
    for (int i = 0; i < n; i++)
    {
        totprod += prod[i].preco * prod[i].qtd; //+= recebe a soma atualizada
    }
    printf("Valor total do estoque é de:R$%.2f\n", totprod);
    printf("==========================================\n");
}
