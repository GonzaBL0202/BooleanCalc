#ifndef EXPRESION_H_
#define EXPRESION_H_
#include "arbolexpre.h"


typedef struct { 
    int numExp;
    ArbolDeExpresiones ar;
        } Expresion;


void CargarExpresion (Expresion &e, ArbolDeExpresiones arb);

#endif