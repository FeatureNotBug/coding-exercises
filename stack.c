/* Stack */
#include <stdio.h>
#include <stdlib.h>

typedef int valType;

typedef struct tnode {
    valType value;
    struct tnode *next;
} NODE;

void push(NODE **stack, valType value) {
    NODE *new;
    new = (NODE *) malloc(sizeof(NODE));
    printf("adding %d\n", (*stack)->value);
    new->value = value;
    NODE *temp = *stack;
    *stack = new;
    new->next = temp;
    printf("adding %d\n", (*stack)->value);
}

valType pop(NODE **stack) {
    NODE *temp = *stack;
    valType popped = temp->value;
    *stack = (*stack)->next;
    free(temp);
    return popped;
}

void erase(NODE *stack) {
    while (stack) pop(&stack);
}

void print(NODE *stack) {
    if (stack == NULL) return;

    NODE *curr_node = stack;
    while (curr_node->next != NULL) {
        printf("%d, ", curr_node->value);
        curr_node = curr_node->next;
    }
    printf("%d\n", curr_node->value);
}

int main() {
    NODE *stack = (NODE *) malloc(sizeof(NODE));
    stack->value = 1;
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    print(stack);
    
    pop(&stack);
    print(stack);
    
    pop(&stack); pop(&stack); pop(&stack); pop(&stack);
    print(stack);

    erase(stack);
    return 0;
}
