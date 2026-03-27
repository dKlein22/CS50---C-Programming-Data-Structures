#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float notas[10];
    float soma = 0;

    int a = get_int("Quantos alunos tem na turma? ");

    for (int i = 0; i < a; i++)
    {
        notas[i] = get_float("Qual foi a nota do %i aluno:\n", i + 1);

        soma += notas[i];
    }

    float media = 0;
    media = (media + soma)/a;

    printf("Média da turma: %.2f\n", media);
    printf("Alunos:\n ");

    for (int i = 0; i < a; i++)
    {
        if (notas[i] > media)
        {
            printf("Aluno %i aprovado! Nota: %.2f\n", i + 1, notas[i]);
        }

        else
        {
            printf("Aluno %i reprovado! Nota: %.2f\n", i + 1, notas[i]);
        }
    }
}

