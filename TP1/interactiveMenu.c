#include <stdio.h>
#include <stdlib.h>
#include "../Bibliotecas/funciones.h"

char menuInteractivo(int opcion, int num1, int num2, char seguir){
    switch(opcion){
        case 1:
            printf("\n\n\n*-*-*-*-*\tLa suma de: %d + %d es de: %d\t*-*-*-*-*\n\n\n",num1,num2,suma(num1, num2));
            break;
        case 2:
            printf("\n\n\n*-*-*-*-*\tLa resta de: %d - %d es de: %d\t*-*-*-*-*\n\n\n",num1,num2,resta(num1, num2));
            break;
        case 3:
            printf("\n\n\n*-*-*-*-*\tLa multiplicacion de %d y %d es de: %d\t*-*-*-*-*\n\n\n",num1, num2, multiplicar(num1, num2));
            break;
        case 4:
            if(num1==0 || num2==0){
                printf("\n\n\n *****Ningun numero es divisible por 0 ni 0 es divisible, porfavor ingrese opcion #7 o #8 y cambie el 0 *****\n\n\n");
            }else{
                if(num1<num2){
                    printf("\n***El segundo numero es mayor que el primero y no se puede dividir. ***");
                    printf("\n***Pero intercambiando los lugares***\n");
                    printf("\n\n\n*-*-*-*-*\tLa division de %d y %d es de: %.2f\t*-*-*-*-*\n\n\n",num2, num1, dividido(num2, num1));
                }else{
                    printf("\n\n\n*-*-*-*-*La division de %d y %d es de: %.2f*-*-*-*-*\n\n\n",num1, num2, dividido(num1, num2));
                    }
                }
            break;
        case 5:
            if(num1==0 || num2==0){
                printf("Porfavor ingrese la opcion #7 y #8 como diferentes de 0");
            }else{
                printf("\n\n\n*-*-*-*-*La factorizacion del numero %d es de: %d*-*-*-*-*\n\n\n",num1, factorizar(num1));
                printf("\n\n\n*-*-*-*-*La factorizacion del numero %d es de: %d*-*-*-*-*\n\n\n",num2, factorizar(num2));
            }
            break;
        case 6:
            if(num1==0 || num2==0){
                printf("Porfavor ingrese la opcion #7 y #8 como diferentes de 0");
            }else{
                printf("\n\n\n*-*-*-*-*La suma de: %d + %d es de: %d*-*-*-*-*\n\n\n",num1,num2,suma(num1, num2));
                printf("\n\n\n*-*-*-*-*La resta de: %d - %d es de: %d*-*-*-*-*\n\n\n",num1,num2,resta(num1, num2));
                if(num1<num2){
                    printf("\n***El segundo numero es mayor que el primero y no se puede dividir***");
                    printf("\n***pero intercambiando los lugares el resultado es: ***\n");
                    printf("\n\n\n*-*-*-*-*La division de %d y %d es de: %.2f*-*-*-*-*\n\n\n",num2, num1, dividido(num2, num1));

                }else{
                    printf("\n\n\n*-*-*-*-*La division de %d y %d es de: %.2f*-*-*-*-*\n\n\n",num1, num2, dividido(num1, num2));
                }
                printf("\n\n\n*-*-*-*-*La multiplicacion de %d y %d es de: %d*-*-*-*-*\n\n\n",num1, num2, multiplicar(num1, num2));
                printf("\n\n\n*-*-*-*-*La factorizacion del numero %d es de: %d*-*-*-*-*\n\n\n",num1, factorizar(num1));
                printf("\n\n\n*-*-*-*-*La factorizacion del numero %d es de: %d*-*-*-*-*\n\n\n",num2, factorizar(num2));
                }
            break;
        case 7:
            printf("\n\n\n*-*-*-*-*Reingrese el primer numero*-*-*-*-*\n\n\n");
            seguir = 'a';
            break;
        case 8:
            printf("\n\n\n*-*-*-*-*Reingrese el segundo numero*-*-*-*-*\n\n\n");
            seguir = 'b';
            break;
        case 9:
            seguir = 'n';
            break;
    }
    return seguir;
}
