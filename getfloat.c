#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include "polish_calc/getch.c"

int getfloat(float *);

int main(){
    float ans[100]; 
    int i = 0;
    while(getfloat(&ans[i++]) != EOF);
    printf("%.8g", *ans); 
}

int getfloat(float *pn){
    int c, sign;

    while (isspace(c = getch()));

    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-')
        c = getch();
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    
    if(c == '.'){
        c = getch();
        for(int i = 1; isdigit(c); c = getch()){
            float denom = 1;
            for(int j = 0; j < i; j++)
                denom *= 10;
            *pn += (c - '0') / denom;
            i++;
        }
    }
    *pn *= sign;
    if(c != EOF)
        ungetch(c);
    return c;
}