#include <stdio.h>
#include <stdlib.h>
#include "interactiveMenu.h"

int main(){
    char seguir='s';
    int opcion=0;
    float num1=0;
    float num2=0;
    float resultadoSuma=0;
    float resultadoResta=0;
    float resultadoMulti=0;
    float resultadoDiv=0;
    int resultadoFactorizacion1=0;
    int resultadoFactorizacion2=0;

    printf("Ingrese el primer numero\n");
    scanf("%f",&num1);
    printf("Ingrese el segundo numero\n");
    scanf("%f",&num2);

     while(seguir=='s'){
        printf("\n(1)Reingresar el 1er numero %.2f\n",num1);
        printf("(2)Reingresar el 2do numero %.2f\n",num2);
        printf("(3)Calcular todas las operaciones\n");
        printf("(4)Informar Resultados\n");
        printf("(5)Salir\n\n");

        printf("Elija una opcion: \n");
        scanf("%d",&opcion);

        seguir = menuInteractivo(opcion,num1,num2,seguir,resultadoSuma,resultadoResta,resultadoMulti,resultadoDiv,resultadoFactorizacion1,resultadoFactorizacion2);
        if (seguir == 'a'){
            scanf("%f",&num1);
            seguir = 's';
        }
        if (seguir == 'b'){
            scanf("%f",&num2);
            seguir = 's';
        }
        if (seguir == 'c'){
            printf("\n*Se realizan los calculos*\n\n");
            resultadoSuma= suma(num1, num2);
            resultadoResta= resta(num1, num2);
            resultadoMulti= multiplicar(num1, num2);
            if( num1==0 && num2==0){
                printf("\n*****Ningun numero es divisible por 0 ni 0 es divisible*****\n");
            }else{
                resultadoDiv= dividido(num1, num2);
            }
            if(num1<0 && num2<0){
                printf("*****Porfavor ingrese la opcion #1 o #2 para reingresar los numeros, no es posible factorizar en 0 o con numeros negativos \n");
            }else{
                if(num1<=0){
                    printf("\n El numero 1 no es factorizable debido a que es 0 o negativo.\n");
                    resultadoFactorizacion1= 1;
                }else{
                resultadoFactorizacion1= factorizar(num1);
                }
                if(num2<=0){
                    printf("\n El numero 2 no es factorizable debido a que es 0 o negativo.\n");
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



