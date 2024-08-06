#ifndef LISTASTRINGS_H_
#define LISTASTRINGS_H_
#include "stringdinamico.h"

typedef struct nodoS { 
    string str;
    nodoS * sig; } NodoS;

typedef NodoS * ListaDeStrings;

void CargarListaStrings (ListaDeStrings &lstr, string str);
void MostrarListaStrings (ListaDeStrings L);
int Largo (ListaDeStrings lstr);

void CrearListaStr (ListaDeStrings &L);
boolean Vacia (ListaDeStrings L);
// Precondición: Lista NO vacía
void Primero (ListaDeStrings L, string &str);
//Precondición: Lista NO vacía
void Resto (ListaDeStrings &L);
void InsertarString(ListaDeStrings &L, string s);
int DevolverNumero (ListaDeStrings L);


#endif