#ifndef ARBOLEXPRE_H_
#define ARBOLEXPRE_H_
#include "valordelnodo.h"

typedef struct nodoA { 
    ValorDelNodo info;
    nodoA * hizq;
    nodoA * hder;
        } NodoA;
typedef NodoA * ArbolDeExpresiones;

void CrearArbol (ArbolDeExpresiones &a);

void CopiarArbol (ArbolDeExpresiones &a, ArbolDeExpresiones b);

//precondición: debe ser luego de un compound y el valordelnodo es un operador
ArbolDeExpresiones CargarArbolExpre (ValorDelNodo nodo, ArbolDeExpresiones a1, ArbolDeExpresiones a2);

//precondición: debe ser luego de un atomic y el valordelnodo es un valor boolean
ArbolDeExpresiones CargarArbolUnValor (ValorDelNodo nodo);

ArbolDeExpresiones CargarArbolNot (ValorDelNodo nodo, ArbolDeExpresiones a1);

//pre:arbol no está vacío
boolean EvaluarExpresion (ArbolDeExpresiones expre);

void ParentesisIzq (ArbolDeExpresiones &a);

void ParentesisDer (ArbolDeExpresiones &a);

void MostrarArbolEnOrden (ArbolDeExpresiones a);

void EnumerarArbol (ArbolDeExpresiones &a, int &contador);

void Bajar_ArbolAux (ArbolDeExpresiones a, FILE * f);

void InsertarEnumerado (ArbolDeExpresiones &a,  ValorDelNodo vn);

void DestruirArbol (ArbolDeExpresiones &a);

#endif