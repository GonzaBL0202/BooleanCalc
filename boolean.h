#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED
#include <stdio.h>
typedef enum {FALSE, TRUE} boolean;
        //cabezales sintacticos de subprogramas
    void cargarbool (boolean & b);
        /* devuelve la variable cargada por el usuario */
    void mostrarbool (boolean b);
        /* muestra en pantalla el valor de la variable */


#endif // BOOLEAN_H_INCLUDED
