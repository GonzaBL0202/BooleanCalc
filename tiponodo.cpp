#include "tiponodo.h"

void MostrarTipoNodo (TipoNodo t) {
    switch (t) {
        case OPERADOR: printf("Tipo: operador");
            break;
        case VALOR: printf("Tipo: valor");
            break;
        case PARENTESIS: printf("Tipo: parentesis");
            break;
        default: printf ("Error");
            break;
    }
}