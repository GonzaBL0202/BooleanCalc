#include "StringDinamico.h"

void StrCrear (string &str){
 str= new char[1];
 str[0]='\0';
}

int strlar (string str){
int i=0, largo=0;
while(str[i]!='\0' && i<MAX-1){
   largo++;
   i++;
}
return(largo);
}

void print (string str){
int i=0;
while(str[i]!='\0' && i<MAX){
    printf("%c", str[i]);
    i++;
}
}
void print2 (string str, int n){
int i=0;
while(str[i]!='\0' && i<MAX && i<n){
    printf("%c", str[i]);
    i++;
}
}


void CargarComando (string &str){
StrCrear(str);
string aux=new char [MAX];
char c;
int i = 0;
fflush (stdin);
scanf ("%c", &c);
while (c != '\n' && i < MAX-1){
    aux[i] = c;
    i++;
    scanf ("%c", &c);
}
aux[i]= '\0';
strcopDinamico(str,aux);
StrDestruir(aux);
fflush(stdin);
}

boolean strmen(string str, string str2){
boolean menor;
int i=0, valor1=0,valor2=0;
while(str[i]!='\0'){
    valor1+= str[i];
    i++;
}
i=0;
while(str2[i]!='\0'){
    valor2+=str2[i];
    i++;
}

if(valor1<valor2)
    menor=TRUE;
else
    menor=FALSE;

return(menor);
}

boolean streq(string str, string str2){
    int i=0;
    boolean iguales=TRUE;
    if(strlar(str)!= strlar(str2))
        iguales=FALSE;
    while(iguales && str[i]!='\0'){
            if(str[i]!=str2[i])
                iguales=FALSE;
            else
                i++;
    }
    return(iguales);
}

void strcopDinamico (string &str, string str2){
int cant=strlar(str2);
int i=0;
StrDestruir(str);
str= new char[cant];
while(str2[i]!='\0'){
    str[i]=str2[i];
    i++;
}
str[i]='\0';
}


void strconDinamico(string &str, string str2){
string aux;
StrCrear(aux);
int largo= strlar(str) + strlar(str2) + 1;
strcopDinamico(aux, str);
StrDestruir(str);
str= new char [largo];
int i=0;
int j=0;
while(aux[j]!='\0' && i<MAX-1){
    str[i]=aux[j];
    i++;
    j++;
}
j=0;
while(str2[j]!='\0' && i<MAX-1){
    str[i]=str2[j];
    i++;
    j++;
}
str[i]='\0';
StrDestruir(aux);
}

void strswapDinamico(string &str, string &str2){
string aux;
aux= str;
str=str2;
str2=aux;
}


void StrDestruir (string &str){
    delete[] str;
    str=NULL;
}

void Bajar_String (string s, FILE * f) /* M�dulo String */
{
 int i=0;
 while (s[i] != '\0')
 {
 fwrite (&s[i], sizeof(char), 1, f);
 i++;
 }
 // escribo el '\0'
 fwrite (&s[i], sizeof(char), 1, f);
}

void Levantar_String (string &s, FILE * f) /* M�dulo String */
{
 int i=0;
 string aux;
 aux = new char[MAX];
 fread (&aux[i], sizeof(char), 1, f);
 while (!feof(f) && (aux[i] != '\0'))
 {
 i++;
 fread (&aux[i], sizeof(char), 1, f);
 }
 if (feof(f))
 aux[i] = '\0';
 strcopDinamico (s, aux);
 delete [] aux;
}

boolean Existe (string nom){
    FILE*f;
    f=fopen(nom,"rb");
    boolean existe=TRUE;
    if(f==NULL)
        existe=FALSE;
    else
        fclose(f);
    return(existe);
}

boolean SoloLetras (string str){
    int i=0;
    boolean letras=TRUE;
    while(str[i]!= '\0' && letras){
        if( ( str[i]>='A' && str[i]<='Z' ) || ( str[i]>='a' && str[i]<='z') || ( str[i] == '.' ))
                i++;
        else
            letras=FALSE;
    }
    return letras;
};

boolean SoloNumeros (string str) {
    int i=0;
    boolean num=TRUE;
    while(str[i]!= '\0' && num){
        if( str[i]>='0' && str[i]<='9' )
                i++;
        else
            num=FALSE;
    }
    return num;
}

// Precondicion: el string solo tiene letras y el punto
boolean EsArchivo (string str){
    int i=0;
    boolean archivo=FALSE;
    while (str[i]!='\0' && str[i]!='.') {
        i++;
    }
    if(str[i+1]=='d' && str[i+2]=='a' && str[i+3]=='t' && str[i+4]=='\0')
        archivo=TRUE;

    return archivo;
};