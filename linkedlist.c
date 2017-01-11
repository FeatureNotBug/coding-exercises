/* Singly linked list */
#include <stdio.h>
#include <stdlib.h>

typedef int valType;

typedef struct tnode {
    valType value;
    struct tnode *next;
} NODE;

typedef struct tlinkedlist {
    struct tnode *head;
} LINKED_LIST;

void init(LINKED_LIST *ls) {
    ls = malloc(sizeof(LINKED_LIST));
    ls->head = (NODE *) malloc(sizeof(NODE));
    ls->head->next = NULL;
}

void add(LINKED_LIST *ls, valType value, int index) {
    int i = -1;         // "index" of head
    NODE *curr_node = ls->head;
    NODE *to_insert = (NODE *) malloc(sizeof(NODE));
    to_insert->value = value;

    int inserted = 0;
    while (i <= index) {
        if (i == index) {
            NODE *next_node = curr_node->next;
            curr_node->next = to_insert;
            to_insert->next = next_node;
            inserted = 1;
        }
        i++;
    }
    if (!inserted) {
        printf("Index %d given; didn't make sense so I did nothing LOL", index);
    }
}

void del(LINKED_LIST *ls, valType value) {
}

/* ===== TESTING AREA ===== */
int main() {
    LINKED_LIST *ls = NULL;
    init(ls);

    // test adding nodes
    
    return 0;
}
