#include "arbolexpre.h"

void CrearArbol (ArbolDeExpresiones &a) {
    a = NULL;
}

void CopiarArbol (ArbolDeExpresiones &arb, ArbolDeExpresiones a) {
    if (a!=NULL) {
        arb = new NodoA;
        arb->info = a->info;
        arb->hizq = NULL;
        arb->hder = NULL;
        CopiarArbol(arb->hizq,a->hizq);
        CopiarArbol(arb->hder,a->hder);
    }
    else
        arb = NULL;
}

//precondición: debe ser luego de un compound y el valordelnodo es un operador
ArbolDeExpresiones CargarArbolExpre (ValorDelNodo nodo, ArbolDeExpresiones a1, ArbolDeExpresiones a2) {
    ArbolDeExpresiones a;
    CrearArbol(a);
    a = new NodoA;
    a -> info = nodo;
    a -> hizq = a1;
    ParentesisIzq(a);
    a -> hder = a2;
    ParentesisDer(a);
    return a;
}

ArbolDeExpresiones CargarArbolNot (ValorDelNodo nodo, ArbolDeExpresiones a1) {
    ArbolDeExpresiones a;
    CrearArbol(a);
    a = new NodoA;
    a -> info = nodo;
    a-> hizq = NULL;
    ParentesisIzq(a);
    a -> hder = a1;
    ParentesisDer(a);
    return a;
}

void ParentesisIzq (ArbolDeExpresiones &a){
    if (a -> hizq == NULL) {
        a->hizq=new NodoA;
        a->hizq->info.discriminante = PARENTESIS;
        a->hizq->info.dato.parentesis ='(';
        a->hizq->hizq = NULL;
        a->hizq->hder = NULL;
    }
    else
        ParentesisIzq(a->hizq);
}

void ParentesisDer (ArbolDeExpresiones &a){
    if (a -> hder == NULL) {
        a->hder=new NodoA;
        a->hder->info.discriminante = PARENTESIS;
        a->hder->info.dato.parentesis =')';
        a->hder->hizq=NULL;
        a->hder->hder=NULL;
    }
    else
        ParentesisDer(a->hder);
}

//precondición: debe ser luego de un atomic y el valordelnodo es un valor boolean
ArbolDeExpresiones CargarArbolUnValor (ValorDelNodo nodo) {
    ArbolDeExpresiones a;
    CrearArbol(a);
    a = new NodoA;
    a -> info = nodo;
    a -> hizq = NULL;
    a -> hder = NULL;

    return a;
}


void MostrarArbolEnOrden (ArbolDeExpresiones a){
    if(a != NULL){
        MostrarArbolEnOrden (a -> hizq);
        MostrarValorDelNodo(a->info);
        MostrarArbolEnOrden (a -> hder);
    }
}

//pre: arbol no está vacío
boolean EvaluarExpresion (ArbolDeExpresiones arb) { 
    if (arb == NULL) 
        return TRUE;
    else { 
        if ((arb->info.discriminante) == VALOR) 
            return (arb->info.dato.valor); 
        else { 
            switch ((arb->info.dato.operador)) { 
                case 'o': 
                    return (boolean) ( EvaluarExpresion(arb->hizq) || EvaluarExpresion(arb->hder) ) ; 
                    break; 
                case 'a': return(boolean) (EvaluarExpresion(arb->hizq) && EvaluarExpresion(arb->hder)); 
                    break; 
                case 'n': return(boolean) !EvaluarExpresion (arb->hder); 
                    break; 
            } 
        } 
    } 
}

void EnumerarArbol (ArbolDeExpresiones &a, int &contador){
    if(a != NULL){
        EnumerarArbol(a->hizq, contador);
        a->info.numero=contador;
        contador++;
        EnumerarArbol (a -> hder, contador);
    }
}

void Bajar_ArbolAux (ArbolDeExpresiones a, FILE * f){
    if (a != NULL){
        Bajar_ValorDelNodo(a -> info, f);
        Bajar_ArbolAux (a -> hizq, f);
        Bajar_ArbolAux (a -> hder, f);
    }
}

void InsertarEnumerado (ArbolDeExpresiones &a,  ValorDelNodo vn){
if (a == NULL){
    a = new NodoA;
    a -> info = vn;
    a -> hizq = NULL;
    a -> hder = NULL;
} else {
    if (vn.numero < a->info.numero)
        InsertarEnumerado (a -> hizq, vn);
    else
        InsertarEnumerado (a -> hder, vn);
    }
}

void DestruirArbol(ArbolDeExpresiones &a) {
    if (a != NULL) {
        DestruirArbol(a->hizq);
        DestruirArbol(a->hder);
        delete a;
        a = NULL;
    }
}