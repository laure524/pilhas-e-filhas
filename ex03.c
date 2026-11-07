#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void iniciarPilha(Pilha *p) {
    p->topo = -1;
}

void empilhar(Pilha *p, int valor) {
    if (p->topo == MAX - 1) {
        printf("\n[ERRO] A pilha esta cheia (Stack Overflow)!\n");
    } else {
        p->topo++;
        p->itens[p->topo] = valor;
    }
}

// Adaptada para retornar o valor removido
int desempilhar(Pilha *p) {
    if (p->topo == -1) {
        printf("\n[ERRO] A pilha esta vazia (Stack Underflow)!\n");
        return -1; // Valor de erro indicando pilha vazia
    } else {
        int valorRemovido = p->itens[p->topo];
        p->topo--;
        return valorRemovido;
    }
}

void mostrarPilha(Pilha *p) {
    if (p->topo == -1) {
        printf("\nA pilha esta vazia.\n");
    } else {
        printf("\n--- ESTADO ATUAL DA PILHA ---\n");
        for (int i = p->topo; i >= 0; i--) {
            printf("| %4d |\n", p->itens[i]);
        }
        printf("--------\n");
    }
}

int main() {
    Pilha minhaPilha;
    iniciarPilha(&minhaPilha);
    
    int qtd, i, valor;

    printf("=== INVERSAO DE SEQUENCIA COM PILHA ===\n");
    printf("Digite a quantidade de numeros (entre 1 e %d): ", MAX);
    scanf("%d", &qtd);

    if (qtd < 1 || qtd > MAX) {
        printf("[ERRO] Quantidade invalida! Deve estar entre 1 e %d.\n", MAX);
        return 1;
    }

    // Leitura e empilhamento dos valores
    for (i = 0; i < qtd; i++) {
        printf("Digite o %d.o numero: ", i + 1);
        scanf("%d", &valor);
        empilhar(&minhaPilha, valor);
    }

    printf("\nSequencia original lida e empilhada.");
    mostrarPilha(&minhaPilha);

    // Desempilhando e apresentando na ordem inversa
    printf("\n--- SEQUENCIA INVERTIDA (Ordem de Retirada) ---\n");
    for (i = 0; i < qtd; i++) {
        int ret = desempilhar(&minhaPilha);
        printf("[%d] ", ret);
    }
    printf("\n");

    // Verificando se a pilha ficou vazia
    mostrarPilha(&minhaPilha);

    return 0;
}