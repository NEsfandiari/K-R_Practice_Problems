#include <stdio.h>

// get the input from the terminal screen, print it back, and show the word count
int main(){
    int c;
    long nc;
    for(nc = 0; (c = getchar()) != EOF; nc++){
        putchar(c);
    }
    printf("Word Count %ld\n", nc);
}