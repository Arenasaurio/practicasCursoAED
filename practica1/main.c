#include <stdio.h>
#include "letras.h"
/*
Conversor de Texto
1.- Convertir texto a mayusculas
2.- Convertir texto a minusuculas
3.- Oracion con mayuscula inicial
4.- Mayuscula por cada palabra
5.- Alternar mayusculas y minusculas
Desarrollado por:
Arenas Sánchez César Eduardo
Domínguez Salas Francisco
Nava Avelar Dana María
Nava Polvo Jazmín
el 03-09-23
*/
int main(){
    char frase[100];
    int c = 0;

    printf("Dime algo que quieras modificar: ");
    fgets(frase, 100, stdin);

    while(c != 6){
        printf("*****************Menu*****************\n");
        printf("1.-Cadena a Mayusculas\n");
        printf("2.-Cadena a minusculas\n");
        printf("3.-Cadena con primera letra a Mayuscula\n");
        printf("4.-Cadena intercalada\n");
        printf("5.-Cadena con mayuscula en la primera letra de cada palabra\n");
        printf("6.-Salir\n");

        printf("Que deseas hacer con la cadena?: "); scanf("%d",&c);

        switch(c){
            case 1:
                cap(frase);
                printf("Esto fue lo que dijiste en mayusculas: \n%s\n", frase);
                break;
            case 2:
                lou(frase);
                printf("Esto fue lo que dijiste en minusuculas: \n%s\n", frase);
                break;
            case 3:
                capFst(frase);
                printf("Esto fue lo que dijiste con la primera letra mayuscula: \n%s\n", frase);
                break;
            case 4:
                capToCap(frase);
                printf("Esto fue lo que dijiste con una letra mayuscula intercalada con minusculas: \n%s\n", frase);
                break;
            case 5:
                wrdfstCap(frase);
                printf("Esto fue lo que dijiste con la primera letra mayuscula de cada palabra: \n%s\n", frase);
                break;
            case 6:
                printf("Hasta pronto!!\n");
                break;
        }
    }
    return 0;

}
