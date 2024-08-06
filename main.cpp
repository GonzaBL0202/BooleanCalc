#include "parsing.h"

int main () {

    ListaDeExpresiones le;
    TipoComando tc;
    ListaDeStrings ls, aux;
    string s;

    printf("\t\t\tEVALUADOR DE EXPRESIONES BOOLEANAS\n\n");
    
    CrearListaExpresion(le);

    do{
        CrearListaStr(ls);
        printf("\nIngrese comando: ");
        CargarComando(s);
        CargarListaStrings(ls,s);
        tc=esComando(ls);

        
        //El comando puede venir vacío
        if (ls!=NULL)
            aux = ls->sig;

        switch(tc){
            case VACIO :
                printf("\nEl comando ingresado no puede estar vacio\n");
                break;
            case ATOMIC :
                if(Largo(ls)==2){
                    if(esBoolean(aux)){
                        EjecutarAtomic(aux,le);
                        printf("\nResultado:\tExpresion %d: ", LargoListaExp(le));
                        if (streq(aux->str, "true"))
                            printf("true\n");
                        else
                            printf("false\n");
                    } else
                        printf("\nLo ingresado luego del 'atomic' no es un valor boolean (true/false) \n");
                }
                else
                    printf("\nNo se ingreso la cantidad necesaria de palabras para ejecutar el comando. Ej: 'atomic true' \n");
                break;
            
            case SHOW : 
                if(Largo(ls)==2){
                    if(SoloNumeros(aux->str)){
                        int numero=DevolverNumero(aux);
                        if(PerteneceALista(numero,le)){  
                            printf("\nResultado:\tExpresion %d: ", numero);
                            EjecutarShow(le, numero);
                            printf("\n");
                        } else
                            printf("\nEl numero ingresado no pertenece a la lista de expresiones\n"); 
                    }else
                        printf("\nNO se ingreso un numero para mostrar una expresion\n");
                }
                else
                    printf("\nNo se ingreso la cantidad necesaria de palabras para ejecutar el comando\n");
                break;
            
            case EVALUATE: 
                if(Largo(ls)==2){
                    if(SoloNumeros(aux->str)){
                        int numero=DevolverNumero(aux);
                        if(PerteneceALista(numero,le)){
                            printf("\nResultado:");
                            EjecutarEvaluate(le, numero);
                        } else
                            printf("\nEl numero ingresado no pertenece a la lista de expresiones\n");
                    }else
                        printf("\nNO se ingreso un numero para evaluar una expresion\n");
                } else    
                    printf("\nNo se ingreso la cantidad necesaria de palabras para ejecutar el comando\n");
                break;
            

            case COMPOUND: 
                if(Largo(ls)==3){
                    if (esOperador(aux)) {
                        if(streq(aux->str, "not")){
                            if(SoloNumeros(aux->sig->str)){
                                int numero=DevolverNumero(aux->sig);
                                if(PerteneceALista(numero,le)){
                                    EjecutarCompoundNOT(aux, le, numero);
                                    printf("\nResultado:\tExpresion %d: ", LargoListaExp(le));
                                    Expresion Exaux = EncontrarExpresion(LargoListaExp(le),le);
                                    MostrarArbolEnOrden(Exaux.ar);
                                    printf("\n");
                                } else
                                    printf("\nEl numero ingresado no pertenece a la lista de expresiones\n");
                            }else
                                printf("\nNO se ingreso un numero como parametro para el comando compound\n");
                        }else
                            printf("\nEl operador a ingresar debe ser 'not' para el compound con una expresion\n");
                    } else 
                        printf("\nNO se ingresó un operador para el compound de una expresion\n");
                } 
                
                
                else if (Largo(ls)==4) {
                    if(SoloNumeros(aux->str)) {
                        int numero1=DevolverNumero(aux);
                        if(PerteneceALista(numero1,le))
                            if (esOperador(aux->sig)){
                                if(streq(aux->sig->str, "and") || streq(aux->sig->str, "or")){
                                    if(SoloNumeros(aux->sig->sig->str)) {
                                        int numero2=DevolverNumero(aux->sig->sig);
                                            if(PerteneceALista(numero2,le)){
                                                EjecutarCompound(aux->sig, le, numero1, numero2);
                                                printf("\nResultado:\tExpresion %d: ", LargoListaExp(le));
                                                Expresion Exaux = EncontrarExpresion(LargoListaExp(le),le);
                                                MostrarArbolEnOrden(Exaux.ar);
                                            } else
                                                printf("\nEl numero ingresado no pertenece a la lista de expresiones\n");
                                    }else
                                        printf("\nNO se ingreso un numero como primer parametro para el comando compound\n");
                                }else
                                    printf("\nEl operador a ingresar debe ser 'and' o 'or' para el compound con una expresion\n");
                            }else
                                printf("\nNO se ingresó un operador para el compound de una expresion\n");
                        else 
                            printf("\nEl numero ingresado no pertenece a la lista de expresiones\n");
                    }else
                        printf("\nNO se ingreso un numero como primer parametro para el comando compound\n");

                } else
                    printf("\nNo se ingreso la cantidad necesaria de palabras para ejecutar el comando\n");
                break;

            case SAVE: 
                    if(Largo(ls)==3)
                        if(SoloNumeros(aux->str)){
                            int numero=DevolverNumero(aux);
                                if(PerteneceALista(numero, le))
                                    if(SoloLetras(aux->sig->str))
                                        if(EsArchivo(aux->sig->str)){
                                            string NomArch;
                                            StrCrear(NomArch);
                                            strcopDinamico(NomArch, aux->sig->str);
                                            if(!Existe(NomArch)) {
                                                EjecutarSave(le, numero, NomArch);
                                                printf("\nResultado:\tExpresion %d respaldada correctamente en ",numero);
                                                print(NomArch);
                                                printf("\n");
                                            }
                                            else{
                                                char sobreescribir;
                                                printf("\nUn archivo con ese nombre ya existe\n");
                                                printf("\n¿Desea sobreescribirlo?(s: si, n: no)\n");
                                                sobreescribir=getchar();
                                                int c;
                                                while ((c = getchar()) != '\n' && c != EOF);
                                                switch(sobreescribir){
                                                    case 's': 
                                                            EjecutarSave(le, numero, NomArch);
                                                            printf("\nResultado:\tExpresion %d respaldada correctamente en ",numero);
                                                            print(NomArch);
                                                            printf("\n");
                                                            break;
                                                    case 'n': break;

                                                    default:printf("\nLa letra ingresada no representa ninguna opcion\n");
                                                            break;
                                                }
                                            }
                                            }
                                        else
                                            printf("\nEl nombre del archivo dene terminar con '.dat'\n");
                                    else
                                        printf("\nEl nombre del archivo debe estar compuesto solo por letras\n");
                                else
                                    printf("\nEl numero ingresado no pertece a la lista de expresiones\n");
                        }else
                            printf("\nNo se ingreso un numero para ejecutar el comando save\n");
                    else
                        printf("\nNo se ingresador los parametros necesario para ejecutar save\n");
                break;
                case LOAD:
                    if(Largo(ls)==2)
                        if(SoloLetras(aux->str))
                            if(EsArchivo(aux->str))
                                if(Existe(aux->str)){
                                    string NomArch;
                                    StrCrear(NomArch);
                                    strcopDinamico(NomArch, aux->str);
                                    EjecutarLoad(le,NomArch);
                                    printf("\nResultado:\t Expresion %d: ", LargoListaExp(le));
                                    Expresion Exaux = EncontrarExpresion(LargoListaExp(le),le);
                                    MostrarArbolEnOrden(Exaux.ar);
                                    printf("\n");
                                }else   
                                    printf("\nEl archivo no existe\n");
                            else
                                printf("\nEl nombre ingresado no corresponde al de un archivo\n");
                        else
                            printf("\nEl nombre del archivo solo debe contener letras\n");
                    else
                            printf("\nNo se ha ingresado los parametros necesario para ejecutar save\n");
                break;

            case EXIT:
                if(Largo(ls)==1){
                    EjecutarExit(le, ls);
                    printf("\nEjecucion finalizada...\n");
                } else
                    printf("Se ingresaron parametros de mas para el comando EXIT\n");
                break;
            default: 
                printf("\nLa palabra ingresada no representa ningun comando disponible\n");
                break;
        }
    }while(tc!=EXIT);
}