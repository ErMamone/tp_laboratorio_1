#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

char menuInteractivo(int opcion, float num1, float num2, char seguir, float resultadoSuma, float resultadoResta, float resultadoMulti, float resultadoDiv, float resultadoFactorizacion1, float resultadoFactorizacion2){
    switch(opcion){
        case 1:
            printf("\n\n*-*-*-*-*Reingrese el primer numero*-*-*-*-*\n\n");
            seguir = 'a';
            break;
        case 2:
            printf("\n\n*-*-*-*-*Reingrese el segundo numero*-*-*-*-*\n\n");
            seguir = 'b';
            break;
        case 3:
            seguir='c';
            break;
        case 4:
            printf("\n\nLa suma de: %.2f + %.2f es de: %.2f\n",num1,num2,resultadoSuma);
            printf("\nLa resta de: %.2f - %.2f es de: %.2f\n",num1,num2,resultadoResta);
            printf("\nLa multiplicacion de %.2f y %.2f es de: %.2f\n",num1, num2, resultadoMulti);
            if(num1==0 || num2==0){
                printf("\n *****Ningun numero es divisible por 0 ni 0 es divisible*****\n\n");
            }else{
                printf("\nLa division de %.2f y %.2f es de: %.2f\n",num1, num2, resultadoDiv);
            }
            if( resultadoFactorizacion1 > 0 && resultadoFactorizacion2 > 0){
                printf("\nLa factorizacion del numero %.2f es de: %.2f\n",num1, resultadoFactorizacion1);
                printf("\nLa factorizacion del numero %.2f es de: %.2f\n",num2, resultadoFactorizacion2);
            }
            break;
        case 5:
            seguir = 'n';
            break;
    }
    return seguir;
}
