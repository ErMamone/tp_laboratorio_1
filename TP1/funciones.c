float suma (float x, float y){
    float sum = 0;

    sum = x + y;

    return sum;
}

float resta (float x, float y){
    float res = 0;

    res = x - y;

    return res;
}

float multiplicar (float x, float y){
    float multi = 0;

    multi = x * y;

    return multi;
}


float dividido (float x, float y){
    float div = 0;

    div = x / y;

    return div;
}

float factorizar (float x){
    float dev = 1;
    float i;
    float contadorN = x;
    for(i=1; i<x; i++){
        dev = dev * contadorN;
        contadorN--;
    }
    return dev;
}
