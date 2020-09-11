/*
* Funcion de suma y
* devuelve la suma de los dos primeros numeros dados
*/

unsigned int suma (int x, int y){
    int sum = 0;

    sum = x + y;

    return sum;
}

/*
* Funcion resta
* devuelve la resta del primer con el segundo numero
*/

unsigned int resta (int x, int y){
    int res = 0;

    res = x - y;

    return res;
}
/*
* Funcion multiplicar
* multiplica el primer por el segundo numero
* sin importar el orden
*/

unsigned int multiplicar (int x, int y){
    int multi = 0;

    multi = x * y;

    return multi;
}

/*
* Funcion division
* esta funcion divide el primer por el segundo numero
* importa el orden para un resultado optimo
*/

float dividido (int x, int y){
    float div = 0;

	if(x<y){
	   div = (float) y / x;
	}else{
	   div = (float) x / y;
    }

    return div;
}

/*
* Funcion factorizar
* esta factoriza los numeros dados
*/

unsigned int factorizar (int x){
    int dev = 1;
    int i;
    int contadorN = x;
    for(i=1; i<x; i++){
        dev = dev * contadorN;
        contadorN--;
    }
    return dev;
}

