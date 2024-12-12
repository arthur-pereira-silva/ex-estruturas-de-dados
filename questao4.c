#include <stdio.h>
#include <locale.h>

void analisarClima()
{
    const int TOTAL_CIDADES = 7;
    const int TOTAL_MESES = 6;
    const char NOMES_MESES[][6] = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun"};

    float dadosPluviometricos[TOTAL_CIDADES][TOTAL_MESES];
    float somaPorMes[TOTAL_MESES] = {0};

    int cidade, mes;
    float soma, mediaCidade;

    for (cidade = 0; cidade < TOTAL_CIDADES; cidade++)
    {
        soma = 0;

        for (mes = 0; mes < TOTAL_MESES; mes++)
        {
            printf("Insira o índice pluviométrico da %dª cidade no mês de %s: ", cidade + 1, NOMES_MESES[mes]);
            scanf("%f", &dadosPluviometricos[cidade][mes]);

            soma += dadosPluviometricos[cidade][mes];
            somaPorMes[mes] += dadosPluviometricos[cidade][mes];
        }

        mediaCidade = soma / TOTAL_MESES;
        printf("Índice de pluviosidade médio da cidade %d: %.2f\n", cidade + 1, mediaCidade);
    }

    printf("\nÍndice de pluviosidade médio por mês:\n");
    for (mes = 0; mes < TOTAL_MESES; mes++)
    {
        printf("Mês de %s: %.2f\n", NOMES_MESES[mes], somaPorMes[mes] / TOTAL_CIDADES);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    analisarClima();
    return 0;
}
