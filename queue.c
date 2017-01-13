/* queue list */
#include <stdio.h>
#include <stdlib.h>

typedef int valType;

typedef struct tnode {
    valType value;
    struct tnode *next;
} NODE;

static NODE *head;
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
    *q = *(q->next);
    valType rmvd = temp->value;
    free(temp);
    return rmvd;
}

void print(NODE *q) {
    while (q->next != NULL) {
        q = q->next;
        printf("%d, ",q->value);
    }
    printf("\n");
}

void del_all(NODE *q) {
    while (q->next != NULL) {
        del(q);   
    }
}

int main() {
    head = (NODE *) malloc(sizeof(NODE));
    head->next = NULL;
    add(head, 1);
    add(head, 2);
    add(head, 3);
    add(head, 4);
    add(head, 5);

    print(head);
    del(head);
    print(head);

    return 0;
}
