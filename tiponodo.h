#ifndef TIPONODO_H_
#define TIPONODO_H_
#include <stdio.h>

typedef enum {OPERADOR, VALOR, PARENTESIS, ERRORTIPONODO} TipoNodo;

void MostrarTipoNodo (TipoNodo t);

#endif