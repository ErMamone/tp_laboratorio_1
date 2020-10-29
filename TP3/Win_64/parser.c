#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "libs/input.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno;
    int cantidad;

    if(pFile == NULL && pArrayListEmployee == NULL){
        printf("Archivo vacio.");
        retorno=-1;
    }else{
        Employee* this;
        char id[999], nombre[999], horasTrabajadas[999], sueldo[999];
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        do{
            cantidad= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
            if (cantidad == 4){
                this=(Employee*)malloc(sizeof(Employee));
                this->id=atoi(id);
                strcpy(this->nombre, nombre);
                this->horasTrabajadas=atoi(horasTrabajadas);
                this->sueldo=atoi(sueldo);
                ll_add(pArrayListEmployee,this);
            }else{
                break;
            }
        }while(!feof(pFile));
        retorno=0;
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno;
    if(pFile == NULL && pArrayListEmployee == NULL){
        printf("Archivo vacio.");
        retorno=-1;
    }else{
        Employee* this;
        while(!feof(pFile)){
            this=(Employee*)malloc(sizeof(Employee));
            if(fread(this, sizeof(Employee),1,pFile)==1){
                ll_add(pArrayListEmployee,this);
            }else{
                break;
            }
        }
        retorno=0;
    }
    return retorno;
}
