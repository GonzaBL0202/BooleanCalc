#include "boolean.h"
//implementación de los subprogramas definidos en el .h
void cargarbool (boolean & b)
{
    char valor;
    fflush(stdin);
    scanf ("%c",& valor);
    if (valor == 's' || valor == 'S')
        b = TRUE;
    else
        b = FALSE;
}
void mostrarbool (boolean b)
{
    if (b)
        printf ("verdadero");
    else
        printf ("falso");
}
