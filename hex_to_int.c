#include <stdio.h>

int htoi(char hex_arr[], int len);
char hex_string[];

int main(){
    int c, i, ans;
    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++){
        if(i == 0 && c != '0'){
            printf("Not a hex num");
        } else if(i >= 2){
           hex_string[i-2] = c;
        }
    }
    hex_string[i] = '\0';
    ans = htoi(hex_string, i-2);
    printf("%d", ans);
}

int htoi(char hex_arr[], int len){
    int n = 0, i = 0, exp;
    while(len > 0){
        exp = 0;
        for (int j = len - 1; j > 0; j--){
            if(!exp)
                exp = 16;
            else
                exp = 16 * exp;
        }
        n = n + (hex_arr[i] * exp);
        len--;
        i++;
    }
    return n;
}