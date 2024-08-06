#ifndef LISTAEXPRESION_H_
#define LISTAEXPRESION_H_

#include "expresion.h"

typedef struct nodoL { 
    Expresion expre;
    nodoL * sig;
        } NodoL;
typedef NodoL * ListaDeExpresiones;

void CrearListaExpresion (ListaDeExpresiones &L);
void InsertarEnListaExpresion (ListaDeExpresiones &L,  Expresion e);
int LargoListaExp (ListaDeExpresiones L);
boolean PerteneceALista (int n, ListaDeExpresiones L);

//precondición: la expresion existe en la lista
Expresion EncontrarExpresion (int n, ListaDeExpresiones L);

void MostrarListaExpresion (ListaDeExpresiones L);

#endif