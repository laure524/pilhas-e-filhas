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
        f->inicio++; 
    }
}

/* Nova funcao: Consulta o primeiro elemento da fila sem remove-lo */
void consultarInicio(Fila *f) {
    if (f->inicio == f->fim) {
        printf("\n[FILA VAZIA] Nao ha elementos aguardando na fila.\n");
    } else {
        printf("\n[CONSULTA] O proximo elemento no inicio da fila e: %d\n", f->itens[f->inicio]);
    }
}

/* Nova funcao: Calcula a quantidade usando apenas fim - inicio (sem contador extra) */
void mostrarQuantidade(Fila *f) {
    int quantidade = f->fim - f->inicio;
    printf("\n[QUANTIDADE] Ha %d elemento(s) aguardando na fila.\n", quantidade);
}

void mostrarFila(Fila *f) {
    if (f->inicio == f->fim) {
        printf("\nA fila esta vazia.\n");
    } else {
        printf("\n--- ESTADO ATUAL DA FILA ---\n");
        printf("Inicio -> ");
        for (int i = f->inicio; i < f->fim; i++) {
            printf("[%d] ", f->itens[i]);
        }
        printf("<- Fim\n");
    }
}

int main() {
    Fila minhaFila;
    iniciarFila(&minhaFila);
    int opcao, valor;

    do {
        printf("\n=== MENU FILA (FIFO) ===\n");
        printf("1. Enfileirar (Entrar na fila)\n");
        printf("2. Desenfileirar (Atender)\n");
        printf("3. Mostrar Fila\n");
        printf("4. Consultar Proximo Elemento\n");
        printf("5. Mostrar Quantidade de Elementos\n");
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
            case 4:
                consultarInicio(&minhaFila);
                break;
            case 5:
                mostrarQuantidade(&minhaFila);
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