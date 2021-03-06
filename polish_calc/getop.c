#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getch(void);
void ungetch(int);

int getop(char s[]){
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t');
    
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));
    // collect decimal value
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));
    // allow for negative numbers
    if (c == '-'){
        if(isdigit(s[++i] = c = getch())){
            while (isdigit(s[++i] = c = getch()));
        }
        else {
            ungetch(c);
            return '-';
        }
    }
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}