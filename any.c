#include <stdio.h>

#define MAX 100

int any(char s1[], char s2[]);

int main(){
    char s1[MAX], s2[MAX];
    int c, i = 0, j = 0, flag = 0;

    while((c = getchar()) != EOF && c != '\n'){
        if(c == ' ')
            flag = 1;
        if(flag)
            s2[j++] = c;
        else
            s1[i++] = c;
    }
    printf("%d",any(s1, s2));
}

// return the first location where a char from s2 occurs in s1
int any(char s1[], char s2[]){
    printf("%s %s", s1, s2);
    int i = 0, j = 0;
    while(i < sizeof s2){
        char c = s2[i++];
        while(j < sizeof s1){
            if(s1[j++] == c)
                return j;
        }
    }
    return -1;
}