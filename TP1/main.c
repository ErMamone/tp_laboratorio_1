#include <stdio.h>
#include <stdlib.h>
#include "interactiveMenu.h"

int main(){
    char seguir='s';
    int opcion=0;
    int num1=0;
    int num2=0;
    int resultadoSuma=0;
    int resultadoResta=0;
    int resultadoMulti=0;
    float resultadoDiv=0;
    int resultadoFactorizacion1=0;
    int resultadoFactorizacion2=0;

    printf("---Ingrese el primer numero---\n");
    scanf("%d",&num1);
    printf("---Ingrese el segundo numero---\n");
    scanf("%d",&num2);

     while(seguir=='s'){
        printf("\n***************************************************\n");
        printf("*****1--Reingresar el 1er Operando %d\n",num1);
        printf("*****2--Reingresar el 2do Operando %d\n",num2);
        printf("*****3--Calcular todas las operaciones\n");
        printf("*****4--Informar Resultados\n");
        printf("*****5--Salir\n");
        printf("***************************************************\n");

        scanf("%d",&opcion);

        seguir = menuInteractivo(opcion,num1,num2,seguir,resultadoSuma,resultadoResta,resultadoMulti,resultadoDiv,resultadoFactorizacion1,resultadoFactorizacion2);
        if (seguir == 'a'){
            scanf("%d",&num1);
            seguir = 's';
        }
        if (seguir == 'b'){
            scanf("%d",&num2);
            seguir = 's';
        }
        if (seguir == 'c'){
            printf("\n\n\n*-*-*-*-*Se realizan los calculos*-*-*-*-*\n\n\n");
            resultadoSuma= suma(num1, num2);
            resultadoResta= resta(num1, num2);
            resultadoMulti= multiplicar(num1, num2);
            if( num1>0 && num2>0){
                if(num2<num1){
                    resultadoDiv= dividido(num2, num1);
                }else{
                    resultadoDiv= dividido(num1, num2);
                }
            }else{
                printf("\n\n\n *****Ningun numero es divisible por 0 ni 0 es divisible, porfavor ingrese opcion #1 o #2 y cambie el 0 *****\n\n\n");
            }
            if(num1<0 || num2<0){
                printf("Porfavor ingrese la opcion #1 o #2 para reingresar los numeros, no es posible factorizar en 0 o menor");
            }else{
                if(num1<=0){
                    printf("\n\n\n ***** El numero 1 no es factorizable debido a que es 0 o menor. *****\n\n\n");
                    resultadoFactorizacion1= 1;
                }else{
                resultadoFactorizacion1= factorizar(num1);
                }
                if(num2<=0){
                    printf("\n\n\n ***** El numero 2 no es factorizable debido a que es 0 o menor. *****\n\n\n");
                    resultadoFactorizacion2= 1;
                }else{
                    resultadoFactorizacion2= factorizar(num2);
                }
            }
            seguir = 's';
        }
    }

    return 0;
}



