//Bibliotecas usadas
#include <cs50.h>
#include <stdio.h>

//Maximo de salarios
#define Max 10

void insertionsort(float v[], int n, int *c, int *m); //Prototipo Insertion

int main(void)
{
    int n;

    n = get_int("Informe o número de salarios: ");

    //Verificacao de numero maximo
    if (n > Max)
    {
        printf("Máximo de salarios é 10!\n");
        return 1;
    }

    float v[n];

    for (int i = 0; i < n; i++)
    {
        v[i] = get_float("Salário [%i]: R$", i + 1);
    }

    printf("Salarios antes da ordenação:\n");
    for(int i = 0; i < n; i++)
    {
        printf("R$%.2f ", v[i]);            //Imprime antes da ordenação
    }
    printf("\n\n");

    int m = 0;
    int c = 0;

    insertionsort(v, n, &c, &m);

    printf("\nSalarios após a ordenação:\n");
    for(int i = 0; i < n; i++)
    {
        printf("R$%.2f ", v[i]);            //Imprime após a ordenação
    }
    printf("\n\n");



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
    printf("\nMaior preço é: R$%.2f\n", maior);
    printf("Menor preço é: R$%.2f\n", menor);
    printf("A soma dos preços é: R$%.2f\n", soma);
    printf("A média dos preços é: R$%.2f\n", media);
    printf("\nHouve %i movimentações\n", c);            //Contador de movimentações
    printf("\nHouve %i comparações\n", m);             //Contador de comparações

}

void insertionsort(float v[], int n, int *c, int *m)    //Funcao Insertion
{
    //Variaveis de inserção
    float chave;
    int j;
    int passo = 0;

    for (int i = 1; i < n; i++)
    {
        chave = v[i];
        j = i - 1;

        // Enquanto houver elementos à esquerda, contamos a comparação
        while (j >= 0)
        {
            (*c)++; //Comparação
            if (v[j] > chave)
            {
                // desloca o elemento para a direita
                v[j + 1] = v[j];
                (*m)++;
                passo++;

                // Mostra o vetor após cada movimentação
                printf("\nApós a movimentação %i:\n", passo);
                for (int k = 0; k < n; k++)
                {
                    printf("R$%.2f ", v[k]);
                }
                printf("\n");

                j--;
            }
            else
            {
                break; // se não é maior, para de deslocar
            }
        }

        // Insere a chave na posição correta
        v[j + 1] = chave;
        (*m)++;
        passo++;

        // Mostra o vetor após a inserção
        printf("\nApós a movimentação %i (inserção):\n", passo);
        for (int k = 0; k < n; k++)
        {
            printf("R$%.2f ", v[k]);
        }
        printf("\n");
    }
}
