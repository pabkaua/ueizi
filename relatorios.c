#include <stdio.h>
#include "relatorios.h"

void gerarRelatorioPorBr(Alerta* hash[], int tamanho, int br, float ini, float fim) {

    FILE* file = fopen("alertas_por_br.csv", "w");
    if(!file) {
        printf("erro na abertura do arquivo\n");
        return;
    }

    fprintf(file, "br;km;tipoAlerta;upvotes\n");

    int pos = br % tamanho;
    Alerta* atual = hash[pos];

    while(atual != NULL) {
        if (atual->br == br && atual->km >= ini && atual->km <= fim) {
            fprintf(file, "%d,%.1f,%c,%d\n", atual->br, atual->km, atual->tipo, atual->upvotes);
        }
        atual = atual->proximo;
    }
    fclose(file);
    printf("Relatorio gerado\n");
}

void gerarRelatorioTipos(Alerta* hash[], int tamanho) {

    FILE* file = fopen("alertas_br_todas.csv", "w");
    if (!file) {
        printf("Erro.\n");
        return;
    }

    fprintf(file, "br;tipoAlerta;quantidade\n");

    for (int pos = 0; pos < tamanho; pos++) {

        if (hash[pos] == NULL) continue;


        int br = hash[pos]->br;

        int cont[6] = {0};

        Alerta* atual = hash[pos];
        while (atual != NULL) {
            int idx = atual->tipo - 'A';
            if (idx >= 0 && idx < 6)
                cont[idx] += atual->upvotes;

            atual = atual->proximo;
        }

        for (int i = 0; i < 6; i++) {
            if (cont[i] > 0)
                fprintf(file, "%d;%c;%d\n", br, 'A'+i, cont[i]);
        }
    }

    fclose(file);
    printf("\nRelatorio gerado\n");
}

void imprimirRelatorioPorBR() {
    FILE* file = fopen("alertas_por_br.csv", "r");
    if (!file) {
        printf("Relatorio de -alertas_por_br.csv- não encontrado.\n");
        return;
    }

    char linha[256];
    printf("\n Relatorio de alertas por br e trecho \n");

    while (fgets(linha, sizeof(linha), file)) {
        printf("%s", linha);
    }
    fclose(file);
}

void imprimirRelatorioTipos() {

    FILE* file = fopen("alertas_br_todas.csv", "r");
    if (!file) {
        printf("Relatorio de -alertas_br_todas.csv- nao encontrado.\n");
        return;
    }

    char linha[256];
    printf("\n Relatorio de alertas por tipo \n");

    while (fgets(linha, sizeof(linha), file)) {
        printf("%s", linha);
    }

    fclose(file);
}