#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){
    int c;
    if(argc == 2 && strcmp(argv[1], "-u") == 0){
        while((c = getchar()) != EOF)
            putchar(toupper(c));
    } else{
        while((c = getchar()) != EOF)
            putchar(tolower(c));
    }
}