#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int get_line();
char line[MAXLINE];

// Remove Comments like the one below from a program
/*
I am 
a super
long comment
that should be deleted
and never seen
when running this program
on itself
*/
int main(){
    while(get_line() > 0){
        if(line[0] != '\0')
            printf("%s", line);
    }
    return 0;
}

int get_line(){
    int c, i;

    for (i=0; i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n'; ++i){
        if(c == '/'){
            c = getchar();
            if(c == '/'){
                // remove everything from the single line comment
                while((c = getchar()) != '\n')
                memset(line, '\0', sizeof line);
                return 1;
            } else if(c == '*'){
                // Remove every single character between the stars
                while((c = getchar()) != '*')
                memset(line, '\0', sizeof line);
                return 1;
            } else {
                // keep '/' operator use intact
                line[i-1] = '/';
                line[i] = c;
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