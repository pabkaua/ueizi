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

    struct alerta* proximo;
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
    Alerta* atual = vetor[pos];

    while (atual != NULL){
        if (atual->br == structAlerta.br &&
            atual->km == structAlerta.km &&
            atual->tipo == structAlerta.tipo){
            atual->upvotes++;
            return;
        }
        atual = atual->proximo;
    }

    Alerta* novo = malloc(sizeof(Alerta));
    if (novo == NULL){
        perror("Erro ao alocar memória");
        exit(1);
    }

    *novo = structAlerta;
    novo->upvotes = 1;
    novo->proximo = vetor[pos];
    vetor[pos] = novo;
}

void linhaParaLista(char caminho[], Alerta** vetor){

    FILE* pontArq = fopen(caminho, "r");
    if(pontArq == NULL){
        printf("Impossível abrir arquivo!\n");
        return;
    }


    char cabecalho[256];
    int user, time, br;
    float km;
    char tipo;

    fgets(cabecalho, sizeof(cabecalho), pontArq);

    while(fscanf(pontArq,"%d;%d;%d;%f;%c", &user, &time, &br, &km, &tipo) == 5){

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

void imprimirHash(Alerta* vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        Alerta* atual = vetor[i];
        while (atual != NULL){
            printf("BR%d km %.1f tipo %c upvotes %d\n",
                    atual->br,atual->km,atual->tipo,atual->upvotes);
            atual = atual->proximo;
        }
    }
}


// ------------------------------------
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
            linhaParaLista("alertas_1000_1.csv", hash);
            imprimirHash(hash, 100);
            break;

        case 2:
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
    return 0;
}
