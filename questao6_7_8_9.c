#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura de um evento
typedef struct evento
{
    int id;
    int dia;
    int hora, minuto;
    int localSaida, localChegada;
    int trajetoria;
    float duracaoEstimativa;
    int participantes;
    struct evento *prox;
} Evento;

// Função para criar um novo evento
Evento *criarEvento(int id, int dia, int hora, int minuto, int localSaida,
              int localChegada, int trajetoria, float duracaoEstimativa, int participantes)
{
    Evento *novoEvento = (Evento *)malloc(sizeof(Evento));
    novoEvento->id = id;
    novoEvento->dia = dia;
    novoEvento->hora = hora;
    novoEvento->minuto = minuto;
    novoEvento->localSaida = localSaida;
    novoEvento->localChegada = localChegada;
    novoEvento->trajetoria = trajetoria;
    novoEvento->duracaoEstimativa = duracaoEstimativa;
    novoEvento->participantes = participantes;
    novoEvento->prox = NULL;
    return novoEvento;
}

// Função para validar entradas inteiras
int lerInteiro(const char *mensagem)
{
    int num;
    while (1)
    {
        printf("%s", mensagem);
        if (scanf("%d", &num) == 1 && num > 0)
        {
            return num;
        }
        else
        {
            while (getchar() != '\n')
                ; // Limpar o buffer de entrada
            printf("Entrada inválida. Por favor, insira um número inteiro positivo.\n");
        }
    }
}

// Função para validar entradas de ponto flutuante
float lerFloat(const char *mensagem)
{
    float num;
    while (1)
    {
        printf("%s", mensagem);
        if (scanf("%f", &num) == 1 && num > 0)
        {
            return num;
        }
        else
        {
            while (getchar() != '\n')
                ; // Limpar o buffer de entrada
            printf("Entrada inválida. Por favor, insira um número válido.\n");
        }
    }
}

// Função para ler o dia (com validação e opções de seleção)
int lerDia()
{
    int dia;
    do
    {
        printf("\nSelecione o dia da semana para o evento:\n");
        printf("1 - Segunda-feira\n");
        printf("2 - Terça-feira\n");
        printf("3 - Quarta-feira\n");
        printf("4 - Quinta-feira\n");
        printf("5 - Sexta-feira\n");
        printf("6 - Sábado\n");
        printf("7 - Domingo\n");
        printf("8 - Diário\n");
        printf("Digite a opção correspondente: ");
        scanf("%d", &dia);

        if (dia >= 1 && dia <= 8)
        {
            return dia;
        }
        else
        {
            printf("Opção inválida! Por favor, escolha um número entre 1 e 8.\n");
        }
    } while (1);
}

// Função para ler o horário (hora e minuto)
void lerHorario(int *hora, int *minuto)
{
    while (1)
    {
        *hora = lerInteiro("Digite a hora (0-23): ");
        *minuto = lerInteiro("Digite os minutos (0-59): ");

        // Validação da hora e minutos
        if (*hora >= 0 && *hora <= 23 && *minuto >= 0 && *minuto <= 59)
        {
            break; // Entrada válida
        }
        else
        {
            printf("Horário inválido! A hora deve ser entre 0 e 23, e os minutos entre 0 e 59.\n");
        }
    }
}

// Função para cadastrar um novo evento na lista
void cadastrarEvento(Evento **lista, Evento *novoEvento)
{
    if (*lista == NULL)
    {
        *lista = novoEvento;
    }
    else
    {
        Evento *temp = *lista;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = novoEvento;
    }
    printf("Evento %d cadastrado com sucesso!\n", novoEvento->id);
}

// Função para consultar um evento pelo número
void consultaEvento(Evento *lista, int id)
{
    Evento *temp = lista;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("\nInformações do Evento %d:\n", temp->id);
            printf("Dia: ");
            switch (temp->dia)
            {
            case 1:
                printf("Segunda-feira\n");
                break;
            case 2:
                printf("Terça-feira\n");
                break;
            case 3:
                printf("Quarta-feira\n");
                break;
            case 4:
                printf("Quinta-feira\n");
                break;
            case 5:
                printf("Sexta-feira\n");
                break;
            case 6:
                printf("Sábado\n");
                break;
            case 7:
                printf("Domingo\n");
                break;
            case 8:
                printf("Diário\n");
                break;
            default:
                printf("Data inválida\n");
                break;
            }
            printf("Horário: %02d:%02d\n", temp->hora, temp->minuto);
            printf("Local de Saída: %d\n", temp->localSaida);
            printf("Local de Chegada: %d\n", temp->localChegada);
            printf("Trajetória: %d\n", temp->trajetoria);
            printf("Duração Estimada: %.2f horas\n", temp->duracaoEstimativa);
            printf("Participantes a bordo: %d\n", temp->participantes);
            return;
        }
        temp = temp->prox;
    }
    printf("Evento %d não encontrado.\n", id);
}

// Função para remover um evento pelo número
void removeEvento(Evento **lista, int id)
{
    Evento *temp = *lista;
    Evento *anterior = NULL;

    while (temp != NULL && temp->id != id)
    {
        anterior = temp;
        temp = temp->prox;
    }

    if (temp == NULL)
    {
        printf("Evento %d não encontrado.\n", id);
        return;
    }

    if (anterior == NULL)
    {
        *lista = temp->prox;
    }
    else
    {
        anterior->prox = temp->prox;
    }

    free(temp);
    printf("Evento %d removido com sucesso!\n", id);
}

// Função principal
int main()
{
    setlocale(LC_ALL, "Portuguese");

    Evento *listaEventos = NULL;
    int opcao, id, dia, hora, minuto, localSaida, localChegada, trajetoria, participantes;
    float duracaoEstimativa;

    do
    {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar Evento\n");
        printf("2. Consultar Evento\n");
        printf("3. Remover Evento\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) != 1)
        {
            printf("Entrada inválida!\n");
            while (getchar() != '\n')
                ; // Limpar o buffer de entrada
            continue;
        }

        switch (opcao)
        {
        case 1:
            id = lerInteiro("Digite o número do evento: ");
            dia = lerDia();
            lerHorario(&hora, &minuto);
            localSaida = lerInteiro("Digite o ID do local de saída: ");
            localChegada = lerInteiro("Digite o ID do local de chegada: ");
            trajetoria = lerInteiro("Digite o ID da trajetória: ");
            duracaoEstimativa = lerFloat("Digite a duração estimada do evento (em horas): ");
            participantes = lerInteiro("Digite o número de participantes: ");

            Evento *novoEvento = criarEvento(id, dia, hora, minuto, localSaida, localChegada, trajetoria, duracaoEstimativa, participantes);
            cadastrarEvento(&listaEventos, novoEvento);
            break;

        case 2:
            id = lerInteiro("Digite o número do evento a consultar: ");
            consultaEvento(listaEventos, id);
            break;

        case 3:
            id = lerInteiro("Digite o número do evento a remover: ");
            removeEvento(&listaEventos, id);
            break;

        case 4:
            printf("Encerrando o programa.\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    // Liberar memória antes de encerrar
    while (listaEventos != NULL)
    {
        Evento *temp = listaEventos;
        listaEventos = listaEventos->prox;
        free(temp);
    }

    return 0;
}