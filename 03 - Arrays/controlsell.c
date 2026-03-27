//Bibliotecas para as funções
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//Protótipo da função
void print_relatorio(int prod, string nameprod[], int quant[], float preco[], float soma, float tot, float mais, string prodmais);

//Definição de um numero
#define MAX 10

//Função principal
int main(void)
{
    //Tipos primitivos
    int c = 0;
    string nameprod[MAX];
    int quant[MAX];
    float preco[MAX];
    float tot = 0;
    float mais = -9999;
    float soma = 0;
    string prodmais = "";

    printf("----------------------MENU----------------------\n");

    //Validação de número correto
    do
    {
        c = get_int("\nQuantos produtos deseja cadastrar? ");
        if (c > 10 || c < 1)
        {
            printf("Número inválido! (Máximo de produtos é 10)\n");
        }

    } while (c > 10);

    printf("\n----------------Cadastro Produtos----------------\n");
    for (int i = 0; i < c; i++)
    {
        printf("=================================================");
        nameprod[i] = get_string("\nInforme o nome do produto: ");
        quant[i] = get_int("Informe a quantidade vendida: ");
        preco[i] = get_float("Informe o valor unitario: R$");

        tot = quant[i]*preco[i];

        soma += tot;

        //Condição para descobrir o maior valor gasto
        if (preco[i] > mais)
        {
            mais = preco[i];
            prodmais = nameprod[i];
        }
    }

    print_relatorio(c, nameprod, quant, preco, soma, tot, mais, prodmais);

}

//Funcao que imprime o relatorio
void print_relatorio(int prod, string nameprod[], int quant[], float preco[], float soma, float tot, float mais, string prodmais)
{
   printf("\n\n-------------------------Relatório de Vendas-----------------------\n\n");

    printf("%-20s %-15s %-15s %-15s\n", "Produto", "Quantidade", "Preço Unit.", "Total Item");
    printf("-------------------------------------------------------------------\n");

    // Loop principal
    for (int i = 0; i < prod; i++)
    {
        //Pega o tamanho da string ATUAL
        int n = strlen(nameprod[i]);

        //Loop interno
        for (int j = 0; j < n; j++)
        {
            //Converte a letra individual
            //nameprod[i] é a string
            //nameprod[i][j] é o char
            nameprod[i][j] = toupper(nameprod[i][j]);
        }

        tot = preco[i]*quant[i];

        //Imprime a linha do relatório
        printf("%-20s %-15i R$%-14.2f R$%-13.2f\n",
        nameprod[i],
        quant[i],
        preco[i],
        tot);
    }
    printf("-------------------------------------------------------------------\n");

    //Imprimei o total geral
    printf("\nTOTAL GERAL: R$%.2f\n", soma);
    printf("\nProduto mais caro foi: %s no valor de R$%.2f\n", prodmais, mais);
}
