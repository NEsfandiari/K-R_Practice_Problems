#include <stdio.h>

#define MAX 100

void reverse(int i);

int len;
char s[MAX];

int main(){
    int c, i = 0;

    while((c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    len = i-1;
    reverse(0);
    printf("%s", s);    
}

void reverse(int i){
    if(i > (len / 2))
        return;

    char temp = s[i];
    s[i] = s[len-i];
    s[len-i] = temp;
    reverse(i+1);
}