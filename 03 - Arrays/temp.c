#include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int dayweek = 7;
    string days[7] = {"Segunda-Feira", "Terça-Feira", "Quarta-Feira", "Quinta-Feira", "Sexta-Feira", "Sabado", "Domingo"};
    float temp[7];
    float media = 0;
    float mnt = 9999;   //Menor temperatura
    float mmt = -9999;  //Maior temperatura
    int c = 0;
    string daym = "";
    string daymn = "";

    for (int i = 0; i < dayweek; i++)
    {
        temp[i] = get_float("Informe a temperatura da %s:\n", days[i]);

        media += temp[i];

        if (temp[i] > mmt)
        {
            mmt = temp[i];
            daym = days[i];
        }

        if (temp[i] < mnt)
        {
            mnt = temp[i];
            daymn = days[i];
        }

    }

    media /= dayweek;

    printf("\n----Relatorio de Temperaturas da Semana----\n");
    printf("\n");
    printf("A maior temperatura registrada foi: %.1f - %s\n", mmt, daym);
    printf("A menor temperatura registrada foi: %.1f - %s\n", mnt, daymn);
    printf("A média semanal de temperaturas foi: %.1f\n", media);

    printf("\nOs dias acima da média foram: \n");
    for (int i = 0; i < dayweek; i++)
    {
        if (temp[i] > media)
        {
            printf("%s\n", days[i]);
        }
        else
        {
            c++;
        }
    }

    if (c == dayweek)
    {
        printf("Atencão!Todas as temperaturas estão abaixo da média!\n");
    }
    return 0;
}
