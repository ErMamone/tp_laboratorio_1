#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "libs/input.h"


void initEmployees (eEmployee emp[], int MAX){
    int i;
    for(i=0; i<MAX; i++){
        emp[i].isEmpty=1;
    }
}

int freeEmployee (eEmployee emp[], int MAX){
    int i,acumular;
    for(i=0; i<MAX; i++){
        if(emp[i].isEmpty==0){
            acumular++;
        }
    }
    return acumular;
}


int empQuantity(eEmployee emp[], int cant){
    int cantEmpleados=0;
    int i;

    for(i=0; i<cant; i++)
    {
        if(emp[i].isEmpty==0){
            cantEmpleados++;
        }
    }
    return cantEmpleados;
}


void addEmployees(eEmployee emp[], int cant){
    int i, r;
    for(i=0;i<cant;i++){
        if(emp[i].isEmpty == 1){
            r=1;
            do{
            fflush(stdin);
            r=getString(emp[i].apellido,"Ingrese el Apellido: ","---(No mas de 50 y mas de 1 letra)---.",1,50);
                if(r==0){
                printf("El Apellido ingresado es: %s\n\n",emp[i].apellido);
            }else{
                printf("Error.\n");
            }
            }while(r!=0);

            r=1;
            do{
            fflush(stdin);
            r=getString(emp[i].nombre,"Ingrese el Nombre: ","---(No mas de 50 y mas de 1 letra)---.",1,50);
                if(r==0){
                printf("El Nombre ingresado es: %s\n\n",emp[i].nombre);
            }else{
                printf("Error.\n");
            }
            }while(r!=0);

            r=1;
            do{
            fflush(stdin);
            r=getFloat(&emp[i].salario,"Ingrese el salario: ","---(entre 0 y 6 digitos)---.",1,999999);
            if(r==0){
                    printf("El salario ingresado es: $%.2f\n\n",emp[i].salario);
                }else{
                    printf("Error.\n");
                }
            }while(r!=0);

            r=1;
            do{
            fflush(stdin);
            r=getInt(&emp[i].sector,"Ingrese el sector: ","---(entre 0 y 6 digitos)---.",0,10);
            if(r==0){
                    printf("El sector ingresado es: %d\n\n",emp[i].sector);
                }else{
                    printf("Error.\n");
                }
            }while(r!=0);

            emp[i].id=i+1;
            system("cls");

            printf("El id de: %s %s es: %d\n\n",emp[i].apellido,emp[i].nombre,emp[i].id);

            emp[i].isEmpty=0;

            }
            else{
                break;
            }
        }
}

void removeEmployee(eEmployee emp[], int id){
    char z[10]={"[Vacio]"};
    int i;
    for(i=0;i<id;i++){
        if(emp[i].isEmpty == 0){
            emp[i].isEmpty=1;
            strcpy(z,emp[i].nombre);
            strcpy(z,emp[i].apellido);
            emp[i].salario=0;
            emp[i].sector=0;
            emp[i].id=0;
            }else{
                break;
            }
        }
}


void modificarApellido(eEmployee emp[], int id){
    int r, aux;
    r=1;
    aux=id-1;
    do{
        fflush(stdin);
        r=getString(emp[aux].apellido,"Ingrese el Apellido a modificar: ","---(No mas de 50 y mas de 1 letra)---.",1,50);
        if(r==0){
            printf("El Apellido modificado es: %s\n\n",emp[aux].apellido);
        }else
        {
            printf("Error.\n");
        }
    }while(r!=0);
}

void modificarNombre(eEmployee emp[], int id){
    int r, aux;
    r=1;
    aux=id-1;
    do{
        fflush(stdin);
        r=getString(emp[aux].nombre,"Ingrese el Nombre a modificar: ","---(No mas de 50 y mas de 1 letra)---.",1,50);
        if(r==0){
            printf("El Nombre modificado es: %s\n\n",emp[aux].nombre);
        }else
        {
            printf("Error.\n");
        }
    }while(r!=0);
}

void modificarSalario (eEmployee emp[], int id){
    int r, aux;
    r=1;
    aux=id-1;
    do{
        fflush(stdin);
        r=getFloat(&emp[aux].salario,"Ingrese el salario a modificar: ","---(entre 0 y 6 digitos)---.",1,999999);
        if(r==0){
            printf("El salario modificado es: $%.2f\n\n",emp[aux].salario);
        }else{
            printf("Error.\n");
        }
    }while(r!=0);
}

void modificarSector (eEmployee emp[], int id){
    int r, aux;
    r=1;
    aux=id-1;
    do{
        fflush(stdin);
        r=getInt(&emp[aux].sector,"Ingrese el sector a modificar: ","---(ingrese el sector)---.",0,10);
        if(r==0){
            printf("El sector modificado es: %d\n\n",emp[aux].sector);
        }else{
            printf("Error.\n");
        }
    }while(r!=0);
}


void printEmployees(eEmployee emp[], int cant){
    int i;
    for(i=0;i<cant;i++){
       printsOne(emp[i]);
        }
}

void printsOne(eEmployee emp){
    printf("\n//Apellido: %s",emp.apellido);
    printf("\t//Nombre: %s",emp.nombre);
    printf("\t//Id: %d",emp.id);
    printf("\t//Sector: %d\n",emp.sector);
}

int findEmployeeById(eEmployee emp[] , int id){
    int i, aux, retorno;
    aux=id+1;
    if(aux > 0 && emp != NULL)
    {
        for(i=0;i<aux;i++)
        {
            if(emp[i].isEmpty == 0)
            {
                printf("El empleado buscado es: \n Apellido: %s Nombre: %s \t Salario: %f \t Sector: %d\n",
                       emp[i].apellido,emp[i].nombre,emp[i].salario,emp[i].sector);
                retorno= i;
            }else{
                printf("El id ingresado no es valido");
                retorno= 0;
            }
        }
    }
    return retorno;
}

void sortEmployees(eEmployee emp[], int cant){
    int i;
    int j;
    eEmployee auxEmployee;

    for(i=0; i<cant-1; i++)
    {
        for (j=i+1; j<cant; j++)
        {
            if(strcmp(emp[i].apellido,emp[j].apellido)>0)
            {
                auxEmployee=emp[i];
                emp[i]=emp[j];
                emp[j]=auxEmployee;
            }
        }
    }
}

void sortEmployeesBySector(eEmployee emp[], int cant){
    int maxSector=0;
    int i;
    int j;
    int k;
    int bandera=0;

    for(i=0; i<cant; i++)
    {
        if(emp[i].sector>maxSector&&emp[i].isEmpty==0)
        {
            maxSector=emp[i].sector;
        }
    }

    for(j=0; j<maxSector; j++)
    {
        bandera=0;
        for(k=0; k<cant; k++)
        {
            if(emp[k].sector==j&&emp[j].isEmpty==0)
            {
                if(bandera==0)
                {
                    printf("\nSECTOR %d\n\n", j);
                    bandera=1;
                }
                printf("\n%s, %s", emp[k].apellido, emp[k].nombre);
            }
        }

    }

}

float salarioTotal(eEmployee emp[], int cant){
    int i;
    float acumuladorSalarios=0;

    for(i=0; i<cant; i++)
    {
        if(emp[i].isEmpty==0)
        {
            acumuladorSalarios=acumuladorSalarios+emp[i].salario;
        }
    }
    return acumuladorSalarios;
}

float promedioSalarioTotal(eEmployee emp[], int cant){
    float promedioSalarios;
    float salariosTotales;
    int quantity;

    quantity=empQuantity(emp,cant);

    salariosTotales=salarioTotal(emp, cant);

    promedioSalarios=salariosTotales/quantity;

    return promedioSalarios;
}
