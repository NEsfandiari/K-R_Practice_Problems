#include <stdio.h>
#include <stdlib.h>
#include "getline.c"

#define MAXLINE 1000

char lines[MAXLINE][MAXLINE];

int get_line(char *line, int max);

int main(int argc, char *argv[]){
    char line[MAXLINE];
    int c, n = 10;
    if(argc > 1 && (*++argv)[0] == '-'){
        if((*argv)[1] == 'n'){
            n = atoi(*++argv);
        } else{
            printf("Format is -n {num}!");
        }
    }
    int len, i = 0;
    while((len = get_line(&line[0], MAXLINE)) != 0){
        for(int j = 0; j < len; j++)
            lines[i][j] = line[j];
        i++;
    }
    while(n-- > -1){
        printf("%s", lines[i-n]);
    }
}