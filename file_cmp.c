#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int main(int argc, char *argv[]){
    if(argc != 3)
        exit(1);

    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");
    char line1[MAXLINE], line2[MAXLINE];
    while(fgets(line1, MAXLINE, fp1) != NULL && fgets(line2, MAXLINE, fp2) != NULL){
        if(strcmp(line1, line2) != 0){
            printf("These lines differed:\nFile1: %sFile2: %s", line1, line2);
            exit(0);
        }
    }
    printf("The Files Were the Same");
    exit(0);
}