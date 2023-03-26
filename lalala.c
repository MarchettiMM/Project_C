#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Função que calcula o ITU
float CalculaITU(float temperatura, float umidadeRelativa)
{
    return 0.8 * temperatura + umidadeRelativa * ((temperatura - 14.3) / 100) + 46.3;
}

int CondicaoITU(float ITU)
{
    if (ITU < 75)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int Day, i = 0;

    struct Dia
    {
        int Dias, M;
        float Temperatura, UmidadeRelativa, ITU;
    } Dia[365];

    printf("Seja bem vindo ao programa de verificação de estresse climático!\n\n");

    FILE *TempUmid;
    TempUmid = fopen("TempUmid.txt", "r");
    fscanf(TempUmid, "%*s %*s %*s");

    while (fscanf(TempUmid, "%d\t%f\t%f\n", &Dia[i].Dias, &Dia[i].Temperatura, &Dia[i].UmidadeRelativa) != EOF)
    {
        Dia[i].ITU = CalculaITU(Dia[i].Temperatura, Dia[i].UmidadeRelativa);
        Dia[i].M = CondicaoITU(Dia[i].ITU);
        i++;
    }
    fclose(TempUmid);
    do
    {
        do
        {
            printf("Digite o dia que deseja buscar (Entre 1 e 365)\nCaso queira finalizar o programa, digite 0:\n");
            scanf("%d", &Day);
        } while ((Day < 0) || (Day > 365));
        if (Day != 0)
        {
            printf("\nInformações para o dia %d:\nTemperatura\tUmidade Relativa\tITU\n", Day);
            printf(" %.2f\t\t %.2f\t\t\t %.2f\t ", Dia[Day - 1].Temperatura, Dia[Day - 1].UmidadeRelativa, Dia[Day - 1].ITU);
            if (Dia[Day - 1].M == 0)
            {
                printf("Condições Normais\n\n");
            }
            else
            {
                printf("Estresse Climático\n\n");
            }
        }
    } while (Day != 0);
    return 0;
}