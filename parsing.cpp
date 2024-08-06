#include"parsing.h"

TipoComando esComando (ListaDeStrings L) {
    TipoComando com;
    if (L==NULL)
        com=VACIO;
    else if (streq(L->str,"atomic"))
        com=ATOMIC;
    else if(streq(L->str,"compound"))
        com=COMPOUND;
    else if(streq(L->str,"evaluate"))
        com=EVALUATE;
    else if(streq(L->str,"show"))
        com=SHOW;
    else if(streq(L->str,"load"))
        com=LOAD;
    else if (streq(L->str,"save"))
        com=SAVE;
    else if(streq(L->str,"exit"))
        com=EXIT;
    else 
        com=ERRORCOMANDO;

    return com;
}

boolean esBoolean (ListaDeStrings L) {
    boolean esbool=FALSE;
    
    if( streq((L->str), "true") || streq((L->str), "false") )
        esbool=TRUE;
    return esbool;
}

boolean esOperador (ListaDeStrings L){
    boolean es=FALSE;
    
    if( streq((L->str), "and") || streq((L->str), "or") || streq((L->str),"not") )
        es=TRUE;
    return es;
}

boolean esParentesis(ListaDeStrings L){
    boolean es=FALSE;
    
    if( streq((L->str), "(") || streq((L->str), ")") )
        es=TRUE;
    return es;
}

void cargarTipoNodo (TipoNodo &t, ListaDeStrings L){
    if(esBoolean(L))
        t=VALOR;
    else if(esOperador(L))
        t=OPERADOR;
    else if(esParentesis(L))
        t=PARENTESIS;
    else
        t=ERRORTIPONODO;
}


void ConvertirAValorNodo (ValorDelNodo &vn, ListaDeStrings L){
    cargarTipoNodo(vn.discriminante, L);
    switch(vn.discriminante){
        case VALOR: if(streq(L->str, "true"))
                    vn.dato.valor=TRUE;
                    else if(streq(L->str,"false"))
                    vn.dato.valor=FALSE;
                    break;
        
        case OPERADOR: if(streq(L->str,"and"))
                        vn.dato.operador='a';
                        else if(streq(L->str,"or"))
                        vn.dato.operador='o';
                        else if(streq(L->str,"not"))
                        vn.dato.operador='n';
                            break;
        
        case PARENTESIS: if(streq(L->str,"("))
                            vn.dato.parentesis='(';
                            else if(streq(L->str,")"))
                            vn.dato.parentesis=')';
                            break;
        default: break;
    }
}

void Bajar_Arbol (ArbolDeExpresiones a, string nomArch) {
    FILE * f = fopen (nomArch, "wb");
    Bajar_ArbolAux (a, f);
    fclose (f);
}


void Levantar_Arbol (ArbolDeExpresiones &a, string nomArch){
    FILE * f = fopen (nomArch, "rb");
    ValorDelNodo buffer;
    CrearArbol(a);
    Levantar_ValorDelNodo (buffer, f);
    while (!feof(f)){
        InsertarEnumerado (a, buffer);
        Levantar_ValorDelNodo (buffer, f);
    }
    fclose (f);
}

void EjecutarAtomic (ListaDeStrings ls, ListaDeExpresiones &le){
    ValorDelNodo vn;
    ArbolDeExpresiones ae;
    Expresion e;
    
    ConvertirAValorNodo(vn,ls);
    ae=CargarArbolUnValor(vn);
    CargarExpresion(e, ae);
    InsertarEnListaExpresion(le,e);
}

void EjecutarShow (ListaDeExpresiones le, int numero){
    Expresion aux;
    aux=EncontrarExpresion(numero, le);
    MostrarArbolEnOrden(aux.ar);
}

void EjecutarEvaluate(ListaDeExpresiones le, int numero){
    boolean evaluar;
    Expresion aux;
    
    aux=EncontrarExpresion(numero, le);
    evaluar= EvaluarExpresion(aux.ar);
    if(evaluar)
        printf("\tLa expresion vale TRUE\n");
    else
        printf("\tLa expresion vale FALSE\n");   
}

void EjecutarCompoundNOT (ListaDeStrings ls, ListaDeExpresiones &le, int numero){
    ValorDelNodo vn;
    ArbolDeExpresiones ae,arbolCopia;
    Expresion e, e2;

    e2=EncontrarExpresion(numero, le);
    CrearArbol(arbolCopia);
    CopiarArbol(arbolCopia, e2.ar);

    ConvertirAValorNodo(vn,ls);
    ae=CargarArbolNot(vn, arbolCopia);
    CargarExpresion(e, ae);
    InsertarEnListaExpresion(le,e);
}

void EjecutarCompound (ListaDeStrings ls, ListaDeExpresiones le, int num1, int num2){
    ValorDelNodo vn;
    ArbolDeExpresiones ae, arbolCopia1, arbolCopia2;
    Expresion e, e1, e2;

    e1=EncontrarExpresion(num1, le);
    CrearArbol(arbolCopia1);
    CopiarArbol(arbolCopia1, e1.ar);

    e2=EncontrarExpresion(num2, le);
    CrearArbol(arbolCopia2);
    CopiarArbol(arbolCopia2, e2.ar);

    ConvertirAValorNodo(vn,ls);
    ae=CargarArbolExpre(vn, arbolCopia1, arbolCopia2);
    CargarExpresion(e, ae);
    InsertarEnListaExpresion(le,e);
}

void EjecutarSave (ListaDeExpresiones le, int num, string &NomArch){
    Expresion e;
    int contador=1;
    
    e=EncontrarExpresion(num, le);
    EnumerarArbol(e.ar, contador);
    Bajar_Arbol(e.ar, NomArch);
}

void EjecutarLoad (ListaDeExpresiones &le, string NomArch){
    Expresion e;
    ArbolDeExpresiones a;

    Levantar_Arbol(a, NomArch);
    CargarExpresion(e, a);
    InsertarEnListaExpresion(le, e);
}

/*void EjecutarExit (ListaDeExpresiones &le, ListaDeStrings &ls) {
    while (ls!=NULL) {
        StrDestruir(ls->str);
        ls=ls->sig;
    }
    delete ls;
    ls = NULL;

    while (le!=NULL) {
        
    }
}
*/
void EjecutarExit (ListaDeExpresiones &le, ListaDeStrings &ls) {
    ListaDeStrings LSaux;
    ListaDeExpresiones LEaux;

        LSaux=ls;
        while (ls!=NULL) {
            //StrDestruir(LSaux->str);
            ls=ls->sig;
            delete LSaux;
            LSaux= ls;
        }
    
        LEaux=le;
        while (le!=NULL) {
            DestruirArbol(LEaux->expre.ar);
            le=le->sig;
            delete LEaux;
            LEaux= le;
        }
}