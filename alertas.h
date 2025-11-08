//
// Criado por joaogt01 em 03/11/2025.
//

#ifndef ALERTAS_H
#define ALERTAS_H

typedef struct alerta {
    int user;
    int time;
    int br;
    float km; 
    char tipo;
    int upvotes;
    
    struct alerta* proximo;
} Alerta;

int carregarCSV(const char *caminho, Alerta **hash);

float agruparKm(float km);
void adicionarOuIncrementar(Alerta structAlerta, Alerta** vetor, int pos);
void imprimirHash(Alerta* vetor[], int tamanho);
#endif