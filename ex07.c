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

void gerarSenha(Fila *f, int *contadorSenhas) {
    if (f->fim == MAX) {
        printf("\n[ERRO] A fila esta cheia! Nao e possivel gerar nova senha no momento.\n");
    } else {
        int senhaGerada = (*contadorSenhas)++;
        f->itens[f->fim] = senhaGerada;
        f->fim++;
        printf("\n[SUCESSO] Senha %d gerada e adicionada ao final da fila!\n", senhaGerada);
    }
}

void chamarProximaSenha(Fila *f) {
    if (f->inicio == f->fim) {
        printf("\n[ERRO] A fila esta vazia! Nao ha pessoas para atender.\n");
    } else {
        printf("\n[ATENDIMENTO] Chamando a senha: %d\n", f->itens[f->inicio]);
        f->inicio++;
    }
}

void consultarProximaSenha(Fila *f) {
    if (f->inicio == f->fim) {
        printf("\n[AVISO] A fila esta vazia. Nenhuma senha aguardando.\n");
    } else {
        printf("\n[CONSULTA] A proxima senha a ser atendida e: %d\n", f->itens[f->inicio]);
    }
}

void mostrarSenhas(Fila *f) {
    if (f->inicio == f->fim) {
        printf("\n[AVISO] A fila de atendimento esta vazia.\n");
    } else {
        printf("\n--- SENHAS AGUARDANDO ATENDIMENTO ---\n");
        printf("Inicio -> ");
        for (int i = f->inicio; i < f->fim; i++) {
            printf("[%d] ", f->itens[i]);
        }
        printf("<- Fim\n");
    }
}

int main() {
    Fila filaSenhas;
    iniciarFila(&filaSenhas);
    int contadorSenhas = 1; // Começa em 1 conforme enunciado
    int opcao;

    // --- TESTE OBRIGATÓRIO ---
    printf("========================================\n");
    printf("       EXECUTANDO TESTE OBRIGATORIO     \n");
    printf("========================================\n");
    
    printf("Gerando 3 senhas (1, 2 e 3)...\n");
    gerarSenha(&filaSenhas, &contadorSenhas);
    gerarSenha(&filaSenhas, &contadorSenhas);
    gerarSenha(&filaSenhas, &contadorSenhas);
    
    printf("\nRealizando 2 atendimentos:\n");
    chamarProximaSenha(&filaSenhas); // Atende senha 1
    chamarProximaSenha(&filaSenhas); // Atende senha 2
    
    printf("\nSenhas restantes aguardando atendimento:\n");
    mostrarSenhas(&filaSenhas); // Deve mostrar apenas a senha 3
    printf("========================================\n\n");

    // Menu interativo após o teste obrigatório
    do {
        printf("\n=== MENU - ATENDIMENTO POR SENHAS ===\n");
        printf("1. Gerar nova senha\n");
        printf("2. Chamar proxima senha (Atender)\n");
        printf("3. Consultar proxima senha\n");
        printf("4. Mostrar senhas aguardando\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                gerarSenha(&filaSenhas, &contadorSenhas);
                break;
            case 2:
                chamarProximaSenha(&filaSenhas);
                break;
            case 3:
                consultarProximaSenha(&filaSenhas);
                break;
            case 4:
                mostrarSenhas(&filaSenhas);
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