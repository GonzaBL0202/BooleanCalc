#ifndef TIPOCOMANDO_H_
#define TIPOCOMANDO_H_

#include "listastrings.h"
typedef enum {ATOMIC, COMPOUND, EVALUATE, SHOW, SAVE, LOAD, EXIT, ERRORCOMANDO, VACIO} TipoComando;

void mostrarComando (TipoComando com);


#endif