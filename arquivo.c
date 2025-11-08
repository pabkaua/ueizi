//
// Created by joao on 06/11/2025.
//

#include <stdio.h>
#include "arquivo.h"

void linhaParaLista(char caminho[], Alerta** vetor) {
    FILE* pontArq = fopen(caminho, "r");
    if (pontArq == NULL) {
        printf("Impossível abrir arquivo!\n");
        return;
    }

    char cabecalho[256];
    int user, time, br;
    float km;
    char tipo;

    fgets(cabecalho, sizeof(cabecalho), pontArq);

    while (fscanf(pontArq, "%d;%d;%d;%f;%c", &user, &time, &br, &km, &tipo) == 5) {
        Alerta structAlerta;
        structAlerta.user = user;
        structAlerta.time = time;
        structAlerta.br = br;
        structAlerta.km = km;
        structAlerta.tipo = tipo;
        structAlerta.proximo = NULL;

        int pos = br % 100;
        adicionarOuIncrementar(structAlerta, vetor, pos);
    }

    fclose(pontArq);
}