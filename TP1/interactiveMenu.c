#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

char menuInteractivo(int opcion, int num1, int num2, char seguir, int resultadoSuma, int resultadoResta, int resultadoMulti, float resultadoDiv, int resultadoFactorizacion1, int resultadoFactorizacion2){
    switch(opcion){
        case 1:
            printf("\n\n\n*-*-*-*-*Reingrese el primer numero*-*-*-*-*\n\n\n");
            seguir = 'a';
            break;
        case 2:
            printf("\n\n\n*-*-*-*-*Reingrese el segundo numero*-*-*-*-*\n\n\n");
            seguir = 'b';
            break;
        case 3:
            seguir='c';
            break;
        case 4:
            printf("\n\n\n*-*-*-*-*\tLa suma de: %d + %d es de: %d\t*-*-*-*-*\n\n\n",num1,num2,resultadoSuma);
            printf("\n\n\n*-*-*-*-*\tLa resta de: %d - %d es de: %d\t*-*-*-*-*\n\n\n",num1,num2,resultadoResta);
            printf("\n\n\n*-*-*-*-*\tLa multiplicacion de %d y %d es de: %d\t*-*-*-*-*\n\n\n",num1, num2, resultadoMulti);
            if(num1==0 || num2==0){
                printf("\n\n\n *****Ningun numero es divisible por 0 ni 0 es divisible, porfavor ingrese opcion #1 o #2 y cambie el 0 *****\n\n\n");
            }else{
                if(num1<num2){
                    printf("\n***El segundo numero es mayor que el primero y no se puede dividir. ***");
                    printf("\n***Pero intercambiando los lugares***\n");
                    printf("\n\n\n*-*-*-*-*\tLa division de %d y %d es de: %.2f\t*-*-*-*-*\n\n\n",num2, num1, resultadoDiv);
                }else{
                    printf("\n\n\n*-*-*-*-*La division de %d y %d es de: %.2f*-*-*-*-*\n\n\n",num1, num2, resultadoDiv);
                    }
                }
            if( resultadoFactorizacion1 > 0 && resultadoFactorizacion2 > 0){
                printf("\n\n\n*-*-*-*-*La factorizacion del numero %d es de: %d*-*-*-*-*\n\n\n",num1, resultadoFactorizacion1);
                printf("\n\n\n*-*-*-*-*La factorizacion del numero %d es de: %d*-*-*-*-*\n\n\n",num2, resultadoFactorizacion2);
            }
            break;
        case 5:
            seguir = 'n';
            break;
    }
    return seguir;
}
