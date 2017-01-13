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

void add(NODE *q, valType value) {
    NODE *new = (NODE *) malloc(sizeof(NODE));
    new->value = value;
    NODE *curr_node = q;
    while (curr_node->next != NULL) {
        curr_node = curr_node->next;
    }
    curr_node->next = new;
    new->next = NULL;
}

valType del(NODE *q) {
    NODE *temp = q;
    q = q->next;
    valType rmvd = temp->value;
    free(temp);
    return rmvd;
}

int main() {
    return 0;
}
