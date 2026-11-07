#include <stdio.h>
#include <stdlib.h>

#define MAX 32 // Ajustado para suportar binarios maiores

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

int desempilhar(Pilha *p) {
    if (p->topo == -1) {
        return -1; // Pilha vazia
    } else {
        int valorRemovido = p->itens[p->topo];
        p->topo--;
        return valorRemovido;
    }
}

int main() {
    Pilha pilhaBinaria;
    iniciarPilha(&pilhaBinaria);
    
    int numero, temp;

    printf("=== CONVERSAO DE DECIMAL PARA BINARIO ===\n");
    printf("Digite um numero inteiro nao negativo: ");
    scanf("%d", &numero);

    // Rejeitando entradas negativas
    if (numero < 0) {
        printf("[ERRO] Entradas negativas nao sao permitidas!\n");
        return 1;
    }

    // Tratamento especial para o numero 0
    if (numero == 0) {
        printf("A representacao binaria de 0 e: 0\n");
        return 0;
    }

    temp = numero;

    // Divisoes sucessivas por 2 e empilhamento dos restos
    while (temp > 0) {
        int resto = temp % 2;
        empilhar(&pilhaBinaria, resto);
        temp = temp / 2;
    }

    // Desempilhando para exibir na ordem correta
    printf("A representacao binaria de %d e: ", numero);
    while (pilhaBinaria.topo != -1) {
        printf("%d", desempilhar(&pilhaBinaria));
    }
    printf("\n");

    return 0;
}