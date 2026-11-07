#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int itens[MAX];
    int inicio;
    int fim;
} Fila;

void iniciarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

void enfileirar(Fila *f, int valor) {
    if (f->fim == MAX) {
        printf("\n[ERRO] A fila esta cheia!\n");
    } else {
        f->itens[f->fim] = valor;
        f->fim++;
        printf("\n[SUCESSO] %d entrou no final da fila!\n", valor);
    }
}

void desenfileirar(Fila *f) {
    if (f->inicio == f->fim) {
        printf("\n[ERRO] A fila esta vazia! Ninguem para atender.\n");
    } else {
        printf("\n[SUCESSO] %d foi atendido e saiu da fila!\n", f->itens[f->inicio]);
        
        // Desloca todos os elementos restantes uma posicao para a esquerda
        for (int i = f->inicio + 1; i < f->fim; i++) {
            f->itens[i - 1] = f->itens[i];
        }
        
        // Ajusta o fim da fila, mantendo o inicio fixo em 0
        f->fim--;
    }
}

void mostrarFila(Fila *f) {
    if (f->inicio == f->fim) {
        printf("\nA fila esta vazia.\n");
    } else {
        printf("\n--- ESTADO ATUAL DA FILA (Com Reutilizacao) ---\n");
        printf("Inicio -> ");
        for (int i = f->inicio; i < f->fim; i++) {
            printf("[%d] ", f->itens[i]);
        }
        printf("<- Fim (Total de elementos: %d)\n", f->fim - f->inicio);
    }
}

int main() {
    Fila minhaFila;
    iniciarFila(&minhaFila);
    int opcao, valor;

    // --- TESTE OBRIGATÓRIO ---
    printf("========================================\n");
    printf("       EXECUTANDO TESTE OBRIGATORIO     \n");
    printf("========================================\n");
    
    printf("1. Inserindo 5 valores (10, 20, 30, 40, 50)...\n");
    enfileirar(&minhaFila, 10);
    enfileirar(&minhaFila, 20);
    enfileirar(&minhaFila, 30);
    enfileirar(&minhaFila, 40);
    enfileirar(&minhaFila, 50);
    mostrarFila(&minhaFila);

    printf("\n2. Removendo 2 valores (10 e 20)...\n");
    desenfileirar(&minhaFila);
    desenfileirar(&minhaFila);
    mostrarFila(&minhaFila);

    printf("\n3. Inserindo mais 2 valores (60 e 70)...\n");
    enfileirar(&minhaFila, 60);
    enfileirar(&minhaFila, 70);
    mostrarFila(&minhaFila);
    printf("========================================\n\n");

    // Menu interativo após o teste obrigatório
    do {
        printf("\n=== MENU FILA COM REUTILIZACAO ===\n");
        printf("1. Enfileirar (Entrar na fila)\n");
        printf("2. Desenfileirar (Atender e deslocar)\n");
        printf("3. Mostrar Fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor para entrar na fila: ");
                scanf("%d", &valor);
                enfileirar(&minhaFila, valor);
                break;
            case 2:
                desenfileirar(&minhaFila);
                break;
            case 3:
                mostrarFila(&minhaFila);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}