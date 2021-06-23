#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f){
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full");
}

double pop(void){
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void dup(void){
    if (sp > 0){
        char cur = val[sp-1];
        val[sp++] = cur;
    }
    else {
        printf("error: stack empty\n");
    }
}

void swap(void){
    if (sp < 2)
        printf("error: not enough values");
    else {
        char temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
    }
}

void clear(void){
    sp = 0;
}

double peek(void){
    if (sp > 0)
        return val[sp-1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void print(void){
    for(int i = 0; i < sp; i++){
        printf("%.8g ", val[i]);
    }
    printf("\n");
}