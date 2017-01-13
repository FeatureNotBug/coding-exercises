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

void init(NODE *ls) {
    ls = (NODE *) malloc(sizeof(NODE));
    ls->next = NULL;
    printf("%p\n", ls);
}

void add(NODE **ls, valType value, int index) {
    int i = -1;         // "index" of head
    NODE *curr_node = *ls;
    NODE *to_insert = (NODE *) malloc(sizeof(NODE));
    to_insert->value = value;
    to_insert->next = NULL;

    while (i <= index) {
        i++;
        //printf("i=%d, index=%d, curr_node=%d\n", i, index, curr_node->value);
        if (i == index) {
            NODE *next_node = curr_node->next;
            curr_node->next = to_insert;
            to_insert->next = next_node;
        } else {
            if (curr_node->next == NULL) {
                printf("Index %d given; didn't make sense so I did nothing LOL\n", index);
                return;
            }
            curr_node = curr_node->next;
        }
    }
}

void del_all(NODE *ls) {
    NODE *curr_node = ls;
    while (curr_node->next != NULL) {
        NODE *temp_node = curr_node;
        free(temp_node);
        curr_node = curr_node->next;
    }
    free(curr_node);
}

void del(NODE *ls, int value) {
    NODE *curr_node = ls;
    NODE *prev_node;
    while (curr_node->next != NULL) {
        if (curr_node->value == value) {
            NODE *temp_node = curr_node;
            prev_node->next = curr_node->next;
            free(temp_node);
            return;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    // check to see if last one is the wanted value
    if (curr_node->value == value) {
        prev_node->next = NULL;
        free(curr_node);
        return;
    }
    printf("OH COME ON.  Value %d isn't in there.\n", value);
}

void print_string(NODE *ls) {
    NODE *curr_node = ls;
    while (curr_node->next != NULL) {
        curr_node = curr_node->next;
        printf("%d, ", curr_node->value);
    }
    printf("\n");
}

/* ===== TESTING AREA ===== */
int main() {
    NODE *ls = NULL;
    //init(ls);
    ls = (NODE *) malloc(sizeof(NODE));
    ls->next = NULL;
    printf("init\n");
    printf("head is %p\n", &ls);

    // test adding nodes
    add(&ls, 5, 0);
    add(&ls, 6, 1);
    add(&ls, 7, 2);
    add(&ls, 8, 5);
    
    print_string(ls);

    del(ls, 6);
    del(ls, 6);
    print_string(ls);
    del_all(ls);
    return 0;
}
