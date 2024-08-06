#include "valordelnodo.h"

//pre: no es errortiponodo
void MostrarValorDelNodo (ValorDelNodo vn){
switch(vn.discriminante){
    case VALOR: if(vn.dato.valor==TRUE)
                    printf("true ");
                else 
                    printf("false ");
                break;
    case OPERADOR: if(vn.dato.operador=='a')
                        printf("and ");
                    else if(vn.dato.operador=='o')
                        printf("or ");
                    else printf("not ");
                    break;
    case PARENTESIS: if(vn.dato.parentesis=='(')
                        printf("( ");
                    else
                        printf(") ");
                    break;
}
}

void Bajar_ValorDelNodo (ValorDelNodo vn, FILE * f) {
    fwrite (&vn.numero, sizeof(int), 1, f);
    fwrite (&vn.discriminante, sizeof(TipoNodo), 1, f);
    if (vn.discriminante == VALOR)
        fwrite (&vn.dato, sizeof(boolean), 1, f);
    else
        fwrite (&vn.dato, sizeof(char), 1, f);
}

void Levantar_ValorDelNodo (ValorDelNodo &vn, FILE * f) {
    fread (&vn.numero, sizeof(int), 1, f);
    fread (&vn.discriminante, sizeof(TipoNodo), 1, f);
    if (vn.discriminante == VALOR)
        fread (&vn.dato, sizeof(boolean), 1, f);
    else
        fread (&vn.dato, sizeof(char), 1, f);
}
