#include <stdio.h>
#include <locale.h>

#define LINHAS 3
#define COLUNAS 3

void encontrarMaiorMenor()
{
    float matriz[LINHAS][COLUNAS];
    int linha, coluna;

    for (linha = 0; linha < LINHAS; linha++)
    {
        for (coluna = 0; coluna < COLUNAS; coluna++)
        {
            printf("Informe o %d° valor da %d° linha: ", coluna + 1, linha + 1);
            scanf("%f", &matriz[linha][coluna]);
        }
    }

    float maiorValor = matriz[0][0], menorValor = matriz[0][0];

    for (linha = 0; linha < LINHAS; linha++)
    {
        for (coluna = 0; coluna < COLUNAS; coluna++)
        {
            if (matriz[linha][coluna] > maiorValor)
            {
                maiorValor = matriz[linha][coluna];
            }
            if (matriz[linha][coluna] < menorValor)
            {
                menorValor = matriz[linha][coluna];
            }
        }
    }

    printf("\nMaior valor da matriz: %.2f\n", maiorValor);
    printf("Menor valor da matriz: %.2f\n", menorValor);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    encontrarMaiorMenor();
    return 0;
}
