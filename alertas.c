#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alertas.h"


void inicializarLista(ListaAlertas *l) {
    l->dados = NULL;
    l->tamanho = 0;
    l->capacidade = 0;
}

void liberarLista(ListaAlertas *l) {
    free(l->dados);
    l->dados = NULL;
    l->tamanho = 0;
    l->capacidade = 0;
}

float agruparKm(float km) {
    int parte = (int)km;
    int decimal = (int)((km - parte) * 10);

    if (decimal <= 4) return parte * 1.0;
    else return parte + 0.5;
}

void adicionarOuIncrementar(ListaAlertas *lista, int br, float km, char tipo) {
    km = agruparKm(km);
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i].br == br &&
            lista->dados[i].km == km &&
            lista->dados[i].tipo == tipo) {
            lista->dados[i].upvotes++;
            return;
        }
    }

    if (lista->tamanho == lista->capacidade) {
        lista->capacidade = lista->capacidade == 0 ? 4 : lista->capacidade * 2;
        lista->dados = realloc(lista->dados, lista->capacidade * sizeof(Alerta));
        if (lista->dados == NULL) {
            perror("Erro ao redimensionar lista");
            exit(1);
        }
    }

    lista->dados[lista->tamanho].br = br;
    lista->dados[lista->tamanho].km = km;
    lista->dados[lista->tamanho].tipo = tipo;
    lista->dados[lista->tamanho].upvotes = 1;

    lista->tamanho++;
}

int carregarCSV(const char *caminho, ListaAlertas *lista) {
    FILE *arq = fopen("caminho dos arquivos", "r");
    if (!arq) return 0;


    char linha[256];

    fgets(linha, sizeof(linha), arq);

    while (fgets(linha, sizeof(linha), arq)) {
        char *token = strtok(linha, ";");
        if (!token) continue;

        int idUsuario = atoi(token);

        token = strtok(NULL, ";");
        long timestamp = atol(token);

        token = strtok(NULL, ";");
        int br = atoi(token);

        token = strtok(NULL, ";");
        float km = atof(token);

        token = strtok(NULL, ";");
        char tipo = token[0];

        float kmAgrupado = agruparKm(km);

        adicionarOuIncrementar(lista, br, kmAgrupado, tipo);
    }

    fclose(arq);
    return 1;
}
