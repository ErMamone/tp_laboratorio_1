#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief Menu interactivo para realizar los datos de la calculadora
 *
 * \param Opcion para ingresar al switch
 * \param Numero 1 ingresado para calcular
 * \param Numero 2 ingresado para calcular
 * \param Caracter para seguir o para el programa
 * \param Numero resultado de la suma dada entre el numero 1 y 2
 * \param Numero resultado de la resta dada entre el numero 1 y 2
 * \param Numero resultado de la multiplicacion dada entre el numero 1 y 2
 * \param Numero resultado de la division dada entre el numero 1 y 2
 * \param Numero resultado de la factorizacion del numero 1
 * \param Numero resultado de la factorizacion del numero 2
 * \return Devuelve un caracter el cual termina el programa o permite reingresar los numeros
 *
 */
char menuInteractivo(int opcion, float num1, float num2, char seguir, float resultadoSuma, float resultadoResta, float resultadoMulti, float resultadoDiv, float resultadoFactorizacion1, float resultadoFactorizacion2);
