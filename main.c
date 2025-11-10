#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "alertas.h"
#include "arquivo.h"
#include "relatorios.h"
#include "persistencia.h"

int main(){
    int escolha = -1;
    Alerta* hash[100];
    for(int i = 0; i < 100; i++) hash[i] = NULL;
    carregarBase(hash, 100);

    while(escolha != 0){
        printf("1 - Ler arquivo\n");
        printf("2 - Mostrar Hash\n");
        printf("3 - Relatorio por trecho de br\n");
        printf("4 - Relatorio por tipo\n");
        printf("5 - Mostrar relatorio br\n");
        printf("6 - Mostrar relatorio por tipo\n");
        printf("0 - SAIR\n");

        scanf("%d", &escolha);
        getchar();

        switch (escolha){
        case 1:
            linhaParaLista("alertas_1000_1.csv", hash);
            break;

        case 2:
            imprimirHash(hash, 100);
            break;

        case 3: {
            int br;
            float ini, fim;
            printf("br: ");
            scanf("%d", &br);

            printf("km inicio: ");
            scanf("%f", &ini);

            printf("km fim: ");
            scanf("%f", &fim);

            gerarRelatorioPorBr(hash, 100, br, ini, fim);
            break;
        }
        case 4:
            gerarRelatorioTipos(hash, 100);
            break;

        case 5:
            imprimirRelatorioPorBR();
            break;
        case 6:
            imprimirRelatorioTipos();
            break;
        case 0:
            escolha = 0;
            break;
        
        default:
            printf("Digite um valor válido!\n");
            break;
        }
    }
    salvarBase(hash, 100);
    for (int i = 0; i < 100; i++) {
        Alerta* atual = hash[i];
        while (atual != NULL) {
            Alerta* tmp = atual;
            atual = atual->proximo;
            free(tmp);
        }
    }
    return 0;
}