//Bibliotecas utilizadas
#include <cs50.h>
#include <stdio.h>

//Numero maximo de notas
#define Max 10

//Prototipo funcao Bubble
void bubblesort(float v[], int n, int *c, int *cc);

int main(void)
{
    int n;

    n = get_int("Quantas notas deseja verificar? [Max é 10] ");

    //Verificacao de tamnho
    if (n > Max)
    {
        printf("Máximo de notas é 10!");
        return 1;
    }

    float v[n];

    for(int i = 0; i < n; i++)
    {
        v[i] = get_float("Nota %i\n", i + 1);
    }

    printf("Antes da ordenação:\n");
    for (int i = 0; i< n; i++)
    {
        printf("%.2f ", v[i]);      //Imprime antes da ordenação
    }
    printf("\n");

    int c = 0;
    int cc = 0;

    bubblesort(v, n, &c, &cc);      //Funcao Bubble

    printf("\nApós a ordenação:\n");
    for (int i = 0; i< n; i++)
    {
        printf("%.2f ", v[i]);      //Imprime apos a ordenação
    }
    printf("\n");

    //Armazerna os valores de maior e menor
    float maior = v[n - 1];
    float menor = v[0];
    float soma = 0;
    float media;

    for (int i = 0; i < n; i++)
    {
        soma += v[i];       //Armazena valor da soma total das notas
    }

    media = soma / n;

    printf("\nA maior nota foi: %.2f\n", maior);
    printf("A menor nota foi: %.2f\n", menor);
    printf("A média das notas foi: %.2f\n", media);     //Imprime todas as informações
    printf("Houve %i trocas\n", c);
    printf("Houve %i comparações\n", cc);

}

void bubblesort(float v[], int n, int *c, int *cc)  //Função
{
    float aux;    //Auxiliar da troca
    int passo = 0;  //Conta o passo a passo

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            //Conta as comparações
            (*cc)++;
            if (v[j] > v[j + 1])

            {
                aux = v[j];
                v[j] = v[j + 1];        //Realiza a troca
                v[j + 1] = aux;

                //Conta as trocas de posições
                (*c)++;
                passo++;

                printf("\nApós a troca %d:\n", passo);
                for (int k = 0; k < n; k++)
                {
                    printf("%.2f ", v[k]);          //Imprime o passo a passo
                }
                printf("\n");
            }
        }
    }
}
