#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "libs/input.h"
#define MAX 999



int main()
{
    int cant, bandera, opcion, id, submenu,r,acumulador;
    float promedio,total;
    eEmployee emp[MAX];

    do{
        printf("1) Dar de alta una empleado\n");
        printf("2) Dar de baja una empleado por id\n");
        printf("3) Modificar un empleado\n");
        printf("4) Ordenar por apellido y mostrar\n");
        printf("5) Ordenar por sector y mostrar\n");
        printf("6) Busqueda por ID\n");
        printf("7) Promedio, total de todos los salarios y cuantos empleados superan el salario promedio\n");
        printf("9) Salir del programa\n");
        scanf("%d",&opcion);
            switch (opcion){
                case 1:
                    system("cls");
                    do{
                        fflush(stdin);
                        r=getInt(&cant,"Ingrese empleados a dar de alta: ","---(entre 1 y 999 digitos)---.",0,1000);
                        if(r==0){
                            system("cls");
                            printf("\tLos empleados a dar de alta son: %d\n\n\n",cant);
                            acumulador=acumulador+cant;
                        }else{
                            printf("Error.\n");
                        }
                    }while(r!=0);
                    initEmployees(emp, cant);
                    addEmployees(emp, cant);
                break;
                case 2:
                    system("cls");
                    if(emp[0].isEmpty==0){
                        system("cls");
                        printf("Que empleado desea borrar? (por id)\n");
                        scanf("%d",&id);
                        removeEmployee(emp, id);
                        printf("Presione cualquier tecla para continuar\n");
                        fflush(stdin);
                        getchar();
                        fflush(stdin);
                        system("cls");
                    }else{
                        system("cls");
                        printf("Primero agregue un empleado.\n");
                        printf("Presione cualquier tecla para continuar\n");
                        fflush(stdin);
                        getchar();
                        fflush(stdin);
                        system("cls");
                    }
                break;
                case 3:
                    system("cls");
                    if(emp[0].isEmpty==0){
                        r=getInt(&id,"Ingrese el ID del empleado que desea modificar","(Desde 1 hasta 1000)",0,MAX);
                        if(r==0){
                            do{
                            findEmployeeById(emp,id);
                            printf("\n--1) Modificar apellido\n");
                            printf("--2) Modificar nombre\n");
                            printf("--3) Modificar salario\n");
                            printf("--4) Modificar sector\n");
                            printf("--5) Cambiar de id\n");
                            printf("--0) Salir de la modificacion\n");
                            r=getInt(&submenu,"Ingrese la opcion","---Entre 1 y 5---",0,MAX);
                                if(r==0){
                                    switch(submenu){
                                    case 1:
                                        system("cls");
                                        modificarApellido(emp,id);
                                    break;
                                    case 2:
                                        system("cls");
                                        modificarNombre(emp,id);
                                    break;
                                    case 3:
                                        system("cls");
                                        modificarSalario(emp,id);
                                    break;
                                    case 4:
                                        system("cls");
                                        modificarSector(emp,id);
                                    break;
                                    case 5:
                                        system("cls");
                                        getInt(&id,"Ingrese el ID del empleado","(Desde 1 hasta 1000)",0,MAX);
                                    break;
                                    default:
                                        submenu=7;
                                        r=1;
                                    }
                                }
                            }while(submenu!=7);
                        }
                        printf("Presione cualquier tecla para continuar\n");
                        fflush(stdin);
                        getchar();
                        fflush(stdin);
                        system("cls");
                    }else{
                        system("cls");
                        printf("Primero agregue un id.\n");
                        printf("Presione cualquier tecla para continuar\n");
                        fflush(stdin);
                        getchar();
                        fflush(stdin);
                        system("cls");
                    }
                break;
                case 4:
                    system("cls");
                    if(emp[0].isEmpty==0){
                    sortEmployees(emp, cant);
                    printEmployees(emp, cant);
                    printf("Presione cualquier tecla para continuar\n");
                    fflush(stdin);
                    getchar();
                    fflush(stdin);
                    }else{
                        printf("Primero agregue un empleado.\n");
                        printf("Presione cualquier tecla para continuar\n");
                        fflush(stdin);
                        getchar();
                        fflush(stdin);
                        system("cls");
                    }
                case 5:
                    system("cls");
                    if(emp[0].isEmpty==0){
                    sortEmployeesBySector(emp, cant);
                    printEmployees(emp, cant);
                    printf("Presione cualquier tecla para continuar\n");
                    fflush(stdin);
                    getchar();
                    fflush(stdin);
                    }else{
                        printf("Primero agregue un empleado.\n");
                        printf("Presione cualquier tecla para continuar\n");
                        fflush(stdin);
                        getchar();
                        fflush(stdin);
                        system("cls");
                    }
                    break;
                case 6:
                    system("cls");
                    if(emp[0].isEmpty==0){
                        r=getInt(&id,"Ingrese el ID del empleado que desea buscar","(Desde 1 hasta 1000)",0,MAX);
                            if(r==0){
                                system("cls");
                                findEmployeeById(emp, id);
                                printf("Presione cualquier tecla para continuar\n");
                                fflush(stdin);
                                getchar();
                                fflush(stdin);
                                system("cls");
                            }
                        }else{
                            system("cls");
                            printf("Primero agregue un empleado.\n");
                            printf("Presione cualquier tecla para continuar\n");
                            fflush(stdin);
                            getchar();
                            fflush(stdin);
                            system("cls");
                        }
                break;
                case 7:
                   system("cls");
                    if(emp[0].isEmpty==0){
                    acumulador=empQuantity(emp,cant);
                    promedio=promedioSalarioTotal(emp, acumulador);
                    total=salarioTotal(emp, acumulador);
                    printf("El salario total es: %.2f, y el promedio de salario es: %.2f de %d de empleados.\n",total,promedio,acumulador);
                    }else{
                        printf("Primero agregue un empleado.\n");
                        printf("Presione cualquier tecla para continuar\n");
                        fflush(stdin);
                        getchar();
                        fflush(stdin);
                        system("cls");
                    }
                break;
                case 8:
                default:
                    system("cls");
                    printf("Programa terminado");
                    bandera=0;
                break;

            }

    }while(bandera!=0);

}
