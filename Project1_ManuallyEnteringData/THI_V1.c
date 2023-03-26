#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura de armazenamento de dados
struct dados_rebanho
{
    int mes;
    float Ta, UR, ITU;
    char M;
} Tabrebanho[12];

// Função para cálculo de ITU
float CalculaITU(float Ta, float UR)
{
    float calculo;
    calculo = 0.8 * Ta + UR * ((Ta - 14.3) / 100) + 46.3;
    return (calculo);
}

// Função das condições de ITU
int status(float ITU)
{
    if (ITU >= 75)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Função do buscador
int busca(int mes)
{
    int posicao = -1, i;

    for (i = 0; i < 12; i++)
    {
        if (Tabrebanho[i].mes == mes)
        {
            posicao = i;
        }
    }
    return posicao;
}

int main()
{
    int i = 0, a, b, posicao;

    while (i < 12)
    {
        printf(" *** Entrada de dados *** \n ");

        printf("Qual o %dº mês? (Valores entre 1 e 12): ", i + 1);
        scanf("%d", &a);
        Tabrebanho[i].mes = a;

        printf("Informe a Temperatura para o mês %d: ", Tabrebanho[i].mes);
        scanf("%f", &Tabrebanho[i].Ta);

        printf("Informe a Umidade para o mês %d: ", Tabrebanho[i].mes);
        scanf("%f", &Tabrebanho[i].UR);

        Tabrebanho[i].ITU = CalculaITU(Tabrebanho[i].Ta, Tabrebanho[i].UR);
        Tabrebanho[i].M = status(Tabrebanho[i].ITU);
        i++;
        system("cls");
    }
    printf(" *** Consulta Mês *** \n");
    printf("Digite o mês a ser consultado (valor entre 1 e 12): ");
    scanf("%d", &b);
    do
    {
        if (b > 0)
        {
            posicao = busca(b);
            if (posicao == -1)
            {
                printf("\nMês não encontrado!\n\n");
            }
            else
            {
                printf("\nInformações para o mês %d:\nTemperatura\tUmidade Relativa\tITU\n", b);
                printf("%.2f\t\t%.2f\t\t\t%.2f\t\t%s\n\n", Tabrebanho[posicao].Ta, Tabrebanho[posicao].UR, Tabrebanho[posicao].ITU, Tabrebanho[posicao].M == 0 ? "Condições Normais" : "Estresse Climático");
            }
        }
        printf("Digite outro mês ou 0 para sair: ");
        scanf("%d", &b);
    } while (b != 0);
    return 0;
}