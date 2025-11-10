#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "alertas.h"

void gerarRelatorioPorBr(Alerta* hash[], int tamanho, int br, float ini, float fim);
void gerarRelatorioTipos(Alerta* hash[], int tamanho);
void imprimirRelatorioPorBR();
void imprimirRelatorioTipos();


#endif