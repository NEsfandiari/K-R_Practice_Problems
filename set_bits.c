#include <stdio.h>
#include "bitcount.h"

int bitcount(int x);
int setbits(int x, int p, int n, int y);
/* 
return x with n bits that begin at position p
set to the rightmost n bits of y
leaving the others unchanged
*/
int main(){
    int n1, p, n, n2;
    int c, flag = 0;

    while((c = getchar()) != EOF && c != '\n'){
        if(c != ' '){
            if(!n1)
                n1 = c;
            else if(!p)
                p = c;
            else if (!n)
                n = c;
            else if (!n2)
                n2 = c;
        }
    }
    printf("%d",setbits(n1, p, n, n2));
}

int setbits(int x, int p, int n, int y){
    int y_count = bitcount(y);
    int diff = y_count - n;
    y &= ~(~0 << (y_count - diff));
    y <<= (p-1);
    return x & y;
}