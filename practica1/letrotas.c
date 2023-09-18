//IMPLEMENTACION
#include <ctype.h>//para traer funciones de mayusculas y minusculas
#include <string.h>//trae operaciones relacionadas con cadenas de cualquier tipo
#include "letras.h"//nuestra biblioteca que funciona de fachada



void cap(char *str) {
    while(*str){//mientras *str sea un valor valido ejecutara
        *str = toupper(*str);//toupper es la de mayusculas
        str++;//aumenta el indice
    }
}

void lou(char *str) {
    while(*str){
        *str = tolower(*str);//tolower es la funcion de minusculas
        str++;
    }
}

void capFst(char *str) {
    int inicio = 1;//se inicia un contador en 1 simbolizando que la primera letra va a ser mayuscula
    while(*str){
        if(inicio == 1){
            *str = toupper(*str);
            inicio = 0;//al pasar la primera iteracion se vuleve 0
        }
        else{
            *str = tolower(*str);
        }
        str++;
    }
}

void capToCap(char *str) {
    int mayus = 1;//Se deja un valor que nos indicara cuando va a ser mayuscula
    while(*str) {
        if(mayus==1){
            *str = toupper(*str);
            mayus=0;//cambia a 0 cuando es 1 obviamente despues de cambiar a mayuscula
        }
        else if(mayus == 0){
            *str = tolower(*str);
            mayus=1;//cambia igualmente a 0
        }
    str++;
    }
}

void wrdfstCap(char *str) {
    int length = strlen(str);//se determina el largo de la cadena
    int nextLet = 1;//indicador de cuando hay un espacio
    for(int i = 0; i < length; i++){
        if (isspace(str[i])) {//se determina si hay espacio
            nextLet = 1;//se afirma que se encotro un espacio
        }
        else if (nextLet){//se comprueba si el nextlet afirma que hubo espacio
            str[i] = toupper(str[i]);
            nextLet = 0;
        }
        else {
            str[i] = tolower(str[i]);//en caso de que no haya ni un espacio ni nexLet este en 1 se ponen minusculas
        }
    }
}
