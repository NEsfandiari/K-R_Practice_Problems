#include <stdio.h>
#include <string.h>
#include "readlines.c"

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);

int main(){
    int nlines;
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        int i;
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
    }
}
