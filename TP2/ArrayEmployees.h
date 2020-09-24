typedef struct {
    int id;
    char apellido[51];
    char nombre[51];
    float salario;
    int sector;
    int isEmpty;
}eEmployee;

/** \brief Para indicar que el Array esta vacio e inicializarlo
*
* \param array de empleados
* \param el tamaño del array
*
* \return Pone todo los isEmpty de emp en 1 para indicar que estan vacios.
*/
void initEmployees(eEmployee emp[], int cant);

/** \brief Para indicar la cantidad de puestos en uso
*
* \param Bucle validando los isEmpty de todos los empleados
*
* \return La cantidad de empleados con datos cargados.
*/
int freeEmployee (eEmployee emp[], int MAX);

/** \brief Cantidad de empleados
*
* \param En un acumulador se agrega de a uno la cantidad de empleados que hay.
*
* \return Devuelve la cantidad de empleados.
*/
int empQuantity(eEmployee emp[], int cant);

/** \brief Para agregar empleados
*
* \param Apellido y verificacion con bibliotecas getString
* \param Nombre y verificacion con bibliotecas getString
* \param Salario y verificacion con bibliotecas getFloat
* \param Sector y verificacion con bibliotecas getInt
*
* \return Agrega el valor a los datos de cada empleado agregado.
*/
void addEmployees(eEmployee emp[], int cant);

/** \brief Para eliminar empleados
* \param Eliminacion de todos los datos y se usa "vacio" o 0
* \return Elimina todo valor agregado del id dado.
*/
void removeEmployee(eEmployee emp[], int id);

/** \brief Modificar un dato concreto a partir de un id dado
* \param Busca a partir del ID el empleado y modifica el dato en especifico
* \return Devuelve el dato verificado por un get.
*/
void modificarApellido (eEmployee emp[], int id);
void modificarNombre (eEmployee emp[], int id);
void modificarSalario (eEmployee emp[], int id);
void modificarSector (eEmployee emp[], int id);

/** \brief Imprime en pantalla los datos
* \param Se usa una llamada a un metodo secundario para imprimir los datos en pantalla
* \return Muestra en pantalla los datos de la estructura.
*/
void printEmployees(eEmployee emp[], int cantidad);

/** \brief Imprime en pantalla los datos de un array
* \param Metodo que imprime en pantalla de forma ordenada los datos requeridos
* \return Devuelve los datos de emp.
*/
void printsOne(eEmployee emp);

/** \brief Para buscar empleados por un id pedido
* \param Busca por id en el array de empleados hasta dar con el
* \return Devuelve los datos del empleado encontrado, sino un mensaje de Error.
*/
int findEmployeeById(eEmployee emp[], int id);

/** \brief Ordena los empleados alfabeticamente
* \param Ordena a los empleados listados del array alfabeticamente con el metodo burbuja
* \return Retorna los datos ordenados alfabeticamente.
*/
void sortEmployees(eEmployee emp[], int MAX);

/** \brief Ordenar los empleados por sector
* \param Con el metodo burbuja se ordenan los empleados por sector
* \return Devuelve los datos ordenados de mayor a menor.
*/
void sortEmployeesBySector(eEmployee emp[], int cant);

/** \brief Acumular el salario total de los empleados
* \param Atravez de un bucle, se recorren los salarios y los suma a un auxiliar
* \return Devuelve la cantidad total de la suma de los salarios.
*/
float salarioTotal(eEmployee emp[], int cant);

/** \brief Promedio de los salarios
* \param Con un bucle, una funcion cantidad de empleados y un auxiliar se genera el promedio
* \return Devuelve el promedio de salarios que hay entre los empleados, se divide por la cantidad dada por la funcion quantity.
*/
float promedioSalarioTotal(eEmployee emp[], int cant);

