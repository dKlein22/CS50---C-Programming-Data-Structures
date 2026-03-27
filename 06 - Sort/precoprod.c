#include <cs50.h>           //Bibliotecas utilizadas
#include <stdio.h>

//Número máximo de preços
#define Max 10

//Protótipo da função Selection
void selectionsort(float v[], int n, int *c);

int main(void)
{
    int n = 0;

    n = get_int("Quantos preços deseja cadastrar?");

    //Verificação de número máximo
    if (n > Max)
    {
        printf("Número maximo de cadastros é 10!\n");
        return 1;
    }

    float v[n];

    for (int i = 0; i < n; i++)
    {
        v[i] = get_float("Digite o preço do produto [%i]: R$", i + 1);      //Armazena os preços na array
    }

    printf("Preços antes da ordenação:\n");

    for (int i = 0; i < n; i++)
    {
        printf("R$%.2f ", v[i]);            //Imprime antes da ordenação
    }
    printf("\n");

    int c = 0;
    selectionsort(v, n, &c);            //Função selection, passando C por referência

    printf("\nPreços após a ordenação:\n");

    for(int i = 0; i < n; i++)
    {
        printf("R$%.2f ", v[i]);            //Imprime após a ordenação
    }
    printf("\n");

    printf("\nHouve %i trocas\n", c);       //Contador de trocas

    float menor = v[0];
    float maior = v[n - 1];         //Armazena os valores maiores e menores
    float soma = 0;
    float media;

    for (int i = 0; i < n; i++)
    {
        //Soma o total
        soma += v[i];
    }

    //Armazena a média
    media = soma / n;

    //Imprime os valores
    printf("Maior preço é: R$%.2f\n", maior);
    printf("Menor preço é: R$%.2f\n", menor);
    printf("A soma dos preços é: R$%.2f\n", soma);
    printf("A média dos preços é: R$%.2f\n", media);

}

void selectionsort(float v[], int n, int *c)    //Função Selection
{
    //Variaveis para realizar a troca de posição
    int menor;
    int aux;

    for(int i = 0; i < n - 1; i++)
    {
        menor = i;

        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[menor])
            {
                menor = j;
            }
        }

        //Condiçãp para evitar troca sem necessidade
        if (menor != i)
        {
            aux = v[i];
            v[i] = v[menor];            //Realiza a troca de posições
            v[menor] = aux;

            (*c)++;

            printf("\nApós a troca %i\n", *c);

            for (int k = 0; k < n; k++)
            {
                printf("%.2f ", v[k]);      //Imprime a quantidade de trocas
            }
            printf("\n");
        }
    }
}
