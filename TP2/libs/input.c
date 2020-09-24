#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(int* input,char msj[],char problematico[], int minValor, int maxValor){
    int c;
    printf("%s\t%s\n",msj,problematico);
    scanf("%d",input);
    c=*input;
    if(c<maxValor && c>minValor){
        return 0;
    }else{
        return -1;
    }
}

int getFloat(float* input,char msj[],char problematico[], float minValor, float maxValor){
    float c;
    printf("%s\t%s\n",msj,problematico);
    scanf("%f",input);
    c=*input;
    if(c<maxValor && c>minValor){
        return 0;
    }else{
        return -1;
    }
}

int getChar(char* input,char msj[],char problematico[], char minValor, char maxValor){
    char c;
    printf("%s\t%s\n",msj,problematico);
    scanf("%c",input);
    fflush(stdin);
    c=*input;
    if(c<maxValor && c>minValor){
        return 0;
    }else{
        return -1;
    }
}

int getString(char* input,char msj[],char problematico[], int minValor, int maxValor){
    printf("%s\t%s\n",msj,problematico);
    gets(input);
    fflush(stdin);
    if(strlen(input)>minValor && strlen(input)<maxValor){
        return 0;
    }else{
        return -1;
    }
}
