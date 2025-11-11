#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alertas.h"

float agruparKm(float km) {
    int parte = (int)km;
    int decimal = (int)((km - parte) * 10);

    if (decimal <= 4) return parte * 1.0;
    else return parte + 0.5;
}

void adicionarOuIncrementar(Alerta structAlerta, Alerta** vetor, int pos) {
    structAlerta.km = agruparKm(structAlerta.km);
    Alerta* atual = vetor[pos];

    while (atual != NULL) {
        if (
            atual->br == structAlerta.br &&
            atual->km == structAlerta.km &&
            atual->tipo == structAlerta.tipo) {
            atual->upvotes++;
            return;
        }
        atual = atual->proximo;
    }

    Alerta* novo = malloc(sizeof(Alerta));
    if (novo == NULL) {
        perror("Erro ao alocar memoria");
        exit(1);
    }

    *novo = structAlerta;
    novo->upvotes = 1;
    novo->proximo = vetor[pos];
    vetor[pos] = novo;
}

void imprimirHash(Alerta* vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        Alerta* atual = vetor[i];
        while (atual != NULL) {
            printf("BR%d km %.1f tipo %c upvotes %d\n",
                    atual->br, atual->km, atual->tipo, atual->upvotes);
            atual = atual->proximo;
        }
    }
}
