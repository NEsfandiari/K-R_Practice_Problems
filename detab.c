#include <stdio.h>
#define MAXLINE 100
#define TABSTOP 8

int get_line();
char line[MAXLINE];

// replace tabs with spaces
int main(){
    while(get_line() > 0)
        printf("%s\n", line);
    return 0;
}

int get_line(){
    int c, i;

    for (i=0; i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n'; ++i){
        if(c == '\t'){
            while((i+1) % TABSTOP != 0){
                line[i] = ' ';
                i++;
            }
        } else {
            line[i] = c;
        }
    }
    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}