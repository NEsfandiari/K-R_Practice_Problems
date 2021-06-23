#include <stdio.h>

#define MAX 1000

void escape(char s[], char t[]);

int main(){
    int len = 0, c;
    char t[1000];

    while((c = getchar()) != EOF)
        t[len++] = c;
    t[len++] = '\0';
    char s[len];
    escape(s, t);
    printf("\n%s", s);
}

void escape(char s[], char t[]){
    char c;
    int j = 0, i = 0;
    while ((c = t[i++]) != '\0'){
        switch(c){
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = c;
                break;
        }
    }
}