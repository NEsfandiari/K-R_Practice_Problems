#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

int main(){
    int type;
    double op2;
    char s[MAXOP], var;
    double vars[26];
    for(int i; i < 26; i++)
        vars[i] = 0.0;

    while((type = getop(s)) != EOF){
        switch (type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() - op2);
                break;
            case '%':
                op2 = pop();
                push((int)pop() % (int)op2);
                break;
            case '=':
                pop();
                if(var >= 'A' && var <= 'Z')
                    vars[(int)var-'A'] = pop();
            case 'd':
                dup();
                break;
            case 'c':
                clear();
                break;
            case 's':
                swap();
                break;
            case 'p':
                printf("\t%.8g\n", peek());
                break;
            case '\n':
                print();
                break;
            default:
                if (type >= 'A' && type <= 'Z'){
                    push(vars[type-'A']);
                }
                else if(type == 'v')
                    push(var);
                else 
                    printf("error: unknown command %s\n", s);
                break;
        }
        var = type;
    }
    return 0;
}