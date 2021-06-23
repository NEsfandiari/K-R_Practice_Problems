#include <stdio.h>

void strcat(char *s, char *t);

int main(){
    int c, i = 0, j = 0, flag = 0;
    char s[100], t[100];
    while((c = getchar()) != '\0' && c != '\n'){
        if (c == ' ')
            flag = 1;
        else if(!flag)
            s[i++] = c;
        else
            t[j++] = c;
    }
    t[j] = '\0';
    char *ps = (&s[0] + i), *pt = &t[0];
    strcat(ps, pt);
    printf("%s", s);
}

void strcat(char *s, char *t){
    while(*t != '\0')
        *s++ = *t++;
}