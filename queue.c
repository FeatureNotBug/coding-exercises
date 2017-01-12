/* queue list */
#include <stdio.h>
#include <stdlib.h>

typedef int valType;

typedef struct tnode {
    valType value;
    struct tnode *next;
} NODE;

typedef struct tqueue {
    struct tnode *head;
} QUEUE;

void add(NODE *q, valType new) {
    
}

void remove(NODE *q) {
    
}
