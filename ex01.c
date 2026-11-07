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
        printf("\n[SUCESSO] %d foi empilhado no topo!\n", valor);
    }
}

void desempilhar(Pilha *p) {
    if (p->topo == -1) {
        printf("\n[ERRO] A pilha esta vazia (Stack Underflow)!\n");
    } else {
        printf("\n[SUCESSO] %d foi desempilhado!\n", p->itens[p->topo]);
        p->topo--;
    }
}

/* Nova funcao: Consulta o topo sem remover */
void consultarTopo(Pilha *p) {
    if (p->topo == -1) {
        printf("\n[PILHA VAZIA] Nao ha elementos no topo.\n");
    } else {
        printf("\n[CONSULTA] O elemento no topo e: %d\n", p->itens[p->topo]);
    }
}

/* Nova funcao: Mostra a quantidade calculada pelo campo topo (sem contador extra) */
void mostrarQuantidade(Pilha *p) {
    int quantidade = p->topo + 1;
    printf("\n[QUANTIDADE] A pilha possui %d elemento(s) armazenado(s).\n", quantidade);
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
    int opcao, valor;

    do {
        printf("\n=== MENU PILHA (LIFO) ===\n");
        printf("1. Empilhar (Push)\n");
        printf("2. Desempilhar (Pop)\n");
        printf("3. Mostrar Pilha\n");
        printf("4. Consultar Topo\n");
        printf("5. Mostrar Quantidade de Elementos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor para empilhar: ");
                scanf("%d", &valor);
                empilhar(&minhaPilha, valor);
                break;
            case 2:
                desempilhar(&minhaPilha);
                break;
            case 3:
                mostrarPilha(&minhaPilha);
                break;
            case 4:
                consultarTopo(&minhaPilha);
                break;
            case 5:
                mostrarQuantidade(&minhaPilha);
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