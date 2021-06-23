#include <stdio.h>
#include <stdlib.h>
#include "bitcount.h"

#define MAX 100

int bitcount(int x);

int main(){
    char n[MAX]; 
    int c, i = 0;

    while((c = getchar()) != EOF && c != '\n')
        n[i++] = c;
    int x = atoi(n);
    printf("%d", bitcount(x));
}