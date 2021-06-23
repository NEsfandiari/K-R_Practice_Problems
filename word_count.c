#include <stdio.h>

#define IN 1
#define OUT 2

int main(){
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF){
        nc++;
        if(c == '\n')
            nl++;
        if(c == '\n' || c == '\t' || c == ' '){
            putchar('\n');
            state = OUT;
        }
        else if (state == OUT){
            putchar(c);
            state = IN;
            nw++;
        }
        else
            putchar(c);
    }
    printf("\nData: %d %d %d\n", nl, nw, nc);
}