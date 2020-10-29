#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param msj Es el mensaje a ser mostrado
* \param problematico Es el mensaje a ser mostrado en caso de error
* \param minValor Limite inferior a validar
* \param maxValor Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1] (valido en busca del error)
*
*/
int getInt(int* input,char msj[],char problematico[], int minValor, int maxValor)
{
    int c, retorno;
    printf("%s\n",msj);
    scanf("%d",input);
    c=*input;
    if(c<maxValor && c>minValor){
        retorno=0;
    }else{
        printf("\n%s",problematico);
        retorno=-1;
    }
    return retorno;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param msj Es el mensaje a ser mostrado
* \param problematico Es el mensaje a ser mostrado en caso de error
* \param minValor Limite inferior a validar
* \param maxValor Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1](valido en busca del error)
*
*/
int getFloat(float* input,char msj[],char problematico[], float minValor, float maxValor)
{
    int retorno;
    float c;
    printf("%s\n",msj);
    scanf("%f",input);
    c=*input;
    if(c<maxValor && c>minValor){
        retorno=0;
    }else{
        printf("\n%s",problematico);
        retorno=-1;
    }
    return retorno;
}

/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param msj Es el mensaje a ser mostrado
* \param problematico Es el mensaje a ser mostrado en caso de error
* \param minValor Limite inferior a validar
* \param maxValor Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1](valido en busca del error)
*
*/
int getChar(char* input,char msj[],char problematico[], char minValor, char maxValor)
{
    int retorno;
    char c;
    printf("%s\n",msj);
    scanf("%c",input);
    fflush(stdin);
    c=*input;
    if(c<maxValor && c>minValor){
        retorno=0;
    }else{
        printf("\n%s",problematico);
        retorno=-1;
    }
    return retorno;
}

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param msj Es el mensaje a ser mostrado
* \param problematico Es el mensaje a ser mostrado en caso de error
* \param minValor Longitud mínima de la cadena
* \param maxValor Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char msj[],char problematico[], int minValor, int maxValor)
{
    int retorno;
    printf("%s\n",msj);
    gets(input);
    fflush(stdin);
    if(strlen(input)>minValor && strlen(input)<maxValor){
        retorno=0;
    }else{
        printf("\n%s",problematico);
        retorno=-1;
    }
    return retorno;
}
