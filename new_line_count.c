#include <stdio.h>

int main(){
    int nlc, c;

    while((c = getchar()) != EOF){
        if(c == '\n' || c == '\t' || c == '\b')
            nlc++;
    }
    printf("\nNew Line Count %d\n", nlc);
}