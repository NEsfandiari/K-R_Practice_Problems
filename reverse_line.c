#include <stdio.h>
#define MAXLINE 100

int get_line(char line[], int maxline);
void reverse(char line[], char reversed_line[]);

// Print longest line
int main(){
    int len;
    int max;
    char line[MAXLINE];
    char reversed_line[MAXLINE];

    max = 0;
    while(get_line(line, MAXLINE) > 0){
        reverse(line, reversed_line);
        printf("%s\n", reversed_line);
    }
    return 0;
}

int get_line(char s[], int lim){
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char line[], char reversed_line[]){
    int i, j;

    j = 0;
    while (line[j] != '\0')
        j++;
    j--;
    i = 0;
    while(j > -1){
        reversed_line[i] = line[j];
        i++;
        j--;
    }
}