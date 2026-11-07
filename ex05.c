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
        printf("\n[ERRO] Historico cheio! Nao e possivel realizar mais alteracoes sem desfazer.\n");
    } else {
        p->topo++;
        p->itens[p->topo] = valor;
    }
}

int desempilhar(Pilha *p) {
    if (p->topo == -1) {
        return -1; // Pilha vazia
    } else {
        int valorRemovido = p->itens[p->topo];
        p->topo--;
        return valorRemovido;
    }
}

void consultarHistorico(int valorAtual, Pilha *p) {
    printf("\n========================================\n");
    printf("Valor Atual: %d\n", valorAtual);
    printf("----------------------------------------\n");
    if (p->topo == -1) {
        printf("Historico de desfazer: Vazio (nenhuma alteracao anterior).\n");
    } else {
        printf("Historico disponivel (do mais recente para o mais antigo):\n");
        for (int i = p->topo; i >= 0; i--) {
            printf("  -> Valor salvo: %d\n", p->itens[i]);
        }
    }
    printf("========================================\n");
}

int main() {
    Pilha historico;
    iniciarPilha(&historico);
    
    int valorAtual = 0; // Valor inicial igual a zero conforme enunciado
    int opcao, novoValor;

    do {
        printf("\n=== MENU - SISTEMA COM DESFAZER (UNDO) ===\n");
        printf("1. Alterar valor\n");
        printf("2. Desfazer ultima alteracao\n");
        printf("3. Consultar valor atual e historico\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Verifica se a pilha esta cheia antes de permitir a alteracao
                if (historico.topo == MAX - 1) {
                    printf("\n[ERRO] Pilha cheia! Impossivel alterar. Faca um 'Desfazer' primeiro.\n");
                    break;
                }
                printf("Digite o novo valor: ");
                scanf("%d", &novoValor);
                
                // Salva o valor atual na pilha antes de substitui-lo
                empilhar(&historico, valorAtual);
                valorAtual = novoValor;
                
                printf("\n[SUCESSO] Valor alterado para %d com sucesso!\n", valorAtual);
                break;

            case 2:
                if (historico.topo == -1) {
                    printf("\n[AVISO] Nao ha operacoes para desfazer (historico vazio).\n");
                } else {
                    valorAtual = desempilhar(&historico);
                    printf("\n[SUCESSO] Operacao desfeita! Valor restaurado para: %d\n", valorAtual);
                }
                break;

            case 3:
                consultarHistorico(valorAtual, &historico);
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