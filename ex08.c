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

void adicionarTrabalho(Fila *f, int idTrabalho) {
    if (f->fim == MAX) {
        printf("\n[ERRO] A fila de impressao esta cheia! Impossivel adicionar novos trabalhos.\n");
    } else {
        f->itens[f->fim] = idTrabalho;
        f->fim++;
        printf("\n[SUCESSO] Trabalho ID %d adicionado a fila de impressao.\n", idTrabalho);
    }
}

void imprimirProximo(Fila *f) {
    if (f->inicio == f->fim) {
        printf("\n[ERRO] A fila de impressao esta vazia! Nenhum trabalho pendente.\n");
    } else {
        printf("\n[IMPRESSAO] Imprimindo e removendo o trabalho ID: %d\n", f->itens[f->inicio]);
        f->inicio++;
    }
}

void listarPendentes(Fila *f) {
    if (f->inicio == f->fim) {
        printf("\n[AVISO] Nao ha trabalhos pendentes na fila de impressao.\n");
    } else {
        printf("\n--- TRABALHOS PENDENTES NA FILA ---\n");
        printf("Inicio -> ");
        for (int i = f->inicio; i < f->fim; i++) {
            printf("[%d] ", f->itens[i]);
        }
        printf("<- Fim\n");
    }
}

void imprimirTodos(Fila *f) {
    if (f->inicio == f->fim) {
        printf("\n[AVISO] A fila esta vazia. Nenhum trabalho para imprimir.\n");
    } else {
        printf("\n--- INICIANDO IMPRESSAO DE TODOS OS TRABALHOS ---\n");
        while (f->inicio != f->fim) {
            printf("[IMPRESSÃO EM LOTE] Processando trabalho ID: %d\n", f->itens[f->inicio]);
            f->inicio++;
        }
        printf("--- TODOS OS TRABALHOS FORAM IMPRESSOS ---\n");
        // Reinicializa os ponteiros para zerar a fila completamente
        f->inicio = 0;
        f->fim = 0;
    }
}

int main() {
    Fila filaImpressao;
    iniciarFila(&filaImpressao);
    int opcao, id;

    do {
        printf("\n=== MENU - FILA DE IMPRESSAO ===\n");
        printf("1. Adicionar trabalho\n");
        printf("2. Imprimir proximo trabalho\n");
        printf("3. Listar trabalhos pendentes\n");
        printf("4. Imprimir todos os trabalhos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o identificador do trabalho (numero inteiro): ");
                scanf("%d", &id);
                adicionarTrabalho(&filaImpressao, id);
                break;
            case 2:
                imprimirProximo(&filaImpressao);
                break;
            case 3:
                listarPendentes(&filaImpressao);
                break;
            case 4:
                imprimirTodos(&filaImpressao);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("\n[ERRO] Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}