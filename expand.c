#include <stdio.h>
#include <ctype.h>

#define MAX 1000

void expand(char s[], char t[]);

int main(){
    int i = 0, c;
    char s1[MAX], s2[MAX];

    while((c = getchar()) != EOF && c != '\n')
        s1[i++] = c;
    s1[i++] = '\0';
    expand(s1, s2);
    printf("\n%s", s2);
}

void expand(char s1[], char s2[]){
    char c;
    int j = 0, i = 0;
    char start;
    while ((c = s1[i++]) != '\0'){
        if(isalnum(c)){
            if (!start)
                start = c;
            else {
                while(start <= c)
                   s2[j++] = start++;
                start = s1[i] == '-' ? c : 0;
            }
        }
    }
    s2[j] = '\0';
}