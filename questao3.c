#include <stdio.h>
#include <locale.h>

void notasTurma()
{
    const int ALUNOS = 5, PROVAS = 4;
    int notas[ALUNOS][PROVAS];
    float medias[ALUNOS], mediaTurma = 0.0, soma;
    int i, j;

    for (i = 0; i < ALUNOS; i++)
    {
        soma = 0;

        for (j = 0; j < PROVAS; j++)
        {
            do
            {
                printf("Insira a %dª nota do %dº aluno (0 a 10): ", j + 1, i + 1);
                scanf("%d", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10)
                {
                    printf("Nota inválida! Tente novamente.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);

            soma += notas[i][j];
        }

        medias[i] = soma / PROVAS;
    }

    soma = 0;
    for (i = 0; i < ALUNOS; i++)
    {
        soma += medias[i];
    }
    mediaTurma = soma / ALUNOS;

    printf("\n--- Resultados ---\n");
    for (i = 0; i < ALUNOS; i++)
    {
        printf("A média do %dº aluno é: %.2f\n", i + 1, medias[i]);
    }
    printf("\nA média da turma é: %.2f\n", mediaTurma);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    notasTurma();

    return 0;
}
