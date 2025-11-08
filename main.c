#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "alertas.h"
#include "arquivo.h"

int main(){
    int escolha = -1;
    Alerta* hash[100];
    for(int i = 0; i < 100; i++) hash[i] = NULL;

    while(escolha != 0){
        printf("1 - Ler arquivo\n");
        printf("2 - Mostrar Hash\n");
        printf("3 - \n");
        printf("4 - \n");
        printf("0 - SAIR\n");

        scanf("%d", &escolha);
        getchar();

        switch (escolha){
        case 1:
            linhaParaLista("alertas_1000000.csv", hash);
            break;

        case 2:
            imprimirHash(hash, 100);
            break;

        case 3:

            break;

        case 4:

            break;

        case 0:
            escolha = 0;
            break;
        
        default:
            printf("Digite um valor válido!\n");
            break;
        }
    }
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