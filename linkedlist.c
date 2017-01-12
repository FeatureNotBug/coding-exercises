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
    ls = (LINKED_LIST *) malloc(sizeof(LINKED_LIST));
    ls->head = (NODE *) malloc(sizeof(NODE));
    ls->head->next = NULL;
    printf("%p\n", ls->head);
    add(ls, 100, 1);
    printf("hehe %p\n", ls->head);
}

void add(LINKED_LIST *ls, valType value, int index) {
    int i = -1;         // "index" of head
    printf("before currnode %p\n", ls->head);
    NODE *curr_node = ls->head;
    printf("after currnode\n");
    NODE *to_insert = (NODE *) malloc(sizeof(NODE));
    to_insert->value = value;

    int inserted = 0;
    while (i <= index) {
        printf("got here %d\n", i);
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

void print_string(LINKED_LIST *ls) {
    NODE *curr_node = ls->head;
    while (curr_node->next != NULL) {
        curr_node = curr_node->next;
        printf("%d, ", curr_node->value);
    }
}

/* ===== TESTING AREA ===== */
int main() {
    LINKED_LIST *ls = NULL;
    init(ls);
    printf("init\n");
    printf("head is %p\n", ls->head);

    // test adding nodes
    add(ls, 5, 0);
    add(ls, 6, 1);
    add(ls, 7, 2);
    add(ls, 8, 5);
    
    print_string(ls);
    return 0;
}
