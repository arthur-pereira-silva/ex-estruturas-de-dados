#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define TAMANHO 3

void limpar()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void aguardar()
{
#ifdef _WIN32
    system("pause");
#else
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
#endif
}

void executarJogo()
{
    char tabuleiro[TAMANHO][TAMANHO] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int linha, coluna;
    int i, j;

    bool finalizado = false;
    char jogadorAtual = 'X';

    do
    {
        limpar();

        printf("\nTabuleiro Atual:\n");
        printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);

        printf("\nEscolha uma linha (0-%d) para %c: ", TAMANHO - 1, jogadorAtual);
        scanf("%d", &linha);
        printf("Escolha uma coluna (0-%d) para %c: ", TAMANHO - 1, jogadorAtual);
        scanf("%d", &coluna);

        if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO)
        {
            printf("\nPosição inválida! Tente novamente.\n");
            aguardar();
            continue;
        }

        if (tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O')
        {
            printf("\nPosição já ocupada! Tente novamente.\n");
            aguardar();
            continue;
        }

        tabuleiro[linha][coluna] = jogadorAtual;

        for (i = 0; i < TAMANHO; i++)
        {
            if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            {
                limpar();
                printf("\nTabuleiro Final:\n");
                printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
                printf("---|---|---\n");
                printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
                printf("---|---|---\n");
                printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
                printf("\n%c venceu!\n", jogadorAtual);
                finalizado = true;
                break;
            }
        }

        for (i = 0; i < TAMANHO; i++)
        {
            if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            {
                limpar();
                printf("\nTabuleiro Final:\n");
                printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
                printf("---|---|---\n");
                printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
                printf("---|---|---\n");
                printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
                printf("\n%c venceu!\n", jogadorAtual);
                finalizado = true;
                break;
            }
        }

        if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        {
            limpar();
            printf("\nTabuleiro Final:\n");
            printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
            printf("\n%c venceu!\n", jogadorAtual);
            finalizado = true;
        }

        if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        {
            limpar();
            printf("\nTabuleiro Final:\n");
            printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
            printf("\n%c venceu!\n", jogadorAtual);
            finalizado = true;
        }

        int cheio = 1;
        for (i = 0; i < TAMANHO; i++)
        {
            for (j = 0; j < TAMANHO; j++)
            {
                if (tabuleiro[i][j] == ' ')
                {
                    cheio = 0;
                    break;
                }
            }
        }
        if (cheio && !finalizado)
        {
            limpar();
            printf("\nTabuleiro Final:\n");
            printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
            printf("\nEmpate!\n");
            finalizado = true;
        }

        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';

    } while (!finalizado);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    executarJogo();

    return 0;
}
