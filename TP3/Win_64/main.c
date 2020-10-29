#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"

//libs= librerias UTN

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.dat (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int opcion = 0, id=999, op,r,seguridad;
    LinkedList* listaEmpleados = ll_newLinkedList();
        printf("\nIngrese la opcion: \n");
        printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
        printf("\n2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).");
        printf("\n3. Alta de empleado");
        printf("\n4. Modificar datos de empleado");
        printf("\n5. Baja de empleado");
        printf("\n6. Listar empleados");
        printf("\n7. Ordenar empleados");
        printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
        printf("\n9. Guardar los datos de los empleados en el archivo data.dat (modo binario).");
        printf("\n10. Salir");
        seguridad=0;
        do{
            r=getInt(&op,"\nIngrese su opcion del menu","--Opcion mal ingresada o fuera de rango--",0,15);
            if(r==-1){
                printf("\nEl programa se cerrara");
                break;
            }else{
                switch(op)
                {
                    case 1:
                        if(seguridad==0){
                            if(controller_loadFromText("data.csv",listaEmpleados) == 1){
                                seguridad=1;
                                printf("Carga de archivo de texto con exito!");
                            }else{
                                printf("La carga no fue exitosa.");
                                op=10;
                            }
                        }else{
                            printf("Ya se abrio en modo binario o texto!");
                        }
                        break;
                    case 2:
                        if(seguridad==0){
                            if(controller_loadFromBinary("data.dat",listaEmpleados) == 1){
                                printf("Carga de archivo binario con exito!");
                            }else{
                                printf("La carga no fue exitosa.");
                                op=10;
                            }
                        }else{
                            printf("Ya se abrio en modo binario o texto!");
                        }
                        break;
                    case 3:
                        controller_addEmployee(listaEmpleados,id);
                        break;
                    case 4:
                        if(!ll_isEmpty(listaEmpleados)){
                                opcion=controller_editEmployee(listaEmpleados);
                            if(opcion==1){
                                    printf("\nEmpleado modificado correctamente\n");
                                }else{
                                    printf("\nError. El empleado no existe o no se pudo modificar\n");
                            }
                        }
                        break;
                    case 5:
                        if(!ll_isEmpty(listaEmpleados)){
                            opcion=controller_removeEmployee(listaEmpleados);
                        if(opcion==0){
                                printf("\nEmpleado dado de baja\n");
                            }else if(opcion==1){
                                printf("\nNo se dio de baja\n");
                            }else{
                                printf("\nError. El empleado no existe\n");
                        }
                    }
                    break;
                    case 6:
                        controller_ListEmployee(listaEmpleados);
                        break;
                    case 7:
                        controller_sortEmployee(listaEmpleados);
                        break;
                    case 8:
                        if(!ll_isEmpty(listaEmpleados)){
                            if(controller_saveAsText("data.csv", listaEmpleados)==0){
                                printf("\n\n--Datos guardados en %s (en modo texto)--\n\n","data.csv");
                            }else{
                                printf("\nError. No se pudieron guardar los datos en %s","data.csv");
                            }
                        }
                        break;
                    case 9:
                        if(!ll_isEmpty(listaEmpleados)){
                            if(controller_saveAsBinary("data.dat", listaEmpleados)==0){
                                printf("\nDatos guardados en %s (en binario)\n","data.dat");
                            }else{
                                printf("\nError. No se pudieron guardar los datos en %s","data.dat");
                            }
                        }
                        break;
                    case 10:
                        printf("Salio del programa.");
                        ll_clear(listaEmpleados);
                        ll_deleteLinkedList(listaEmpleados);
                        op=10;
                        break;
                    default:
                        printf("Ingreso una opcion incorrecta, intente de nuevo");
                        break;
                    }
                }
            }while(op != 10);
    return 0;
}
