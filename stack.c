/* Stack */
#include <stdio.h>
#include <stdlib.h>

typedef int valType;

typedef struct tnode {
    valType value;
    struct tnode *next;
} NODE;

/*
typedef struct tstack {
    struct tnode *head;
} STACK;
*/

void push(NODE *stack, valType value) {
    NODE *new = (NODE *) malloc(sizeof(NODE));
    new->value = value;
    NODE *temp = stack;
    stack = new;
    new->next = temp;
}

valType pop(NODE *stack) {
    NODE temp = stack;
    valType popped = temp->value;
    stack = stack->next;
    free(temp);
    return popped;
}

void erase(NODE *stack) {
    while (stack) pop(stack);
}

int main() {
    return 0;
}
