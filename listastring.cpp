#include "listastrings.h"

void CrearListaStr (ListaDeStrings & L) {
    L = NULL;
}


boolean Vacia (ListaDeStrings L){
    boolean es = FALSE;
    if (L == NULL)
        es = TRUE;
    return es;
}


//Pre: Lista NO vacía
void Primero (ListaDeStrings L, string &str) {
    StrCrear(str);
    strcopDinamico(str, L->str);
}


void Resto (ListaDeStrings &L) {
    ListaDeStrings aux=L;
    L=L->sig;
    delete aux; 
}


int Largo (ListaDeStrings L) {
    int cont=0;
    while (L!=NULL) {
        cont++;
        L=L->sig;
    }
    return cont;
}


void InsertarString ( ListaDeStrings &L, string s) {
    ListaDeStrings nuevo = new NodoS;
    StrCrear ( nuevo->str );
    strcopDinamico ( nuevo->str , s);
    nuevo->sig = NULL;
    if ( L == NULL )
        L = nuevo;
    else {
        ListaDeStrings aux = L;
        while ( aux->sig != NULL ) 
            aux = aux->sig;
        aux->sig = nuevo;
    }
}


void CargarListaStrings (ListaDeStrings &lstr, string s) {
    string aux;
    StrCrear(aux);
    int i=0;

    while (s[i]!='\0') {
        if (s[i]==' ')
            i++;
        else {
            int largo=0;
            while (s[i]!=' ' && s[i]!='\0') {
                i++;
                largo++;
            }
            aux= new char[largo+1];
            i=i-largo;
            int a=0;
            for (; largo>0; largo--) {
                aux[a]=s[i];
                i++;
                a++;
            }
            aux[a]='\0';
            InsertarString(lstr, aux);
            StrDestruir(aux);
        }
    }
}


void MostrarListaStrings (ListaDeStrings L){
    if(L != NULL){
        print(L->str);
        MostrarListaStrings(L->sig);
    }
}

//precondición: el string debe estar formado solo por numeros
int DevolverNumero (ListaDeStrings L) {
    int largo = strlar(L->str);
    int resu = 0, pot=1, n;

    for(int i = largo-1; i>=0; i--){
        switch(L->str[i]){
            case '0': n=0;
                break;
            case '1': n=1;
                break;
            case '2': n=2;
                break;
            case '3': n=3;
                break;
            case '4': n=4;
                break;
            case '5': n=5;
                break;
            case '6': n=6;
                break;
            case '7': n=7;
                break;
            case '8': n=8;
                break;
            case '9': n=9;
                break;
        }
        
        resu = n * pot + resu;
        pot*=10;
    }
    return resu;
}


