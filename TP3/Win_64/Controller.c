#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "libs/input.h"
#include "parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
    int retorno;
    FILE* archivo;
    archivo= fopen(path,"r");
    if(archivo == NULL && pArrayListEmployee == NULL){
        retorno=-1;
    }else{
        ll_clear(pArrayListEmployee);
        retorno=parser_EmployeeFromText(archivo, pArrayListEmployee);
        fclose(archivo);
        retorno=1;
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
    int retorno;
    FILE* archivo;
    archivo= fopen(path,"rb");
    if(archivo == NULL && pArrayListEmployee == NULL){
        retorno=-1;
    }else{
        ll_clear(pArrayListEmployee);
        retorno= parser_EmployeeFromBinary(archivo, pArrayListEmployee);
        //      Problema de ordenamiento de binario a texto
        //      Abrir un .bin
        fclose(archivo);
        retorno=1;
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id){
    int idaux;
    char nombreaux[256];
    int horasTrabajadasaux;
    int sueldoaux;
    int retorno;
    if(pArrayListEmployee == NULL && *id == NULL){
        printf("Array vacio");
        retorno=-1;
    }else{
        getString(&nombreaux,"Ingrese el nombre","Nombre mal ingresado",0,256);
        getInt(&horasTrabajadasaux,"Ingrese las horas trabajadas","Horas mla ingresadas",0,12);
        getInt(&sueldoaux,"Ingrese el sueldo","sueldo mla ingresado",0,12);
        idaux= *id;
        id++;
        Employee* this= employee_newParametros(idaux,nombreaux,horasTrabajadasaux,sueldoaux);
        ll_add(pArrayListEmployee, this);
        *id=idaux;
        retorno=0;
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee){
    int retorno,id ,sueldoaux ,horasTrabajadasaux ,i ,op ,indice,r,error,m;
    char nombreaux[256];
    Employee* this;

    if(pArrayListEmployee == NULL){
        printf("Array vacio");
        retorno=-1;
    }else{
        m=getInt(&id,"Ingrese el id a modificar: ","Error",0,1000);
        if(m==-1){
            printf("\nIngreso mal el ID");
        }else{
            for(i=0;i<ll_len(pArrayListEmployee);i++){
                this=(Employee*)ll_get(pArrayListEmployee, i);
                if(this->id == id){
                    indice= i;
                    break;
                }
            }
        }

        do{
        printf("\n1_Modificar nombre");
        printf("\n2_Modificar horas trabajadas");
        printf("\n3_Modificar sueldo");
        error=getInt(&op,"\nIngrese que desea modificar: ","--Opcion invalida--",0,10);
        if(error==-1){
            printf("Error al ingresar la opcion para modificar");
            break;
        }else{
                switch(op){
                    case 1:
                        fflush(stdin);
                        r=getString(nombreaux,"Ingrese el nuevo nombre","Mal ingresado",0,256);
                        if(r==-1){
                            printf("\nError al modificar el nombre");
                        }else{
                            employee_setNombre(this,nombreaux);
                            printf("\nNombre modificado!");
                        }
                        break;
                    case 2:
                        r=getInt(&horasTrabajadasaux,"Ingrese las horas: ","Mal ingresado",0,12);
                        if(r==-1){
                            printf("\nError al modificar las horas");
                        }else{
                        employee_setHorasTrabajadas(this, horasTrabajadasaux);
                        printf("\nHoras modificas!");
                        }
                        break;
                    case 3:
                        r=getFloat(&sueldoaux,"Ingrese el sueldo nuevo: ","Mal ingresado",0,99999);
                        if(r==-1){
                            printf("\nError al modificar el sueldo");
                        }else{
                        employee_setSueldo(this, sueldoaux);
                        printf("\nSueldo modificado!");
                        }
                        break;
                    case 4:
                    default:
                        if(op>=4){
                            op=10;
                            retorno=1;
                        }
                        break;
                    }
                }
                }while(op!=10);

    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int#include "libs/input.h"

 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee){
    int id,i,op,seguido=-1,retorno;
    Employee* this;

    if(pArrayListEmployee == NULL){
        printf("Array vacio");
        retorno=-1;
    }else{
        getInt(&id,"Ingrese su opcion: ","",0,1);

        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this=(Employee*)ll_get(pArrayListEmployee,i);

            if(this->id == id){
                seguido=i;
                break;
            }
        }
        if(seguido != -1){
            getInt(&op,"\n1_Dar de baja al empleado\n2_Cancelar baja\nElija una opcion","Ingreso mal la opcion",1,2);
            if(op==1){
                ll_remove(pArrayListEmployee,seguido);
                retorno=0;
            }else{
                retorno=1;
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i,retorno,contador=0;
    Employee* this;

    if(pArrayListEmployee == NULL){
            printf("Array vacio");
            retorno=-1;
    }else{
        printf("\nID|\t||NOMBRE||\t\t|HS|\t\t||SUELDO||\n");
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= (Employee*)ll_get(pArrayListEmployee, i);
            employee_mostrarUno(this);
            contador++;
        }
        retorno= 0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 * \param
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee){
    int opcion,retorno;

    if(pArrayListEmployee == NULL){
                printf("Array vacio");
                retorno=-1;
            }else{
            do{
            getInt(&opcion,"\n1_Ordenar id\n2_Ordenar nombre\n3_Ordenar por sueldo\n4_Ordenar por horas\n5_Salir.","ERROR",0,9);
            if(opcion<5){
                switch(opcion){
                    case 1:
                        ll_sort(pArrayListEmployee,employee_compareId,1);
                        break;
                    case 2:
                        ll_sort(pArrayListEmployee,employee_compareName,1);
                        break;
                    case 3:
                        ll_sort(pArrayListEmployee,employee_compareSueldo,1);
                        break;
                    case 4:
                        ll_sort(pArrayListEmployee,employee_compareHorasTrabajadas,1);
                        break;
                    case 5:
                    default:
                        opcion=5;
                        break;
                }
                printf("\nOrdenado terminado.\n");
                retorno=0;
                }else{
                    printf("\nNo se pudo ordenar.\n");
                }
                }while(opcion!=5);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno;
    int i;
    FILE* archivo= fopen(path,"w");
    if(pArrayListEmployee == NULL && archivo == NULL){
        printf("Array vacio");
        retorno=-1;
    }else{
        Employee* this;
        fprintf(archivo,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= ll_get(pArrayListEmployee, i);
            fprintf(archivo,"%d,%s,%d,%d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        }
        fclose(archivo);
        retorno= 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno;
    int i;
    FILE* archivo= fopen(path,"wb");
     if(pArrayListEmployee == NULL && archivo){
        printf("Array vacio");
        retorno=-1;
    }else{
        Employee* this;
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= ll_get(pArrayListEmployee, i);
            fwrite(this, sizeof(Employee),1,archivo);
        }
        fclose(archivo);
        retorno= 0;
    }
    return retorno;
}

