#ifndef VALORDELNODO_H_INCLUDED
#define VALORDELNODO_H_INCLUDED
#include "tiponodo.h"
#include "boolean.h"

typedef struct { 
    int numero;
    TipoNodo discriminante;
    union { boolean valor;
            char operador; 
            char parentesis; 
            } dato;
} ValorDelNodo;

//pre: no es errortiponodo
void MostrarValorDelNodo (ValorDelNodo vn);

void Bajar_ValorDelNodo (ValorDelNodo vn, FILE * f);
void Levantar_ValorDelNodo (ValorDelNodo &vn, FILE * f);

#endif