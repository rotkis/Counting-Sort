#include <stdio.h>

typedef int vetor[13];

void countingSort(vetor v) {
    int maior = v[0];
    for (int i = 1; i < 13; i++) {
        if (maior < v[i]) {
            maior = v[i];
        }
    }

    // Passo 1: Criar vetor de contagem
    int c[maior + 1];
    
    // Inicializar com zeros
    for (int i = 0; i <= maior; i++) {
        c[i] = 0;
    }

    // Contar ocorrências
    for (int i = 0; i < 13; i++) {
        c[v[i]]++;
    }

    printf("Contador: ");
    for (int i = 0; i < maior; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    // Passo 2: Fazer a contagem acumulada
    for (int i = 1; i <= maior; i++) {
        c[i] += c[i - 1];
    }
    
    // Passo 3: Criar vetor auxiliar ordenado
    int aux[13];
    
    // Colocar elementos nas posições corretas
    for (int i = 12; i >= 0; i--) {
        aux[c[v[i]] - 1] = v[i];
        c[v[i]]--;
    }

    // Passo 4: Imprimir o vetor auxiliar ordenado
    printf("Vetor ordenado: ");
    for (int i = 0; i < 13; i++) {
        printf("%d ", aux[i]);
    }
    printf("\n");
}

int main() {
    vetor v = {7,9,7,5,3,2,8,5,4,12,10,10,6};
    countingSort(v);
    return 0;
}