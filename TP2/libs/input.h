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
int getInt(int* input,char msj[],char problematico[], int minValor, int maxValor);

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
int getFloat(float* input,char msj[],char problematico[], float minValor, float maxValor);

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
int getChar(char* input,char msj[],char problematico[], char minValor, char maxValor);

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
int getString(char* input,char msj[],char problematico[], int minValor, int maxValor);
