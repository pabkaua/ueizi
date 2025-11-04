//
// Criado por joaogt01 em 03/11/2025.
//

#ifndef ALERTAS_H
#define ALERTAS_H

typedef struct {
    int br;
    float km;
    char tipo;
    int upvotes;
} Alerta;

typedef struct {
    Alerta* dados;
    int tamanho;
    int capacidade;
} ListaAlertas;

void inicializarLista(ListaAlertas *l);
void liberarLista(ListaAlertas *l);

int carregarCSV(const char *caminho, ListaAlertas *lista);

float agruparKm(float km);
void adicionarOuIncrementar(ListaAlertas *lista, int br, float km, char tipo);

#endif