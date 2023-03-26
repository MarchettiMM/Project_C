#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// estrutura de armazenamento de dados
struct dados_rebanho
    {
        int mes;
        float Ta, UR, ITU;// variaveis para calculo
        char M; // tem que ser do tipo char, pois retornará uma mensagem
    }Tabrebanho[12];

// recebe Ta e UR retorna calculado-Função
float itu (float Ta, float UR)
{
    float calculo;
    calculo = 0.8*Ta + UR*((Ta - 14.3)/100) + 46.3;
    return (calculo);// retorna para main
}//Fim da função

int status(float ITU){ // função que retorna a mensagem das condições animais
    if (ITU >= 75)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int busca(int mes){
    int posicao = -1, i;

    for (i=0;i<12;i++){
        if(Tabrebanho[i].mes == mes){
            posicao=i;
        }
    }
    return posicao;
}
//Função principal
int main()
{
    setlocale(LC_ALL,"Portuguese");
    int i=0;// contador
    int a,b;
//Fim da struct

    while (i <12) // inicio do programa
    {
        printf(" *** Entrada de dados *** \n ");

        printf("Qual o m�s?: ");
        scanf("%d", &a);
        Tabrebanho[i].mes=a;

        printf("Informe Temperatura (Ta): " );
        scanf("%f", &Tabrebanho[i].Ta);

        printf("Informe Umidade (UR):  ");
        scanf("%f", &Tabrebanho[i].UR);

        Tabrebanho[i].ITU = itu (Tabrebanho[i].Ta, Tabrebanho[i].UR);//invocando a fun��o

        Tabrebanho[i].M = status(Tabrebanho[i].ITU);

        i++;
        system("cls");
    }
    printf(" *** Consulta M�s *** \n");

    printf("Digite o m�s a ser consultado (valor entre 1 e 12): ");

    int posicao;
    do
    {
        scanf("%d", &b);
        if(b>0)
        {
            posicao = busca(b);
            if (posicao==-1){
                printf("M�s n�o encontrado!\n");
            }else{
                printf("Ta: %.2f   UR: %.2f   ITU: %.2f   M: %s\n", Tabrebanho[posicao].Ta, Tabrebanho[posicao].UR, Tabrebanho[posicao].ITU, Tabrebanho[posicao].M == 0 ? "CONDI��ES NORMAIS" : "ESTRESSE CLIM�TICO");
            }
        }
        printf("Digite outro m�s ou 0 para sair: ");
    }while(b!=0); // façaa enquanto o mes digitado for diferente de zero
  return 0;
}//Fim da função principal
