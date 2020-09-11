unsigned int suma (int x, int y){
    int sum = 0;

    sum = x + y;

    return sum;
}

unsigned int resta (int x, int y){
    int res = 0;

    res = x - y;

    return res;
}

unsigned int multiplicar (int x, int y){
    int multi = 0;

    multi = x * y;

    return multi;
}


float dividido (int x, int y){
    float div = 0;

	if(x<y){
	   div = (float) y / x;
	}else{
	   div = (float) x / y;
    }

    return div;
}

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
