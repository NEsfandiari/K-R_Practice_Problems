#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s){
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval += *s + 31;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s){
    struct nlist *np;
    
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if(strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *install(char *name, char *defn){
    struct nlist *np;
    unsigned hashval;

    if((np = lookup(name)) == NULL){
        np = (struct nlist *) malloc(sizeof(*np));
        if(np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    if((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

void undef(char *s){
    struct nlist *np = lookup(s);
    unsigned hashval = hash(s);
    if(hashtab[hashval] == np)
        hashtab[hashval] = np->next;

    else {
        struct nlist *prev = hashtab[hashval];
        for (np = hashtab[hashval]; np != NULL; np = np->next)
            if(strcmp(s, np->name) == 0){
                prev->next = np->next;
                break;
            }
            prev = hashtab[hashval];
    }
    free((void *) np);
}

int main(){
    struct nlist *np; 
    
    install("IN", "1");
    install("NI", "23");
    undef("NI");
    install("OUT", "hi");
    
    
    for (int i = 0; i < HASHSIZE; i++){
        np = hashtab[i];
        if(np != NULL)
            printf("%d %s %s \n", i, np->name, np->defn);
    }
}