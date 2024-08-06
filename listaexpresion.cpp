#include "listaexpresion.h"

void CrearListaExpresion (ListaDeExpresiones &L) {
    L = NULL;
}

void InsertarEnListaExpresion (ListaDeExpresiones &L,  Expresion e) {
    int num = LargoListaExp(L) + 1;
    
    ListaDeExpresiones nuevo = new NodoL;
    nuevo -> expre = e;
    nuevo->expre.numExp=num;
    nuevo -> sig = NULL;
    if (L == NULL)
        L = nuevo;
    else {
        ListaDeExpresiones aux = L;
        while (aux -> sig != NULL)
            aux = aux -> sig;
        aux -> sig = nuevo;
    }
}

int LargoListaExp (ListaDeExpresiones L) {
    int cont=0;
    while (L!=NULL) {
        cont++;
        L=L->sig;
    }
    return cont;
}

boolean PerteneceALista (int n, ListaDeExpresiones L) {
    return (boolean) (n<=LargoListaExp(L));
}

//precondición: la expresion existe en la lista
Expresion EncontrarExpresion (int n, ListaDeExpresiones L) {
    if (L != NULL)
        if (L->expre.numExp == n)
            return L->expre;
        else
            return EncontrarExpresion (n, L->sig);
}

void MostrarListaExpresion (ListaDeExpresiones L) {
    if(L != NULL){
        printf("Expresion %d:", L->expre.numExp);
        MostrarArbolEnOrden(L->expre.ar);
        MostrarListaExpresion(L->sig);
    }
}
