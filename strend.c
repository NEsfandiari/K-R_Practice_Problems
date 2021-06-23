#include <stdio.h>

int strend(char *s, char *t);

int main(){
    int c, i = 0, j = 0, flag = 0;
    char s[100], t[100];
    while((c = getchar()) != '\0' && c != '\n'){
        if (c == ' '){
            flag = 1;
            s[i] = '\0';
        }
        else if(!flag)
            s[i++] = c;
        else
            t[j++] = c;
    }
    t[j] = '\0';
    char *ps = &s[0] + i-1, *pt = &t[0]+ j-1;
    printf("%d", strend(ps, pt));
}

int strend(char *s, char *t){
    while(*t)
        if(*t-- != *s--)
            return 0;
    return 1;
}