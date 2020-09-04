#include <stdio.h>
#include <stdlib.h>
#include "interactiveMenu.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int num1=0;
    int num2=0;
    printf("---Ingrese el primer numero---\n");
    scanf("%d",&num1);
    printf("---Ingrese el segundo numero---\n");
    scanf("%d",&num2);

     while(seguir=='s'){
        printf("\n***************************************************\n");
        printf("*****1--Calcular suma (%d + %d)\n",num1,num2);
        printf("*****2--Calcular resta (%d - %d)\n",num1,num2);
        printf("*****3--Calcular multiplicacion (%d * %d)\n",num1,num2);
        printf("*****4--Calcular division (%d / %d)\n",num1,num2);
        printf("*****5--Calcular el factorial (%d y %d!)\n",num1,num2);
        printf("*****6--Calcular todas las operaciones anteriores\n");
        printf("*****7--Reingresar el numero 1\n");
        printf("*****8--Reingresar el numero 2\n");
        printf("*****9--Salir\n");
        printf("***************************************************\n");

        scanf("%d",&opcion);

        seguir = menuInteractivo(opcion,num1,num2,seguir);
        if (seguir == 'a'){
            scanf("%d",&num1);
            seguir = 's';
        }
        if (seguir == 'b'){
            scanf("%d",&num2);
            seguir = 's';
        }
    }

    return 0;
}



