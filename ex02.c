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

void adicionarBandeja(Pilha *p, int idBandeja) {
    if (p->topo == MAX - 1) {
        printf("\n[ERRO] Pilha de bandejas cheia! Nao cabem mais bandejas no balcao.\n");
    } else {
        p->topo++;
        p->itens[p->topo] = idBandeja;
        printf("\n[SUCESSO] Bandeja ID %d adicionada ao topo da pilha.\n", idBandeja);
    }
}

void retirarBandeja(Pilha *p) {
    if (p->topo == -1) {
        printf("\n[ERRO] Pilha de bandejas vazia! Nao ha bandejas para retirar.\n");
    } else {
        printf("\n[SUCESSO] Bandeja ID %d foi retirada do topo da pilha.\n", p->itens[p->topo]);
        p->topo--;
    }
}

void consultarProximaBandeja(Pilha *p) {
    if (p->topo == -1) {
        printf("\n[AVISO] A pilha de bandejas esta vazia.\n");
    } else {
        printf("\n[CONSULTA] A proxima bandeja disponivel no topo e a de ID: %d\n", p->itens[p->topo]);
    }
}

void mostrarBandejas(Pilha *p) {
    if (p->topo == -1) {
        printf("\n[AVISO] A pilha de bandejas esta vazia.\n");
    } else {
        printf("\n--- PILHA DE BANDEJAS (Do Topo para a Base) ---\n");
        for (int i = p->topo; i >= 0; i--) {
            printf("| ID: %4d |\n", p->itens[i]);
        }
        printf("-------------\n");
    }
}

int main() {
    Pilha pilhaBandejas;
    iniciarPilha(&pilhaBandejas);
    int opcao, id;

    // --- TESTE OBRIGATÓRIO ---
    printf("========================================\n");
    printf("       EXECUTANDO TESTE OBRIGATORIO     \n");
    printf("========================================\n");
    
    printf("Adicionando bandejas 101, 102 e 103...\n");
    adicionarBandeja(&pilhaBandejas, 101);
    adicionarBandeja(&pilhaBandejas, 102);
    adicionarBandeja(&pilhaBandejas, 103);
    
    printf("\nRealizando 2 retiradas:\n");
    retirarBandeja(&pilhaBandejas); // Retira 103
    retirarBandeja(&pilhaBandejas); // Retira 102
    
    printf("\nEstado atual apos o teste obrigatorio:\n");
    mostrarBandejas(&pilhaBandejas); // Deve mostrar apenas a bandeja 101
    printf("========================================\n\n");

    // Menu interativo após o teste
    do {
        printf("\n=== MENU PILHA DE BANDEJAS ===\n");
        printf("1. Adicionar bandeja\n");
        printf("2. Retirar bandeja do topo\n");
        printf("3. Consultar proxima bandeja\n");
        printf("4. Mostrar todas as bandejas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o numero de identificacao da bandeja: ");
                scanf("%d", &id);
                adicionarBandeja(&pilhaBandejas, id);
                break;
            case 2:
                retirarBandeja(&pilhaBandejas);
                break;
            case 3:
                consultarProximaBandeja(&pilhaBandejas);
                break;
            case 4:
                mostrarBandejas(&pilhaBandejas);
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