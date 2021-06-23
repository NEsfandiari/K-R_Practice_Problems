#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct tnode {
    char *word;
    char lines[100];
    char *pl;
    struct tnode *left;
    struct tnode *right;
};

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *, int sort);
int getword(char *, int);
int line = 1;

int main(int argc, char *argv[]){
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if(isalpha(word[0]))
            root = addtree(root, word);
    int sort = 0;
    if(argc == 2 && *(argv+1)[1] == 's')
        sort = 1;
    treeprint(root, sort);
    return 0;
}

struct tnode *talloc(void);
// char *strdup(char *s);

struct tnode *addtree(struct tnode *p, char *w){
    int cond;

    if(p == NULL){
        p = talloc();
        p->word = strdup(w);
        p->pl = p->lines;
        *p->pl++ = line;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        *p->pl++ = line;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    *p->pl = '\0';
    return p;
}

void treeprint(struct tnode *p, int sort){
    if(p != NULL && !sort){
        treeprint(p->left, sort);
        printf("%s ", p->word);
        for(int i; p->lines[i] != '\0'; i++)
            printf("%d ", p->lines[i]);
        printf("\n");
        treeprint(p->right, sort);
    }
}

#include <stdlib.h>

struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}

#include "polish_calc/getch.c"

int getword(char *word, int lim){
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while ((c = getch()) == ' ' || c == '\t');
    if(c == '\n'){
        line += 1;
        c = getch();
    }
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)){
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}