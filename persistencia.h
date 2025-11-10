#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "alertas.h"

void salvarBase(Alerta* hash[], int tamanho);
void carregarBase(Alerta* hash[], int tamanho);

#endif