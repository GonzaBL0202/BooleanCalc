#ifndef PARSING_H_INCLUDED
#define PARSING_H_INCLUDED

#include "tipocomando.h"
#include "listastrings.h"
#include "listaexpresion.h"

TipoComando esComando (ListaDeStrings L);
boolean esBoolean (ListaDeStrings L);
boolean esOperador (ListaDeStrings L);
boolean esParentesis (ListaDeStrings L);


void cargarTipoNodo (TipoNodo &t, ListaDeStrings L);
void ConvertirAValorNodo (ValorDelNodo &v, ListaDeStrings L);

void Bajar_Arbol (ArbolDeExpresiones a, string nomArch);
void Levantar_Arbol (ArbolDeExpresiones &a, string nomArch);

void EjecutarAtomic (ListaDeStrings ls, ListaDeExpresiones &le);
void EjecutarShow (ListaDeExpresiones le, int numero);
void EjecutarEvaluate (ListaDeExpresiones le, int numero);
void EjecutarCompoundNOT (ListaDeStrings ls,ListaDeExpresiones &le, int numero);
void EjecutarCompound (ListaDeStrings ls, ListaDeExpresiones le, int num1, int num2);
void EjecutarSave (ListaDeExpresiones le, int num, string &NomArch);
void EjecutarLoad (ListaDeExpresiones &le, string NomArch);
void EjecutarExit (ListaDeExpresiones &le, ListaDeStrings &ls);
#endif