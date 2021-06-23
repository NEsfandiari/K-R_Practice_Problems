#include <stdio.h>
#include <stdlib.h>

#define MAX 100

static char (*daytab)[13] = (char [][13]){
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};


int day_of_year(int year, int month, int day);

int main(){
    int c, year = 0, month = 0, day = 0, i = 0;
    char num[MAX];
    while ((c = getchar()) != EOF){
        if(c == ' ' || c == '\n'){
            if(!year){
                year = atoi(num);
            } else if (!month){
                month = atoi(num);
            } else {
                day = atoi(num);
                break;
            }
            for(; i >= 0; i--)
                num[i] = '\0';
            i = 0;
        } else {
            num[i++] = c;
        }
    }
    printf("%d", day_of_year(year, month, day));
}

int day_of_year(int year, int month, int day){
    printf("%d, %d, %d\n", year, month, day);
    int i, leap;
    char *dayp;
    
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    dayp = leap ? &daytab[1][1] : &daytab[0][1];
    for (i = 1; i < month; i++)
        day += (*dayp)++;
    return day;
}