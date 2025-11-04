#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// ------------------------------------
typedef struct alerta {
    int idUsuario;
    int timestamp;
    int br;
    int km; 
    int tipoAlerta;
    
    Alerta* proximo;
} Alerta;

// ------------------------------------
void criaLista(){
    
}

// ------------------------------------
int main(){
    int escolha = 0;
    Alerta* inicio = malloc(sizeof(Alerta));

    while(escolha != 0){
        printf("1 - \n");
        printf("2 - \n");
        printf("3 - \n");
        printf("4 - \n");
        printf("0 - SAIR\n");

        scanf("%d", escolha);
        getchar();

        switch (escolha){
        case 1:
            /* code */
            break;

        case 2:
            /* code */
            break;

        case 3:
            /* code */
            break;

        case 4:
            /* code */
            break;

        case 0:
            escolha = 0;
            break;
        
        default:
            printf("Digite um valor válido!\n");
            break;
        }
    }
    return 0;
}