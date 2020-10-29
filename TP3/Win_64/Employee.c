#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "libs/input.h"

/** \brief Agrega un nuevo espacio para un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \param malloc para designarle un espacio
 * \return Employee*
 *
 */
Employee* employee_new(){
    Employee* this;
    this=(Employee*)malloc(sizeof(Employee));
    return this;
}

/** \brief Agrega un nuevo espacio para un empleado con los parametros dados
 *
 * \param pArrayListEmployee LinkedList*
 * \param Uso de la funcion employee_new
 * \param If para validar que el valor no sea nulo
 * \return Employee*
 *
 */
Employee* employee_newParametros(int idaux, char* nombreaux, int horasTrabajadasaux, float sueldoaux){

    Employee* this=employee_new();

    if(this != NULL){
        this->id=idaux;

        strcpy(this->nombre,nombreaux);

        this->horasTrabajadas=horasTrabajadasaux;
        this->sueldo=sueldoaux;
    }
    return this;
}

/** \brief Muestra 1 empleado (para iteracion)
 *
 * \param If para validacion de que no este vacio
 * \param Muestra id - nombre - horas - sueldo
 * \return Nada, void
 *
 */
void employee_mostrarUno(Employee* this){
    if(this == NULL){
        printf("no se pudo mostrar");
    }else{
        printf("%4d\t%9s\t\t%4d\t\t%.2f\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
    }
}
/** \brief Setters and Getters (lista de empleados, id al cual se le asigna)
 *
 * \param int para retornar un valor
 * \param if para validar el vacio
 * \param this id = id aux
 * \return int
 *
 */
int employee_setId(Employee* this,int idaux){
    int retorno;
    if(this == NULL){
        retorno=-1;
    }
    else{
        this->id=idaux;
        retorno=0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* idaux){
    int retorno;
    if(this == NULL){
        retorno=-1;
    }
    else{
        *idaux=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombreaux){
    int retorno;
    if(this == NULL && nombreaux==NULL){
        retorno=-1;
    }
    else{
        strcpy(this->nombre,nombreaux);
        retorno=0;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombreaux){
    int retorno;
    if(this == NULL && nombreaux==NULL){
        retorno=-1;
    }
    else{
        strcpy(nombreaux,this->nombre);
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadasaux){
    int retorno;
    if(this == NULL && horasTrabajadasaux<0){
        retorno=-1;
    }
    else{
        this->horasTrabajadas=horasTrabajadasaux;
        retorno=0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadasaux){
    int retorno;
    if(this == NULL && horasTrabajadasaux<0){
        retorno=-1;
    }
    else{
        *horasTrabajadasaux=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,float sueldoaux){
    int retorno;
    if(this == NULL && sueldoaux<0){
        retorno=-1;
    }
    else{
        this->sueldo=sueldoaux;
        retorno=0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,float* sueldoaux){
    int retorno;
    if(this == NULL && sueldoaux<0){
        retorno=-1;
    }
    else{
        *sueldoaux=this->sueldo;
        retorno=0;
    }
    return retorno;
}
/** \brief Comparar entre 2 puntos (para ordenar)
 *
 * \param 2 employee para asignar los valores
 * \param se valida atravez de una comparacion entre los elementos
 * \return Employee*
 *
 */
int employee_compareName(void* emp1, void* emp2){
    Employee* empaux1=(Employee*)emp1;
    Employee* empaux2=(Employee*)emp2;
    return strcmpi(empaux1->nombre,empaux2->nombre);
}

int employee_compareId(void* emp1, void* emp2){
    int retorno;
    Employee* empaux1=(Employee*)emp1;
    Employee* empaux2=(Employee*)emp2;

    if(empaux1->id > empaux2->id){
        retorno=1;
    }else if(empaux1->id > empaux2->id){
        retorno=-1;
    }else{
        retorno=0;
    }
    return retorno;
}

int employee_compareHorasTrabajadas(void* emp1, void* emp2){
    int retorno;
    Employee* empaux1=(Employee*)emp1;
    Employee* empaux2=(Employee*)emp2;

    if(empaux1->horasTrabajadas > empaux2->horasTrabajadas){
        retorno=1;
    }else if(empaux1->horasTrabajadas < empaux2->horasTrabajadas){
        retorno=-1;
    }else{
        retorno=0;
    }
    return retorno;
}

int employee_compareSueldo(void* emp1, void* emp2){
    int retorno;
    Employee* empaux1=(Employee*)emp1;
    Employee* empaux2=(Employee*)emp2;

    if(empaux1->sueldo > empaux2->sueldo){
        retorno=1;
    }else if(empaux1->sueldo < empaux2->sueldo){
        retorno=-1;
    }else{
        retorno=0;
    }
    return retorno;
}
