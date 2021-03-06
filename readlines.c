#include <stdio.h>
#include <string.h>
#include "getline.c"
#include "address.c"

#define MAXLEN 1000
int get_line(char *line, int len);
char *alloc(int);

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0){
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines, int reverse){
    while (nlines-- > 0){
        if(reverse)
            printf("%s\n", lineptr[nlines]);
        else
            printf("%s\n", *lineptr++);
    }
}