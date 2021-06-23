#include <stdio.h>
#include <string.h>
#include "readlines.c"

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int r);

void q_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);

int main(int argc, char *argv[]){
    int nlines, numeric = 0, reverse = 0;
    if(argc > 1){
        for(int i = 0; i < argc; argv++, i++){
            if(strcmp(*argv, "-n") == 0)
                numeric = 1;
            else if(strcmp(*argv, "-r") == 0)
                reverse = 1;
            // else if (strcmp(*argv, "-d") == 0)

        }
        
    }
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        q_sort((void **) lineptr, 0, nlines-1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines, reverse);
        return 0;
    } else {
        printf("input too big to sort \n");
        return 1;
    }
}

void q_sort(void *v[], int left, int right, int (*comp)(void *, void *)){
    int i, last;
    void swap(void *v[], int, int);
    if(left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    q_sort(v, left, last-1, comp);
    q_sort(v, last + 1, right, comp);
}

#include <stdlib.h>

int numcmp(const char *s1, const char *s2){
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if(v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j){
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}