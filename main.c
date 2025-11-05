#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// ------------------------------------
typedef struct alerta {
    int user;
    int time;
    int br;
    float km; 
    char tipo;
    int upvotes;
    
    Alerta* proximo;
} Alerta;

// ------------------------------------

float agruparKm(float km) {
    int parte = (int)km;
    int decimal = (int)((km - parte) * 10);

    if (decimal <= 4) return parte * 1.0;
    else return parte + 0.5;
}

void adicionarOuIncrementar(Alerta structAlerta, Alerta** vetor, int pos) {
    structAlerta.km = agruparKm(structAlerta.km);

    Alerta* structAtual;
    structAtual = *vetor;
    // em construção...

// analisando e tentando entender se há algo para aproveitar
/* 
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
*/
}

void linhaParaLista(char caminho[], Alerta** vetor){

    FILE* pontArq = fopen(caminho, "r");
    if(pontArq == NULL) printf("Impossível abrir arquivo!\n");
    else{

        char cabecalho[256];
        int user, time, br;
        float km;
        char tipo;

        fgets(cabecalho, sizeof(cabecalho), pontArq);
        
        while(fscanf("%d;%d;%d;%f;%c", &user, &time, &br, &km, &tipo) == 5){

            Alerta structAlerta;

            structAlerta.user = user;
            structAlerta.time = time;
            structAlerta.br = br;
            structAlerta.km = km;
            structAlerta.tipo = tipo;

            int pos = structAlerta.br % 100;

            adicionarOuIncrementar(structAlerta, vetor, pos);
        }
    }
}

// ------------------------------------
int main(){
    int escolha = 0;
    Alerta* hash[100];

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