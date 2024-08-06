#ifndef STRINGDINAMICO_H_INCLUDED
#define STRINGDINAMICO_H_INCLUDED
#include<stdio.h>
#include "boolean.h"
const int MAX=80;
typedef char * string;

void StrCrear (string &str);

int strlar (string str);

void print (string str);

void print2 (string str, int n);

void CargarComando (string &str);

boolean strmen(string str, string str2);

boolean streq(string str, string str2);

void strcopDinamico (string &str, string str2);

void strconDinamico(string &str, string str2);

void strswapDinamico(string &str, string &str2);

void StrDestruir (string &str);

void Bajar_String (string s, FILE * f);

void Levantar_String (string &s, FILE * f);

boolean Existe (string nom);

boolean SoloLetras (string str);

boolean SoloNumeros (string str);

boolean EsArchivo (string str);

#endif // STRINGDINAMICO_H_INCLUDED
