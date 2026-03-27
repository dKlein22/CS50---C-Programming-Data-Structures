#include <cs50.h>
#include <stdio.h>

// Definição do número máximo de funcionários
#define MAX 10

// Protótipo da função
void print_question(int c, string name[], int m, string mes[], int nota[], float media[]);
void print_relatorio(int c, string name[], float media[], float maior, float menor, string nomemaior, string nomemenor);

// Funcao principal
int main(void)
{
    // tipos primitivos
    int c = 0;
    string name[MAX];
    string mes[3] = {"Janeiro", "Fevereiro", "Março"};
    int m = 3;
    int nota[m];
    float soma = 0;
    float media[MAX];
    float maior = 0;
    float menor = 9999;
    string nomemaior = "";
    string nomemenor = "";

    // Verificação para caso não seja o número valido
    printf("\n--------------------Análise Funcionários--------------------\n");
    do
    {
        c = get_int("\nQual o números de funcionários deseja avaliar? ");
        if (c > 10)
        {
            printf("Número Inválido! (Máximo de funcionários é 10)\n");
        }
    } while (c > 10 || c < 1);

    // Esta função  pega os dados E calcula a média de cada um
    print_question(c, name, m, mes, nota, media);

    //Acha o maior e menor
    for (int i = 0; i < c; i++)
    {
        if (media[i] > maior)
        {
            maior = media[i];
            nomemaior = name[i];
        }
        if (media[i] < menor)
        {
            menor = media[i];
            nomemenor = name[i];
        }
    }

    // Esta função imprime o relatório final
    print_relatorio(c, name, media, maior, menor, nomemaior, nomemenor);
}


void print_question(int c, string name[], int m, string mes[], int nota[], float media[])
{
    // Repetição de impressao dos nomes de funcionarios
    for (int i = 0; i < c; i++) // Loop para CADA funcionario
    {
        printf("_______________________________________________________\n");
        name[i] = get_string("Informe o nome do %io funcionário: ", i + 1);
        printf("_______________________________________________________\n");

        float soma_funcionario = 0;

        // Repetição dos meses
        for (int j = 0; j < m; j++)
        {
            // Verificação se a nota não vai ser maior que 10
            do
            {
                nota[j] = get_int("Informe a nota de produtividade do mês de %s: ", mes[j]);

                if (nota[j] > 10 || nota[j] < 1)
                {
                    printf("Nota Inválida! (Nota máxima é 10)\n");
                }

            } while (nota[j] > 10 || nota[j] < 1);

            soma_funcionario = soma_funcionario + nota[j]; // Soma a nota do mes
        }

        media[i] = soma_funcionario / (float)m;
    }
}


// Função de impressão do relatório
void print_relatorio(int c, string name[], float media[], float maior, float menor, string nomemaior, string nomemenor)
{
    printf("\n\n-----------------Relatório de Desempenho-----------------\n\n");
    printf("_______________________________________\n");
    printf("%-20s | %-15s\n", "Nome:", "Média"); // Cabeçalho da tabela
    printf("_______________________________________\n");

    for (int i = 0; i < c; i++)
    {
        // Imprime o nome e a media[i]
        printf("%-20s | %-15.2f\n", name[i], media[i]);
    }

    printf("__________________________________________\n");
    printf("===========================================\n");
    printf("Melhor funcionário/a: %s (%.2f)\n", nomemaior, maior);
    printf("Pior funcionário/a: %s (%.2f)\n", nomemenor, menor);
    printf("===========================================\n");
}
