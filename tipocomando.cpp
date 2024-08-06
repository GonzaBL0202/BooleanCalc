#include "tipocomando.h"


void mostrarComando (TipoComando com){
    switch(com){

        case ATOMIC: printf("atomic");
                    break;
        case COMPOUND: printf("compound");
                    break;
        case EVALUATE: printf("EVALUATE");
                    break;
        case SHOW: printf("SHOW");
                    break;
        case SAVE: printf("SAVE");
                    break;
            
        case LOAD: printf("LOAD");
                    break;
        case EXIT: printf("exit");
                    break;

        default: printf("Comando no reconocido"); break;         
    }
}