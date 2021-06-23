#include <stdio.h>
#include "minprintf.c"

// Dick around tests for c
# define swap(t, x, y){\
    t _z;\
    _z = x;\
    x = y;\
    y = _z;\
}

#include <stdlib.h>
                        
int main(){
    struct chore_count{
        char *name;
        int num;
        int *days;
    } roommate_chore_tracker[] = {
        "Ian", 27, malloc(100 * sizeof(int)),
        "Fabian", 22, malloc(100 * sizeof(int)), 
        "Niki", 12, malloc(100 * sizeof(int)),
    };
    int beginning = *roommate_chore_tracker[0].days;
    *roommate_chore_tracker[0].days++ = 1;
    *roommate_chore_tracker[0].days++ = 2;
    *roommate_chore_tracker[0].days++ = 3;
    // printf("%s %d", roommate_chore_tracker[0].name, beginning+2);
    
    char *website;
    char *saying = "partner";
    minprintf("howdy %s\n", saying);
    printf("whats your name and website\n");
    scanf("%s", website);
    printf("%s", website);
}