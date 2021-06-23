#include <stdio.h>

int get_line(char *line, int MAXLINE){
    int c, i;

    for (i=0; i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}