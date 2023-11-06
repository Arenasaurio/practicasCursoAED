/*Mejorar para que evalue expresiones con más de un digito
 25 300 + 2 * = 650*/
 //psdt:deje los comentarios para que vean lo pendejo que estoi ;)


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define GRANDOTOTE 100
long stack[GRANDOTOTE]; //para guardar los operandos
int top=-1; //la pila esta vacia

void push(int val)
{
    stack[++top]=val;
}
int pop()
{
    return stack[top--];
}
int main()
{
    char exp[GRANDOTOTE]; //guardar toda la expresion abc+*
    char *op;
    int n1,n2, res;
    printf("Escribe la expresion: ");//debe incluir un espacio al final debido a como se guardan los tokens
    fgets(exp, GRANDOTOTE, stdin);//necesario para guardar espacios
    printf("\n El resultado de %s es ",exp);
    char *token = strtok(exp, " ");//crea un token que basicamente es la parte de la cadena dividida por espacios
    while (token != NULL) {
        if (isdigit(token[0])) {
            int number = atoi(token);//atoi convierte la cadena o token en numero entero
            push(number);//envia mi numero a la pila
        } else if (strlen(token) == 1 && strchr("+-*/", token[0])) {//evalua si tiene el tamaño de una sola operacion y este dentro de los operadores
            n1=pop();
            n2=pop();//trae los valores de la cima
            if(token[0]=='+')//se usa token[0] ya que es el primer y unico caracter del token
                res=n2+n1;
            else if(token[0]=='-')
                res=n2-n1;
            else if(token[0]=='*')
                res=n2*n1;
            else if(token[0]=='/')
                res=n2/n1;

            //printf("res: %d\n", res);
            push(res);//envia mi respuesta a la cima
        } else {
            printf("\n");//es en caso de que no haya un espacio al final de la cadena
        }
        token = strtok(NULL, " ");//pide el siguiente token
    }
    //while(*op!='\0')/*tiene que verificar el final no si es nulo*/
    /*{
        if(*op=='+')
                {
                    n1 = pop();
                    n2 = pop();
                    res=n2+n1;
                }

            else if(*op=='-')
                {
                    n1 = pop();
                    n2 = pop();
                    res=n2-n1;
                }

            else if(*op=='*')
                {
                    n1 = pop();
                    n2 = pop();
                    res=n2*n1;
                }

            else if(*op=='/')
                {
                    n1 = pop();
                    n2 = pop();
                    res=n2/n1;
                }
            printf("%d %d resultado: %d\n", n1, n2, res);
            push(res);

        op++;}*/
        /*if(*op==' '&&*op!='\0')
        {
            num = strtol(operando, &endptr, 10);
            printf("%d",num);
            push(num);
            memset(operando,'0', sizeof(operando));
            i=0;
        }
        else if(isdigit(*op))
        {
            operando[i]=*op;
            //printf("%c ", *op);realiza la conversion para la impresion mas bien no para manejar el dato
            //num=*op-48;conversion de chat a numero debido al codigo ASCII 0=48 y asi hasta llegar al 57
            //push(num);cada que encuentre numero lo agregamos a la pila
            printf("[%d]=%c", i, *op);
            i++;

        }*/
            //n1=pop();printf("1.%d ", n1);
            //n2=pop();printf("2.%d \n",n2);
            //33-4+5-=-1
            /*
            1.Primero tiene al 3 que envia al stack
            2.Envia al otro 3
            3.ya que exp[2] es operador entra en else donde saca primero al segundo 3(n1) y despues al primer 3(n2)
            4.entra al if para checar el operador y hace la operacion asi: n2<OPERADOR>n1
            5.envia el resultado al stack
            6.envia el cuatro al stack
            7.obtiene n1 y n2 y entra al if de suma: n2(0)+n1(4)=4
            8.envia el resultado al stack
            9.envia el 5 al stack
            10.saca n1 y n2 y entra en el if de resta: n2(4)-n1(5)=-1
            11.envia el resultado al stack
            12.sale del while ya que no queda mas que evaluar
            13.imprime la expresion y el pop del stack
            */
    printf("%d",pop());//muestra la cima que en realidad es el resultado final ;)

    return  0;
}
