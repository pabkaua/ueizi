#include "persistencia.h"

#include <stdio.h>

#include "alertas.h"

void salvarBase(Alerta* hash[], int tamanho) {

    FILE* file = fopen("base_consolidada.csv", "w");
    if (!file) return;

    fprintf(file, "br;km;tipo;upvotes\n");

    for (int pos = 0; pos < tamanho; pos++) {
        Alerta* atual = hash[pos];

        while (atual != NULL) {
            fprintf(file, "%d;%.1f;%c;%d\n", atual->br,atual->km, atual->tipo, atual->upvotes);
            atual = atual->proximo;
        }
    }
    fclose(file);
}

void carregarBase(Alerta* hash[], int tamanho) {

    FILE* file = fopen("base_consolidada.csv", "r");
    if (!file) return;

    char lixo[200];
    fgets(lixo, 200, file);

    int br,up;
    float km;
    char tipo;

    while (fscanf(file, "%d;%f;%c;%d", &br, &km, &tipo, &up) == 4) {
        for (int i=0; i < tamanho; i++) {
            Alerta temp = {0,0,br,km,tipo,1,NULL};
            int pos = br % tamanho;
            adicionarOuIncrementar(temp, hash, pos);
        }
    }
    fclose(file);
}