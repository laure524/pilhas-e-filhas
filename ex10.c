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
        printf("\n[ERRO] A fila de tarefas esta cheia!\n");
    } else {
        f->itens[f->fim] = valor;
        f->fim++;
        printf("\n[SUCESSO] Tarefa %d adicionada ao sistema.\n", valor);
    }
}

// Retira a tarefa do inicio e retorna seu identificador
int retirarTarefa(Fila *f) {
    if (f->inicio == f->fim) {
        return -1; // Fila vazia
    } else {
        int idTarefa = f->itens[f->inicio];
        
        // Desloca os elementos restantes para a esquerda
        for (int i = f->inicio + 1; i < f->fim; i++) {
            f->itens[i - 1] = f->itens[i];
        }
        f->fim--;
        return idTarefa;
    }
}

void mostrarFila(Fila *f) {
    if (f->inicio == f->fim) {
        printf("\n[AVISO] Nenhuma tarefa pendente no sistema.\n");
    } else {
        printf("\n--- FILA DE TAREfas PENDENTES ---\n");
        printf("Inicio -> ");
        for (int i = f->inicio; i < f->fim; i++) {
            printf("[%d] ", f->itens[i]);
        }
        printf("<- Fim (Total: %d)\n", f->fim - f->inicio);
    }
}

void executarRodada(Fila *f) {
    if (f->inicio == f->fim) {
        printf("\n[AVISO] Nao ha tarefas para executar na rodada.\n");
        return;
    }

    int tarefaAtual = retirarTarefa(f);
    printf("\n========================================\n");
    printf(" Executando a tarefa ID: %d\n", tarefaAtual);
    printf("========================================\n");
    
    int status;
    printf("A tarefa %d foi concluida? (1- Sim / 0- Nao): ", tarefaAtual);
    scanf("%d", &status);

    if (status == 1) {
        printf("\n[SUCESSO] Tarefa %d concluida e removida definitivamente do sistema.\n", tarefaAtual);
    } else {
        printf("\n[REINSERCAO] Tarefa %d nao concluida. Retornando ao final da fila...\n", tarefaAtual);
        enfileirar(f, tarefaAtual);
    }
}

int main() {
    Fila filaTarefas;
    iniciarFila(&filaTarefas);
    int opcao, id;

    // --- TESTE OBRIGATÓRIO DE DEMONSTRAÇÃO ---
    printf("========================================\n");
    printf("       EXECUTANDO TESTE OBRIGATORIO     \n");
    printf("========================================\n");
    printf("Inserindo tarefas iniciais: 1, 2, 3\n");
    enfileirar(&filaTarefas, 1);
    enfileirar(&filaTarefas, 2);
    enfileirar(&filaTarefas, 3);
    mostrarFila(&filaTarefas);
    printf("========================================\n\n");

    do {
        printf("\n=== MENU - RODIZIO DE TAREFAS (ROUND ROBIN) ===\n");
        printf("1. Adicionar nova tarefa\n");
        printf("2. Executar rodada (Processar proxima tarefa)\n");
        printf("3. Mostrar tarefas pendentes\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o identificador da nova tarefa (inteiro): ");
                scanf("%d", &id);
                enfileirar(&filaTarefas, id);
                break;
            case 2:
                executarRodada(&filaTarefas);
                break;
            case 3:
                mostrarFila(&filaTarefas);
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