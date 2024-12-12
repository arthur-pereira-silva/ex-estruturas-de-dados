#include <stdio.h>
#include <locale.h>

int somaRecursiva(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + somaRecursiva(n - 1);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n;

    do
    {
        printf("Digite um valor positivo para N: ");
        scanf("%d", &n);

        if (n <= 0)
        {
            printf("Erro: O número deve ser maior que zero.\n");
        }
    } while (n <= 0);

    int soma = somaRecursiva(n);

    printf("A somatória de 1 a %d é: %d\n", n, soma);

    return 0;
}