#include <stdio.h>

int main(){
    int c, i, j, ltrs[26];
    for(i = 0; i < 26; i++)
        ltrs[i] = 0;

    while((c = getchar()) != EOF){
        if(c >= 'A' && c <= 'Z')
            c = c + 32;
        if(c >= 'a' && c <= 'z')
            ++ltrs[c-97];
    }

    for(i = 0; i < 26; i++){
        putchar('a'+ i);
        for(j = 0; j < ltrs[i]; j++)
            putchar('-');
        putchar('\n');
    }
}