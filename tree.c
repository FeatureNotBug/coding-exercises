/* ordinary tree */
#include <stdio.h>
#include <stdlib.h>

typedef int valType;

typedef struct tnode {
    valType value;
    struct tnode *left;
    struct tnode *right;
} NODE;

void insert(NODE **tree, valType value) {
    NODE *temp;// = NULL;
    printf("calling insert on %d\n", value);
    if ((*tree) == NULL) {
        temp = (NODE *)malloc(sizeof(NODE));
        temp->left = NULL;
        temp->right = NULL;
        temp->value = value;
        *tree = temp;
        printf("inserted %d\n", value);
        return;
    }

    if (value < (*tree)->value) {
        printf("going left, compare %d\n",  value);
        insert(&(*tree)->left, value);
    } else {//if (value > tree->value) {
        printf("going right, compare %d\n",  value);
        insert(&(*tree)->right, value);
    }
}

void delete_all(NODE *tree) {
    if (tree) {
        delete_all(tree->left);
        delete_all(tree->right);
        free(tree);
    }
}


/* maybe add delete later */

void preorder(NODE *tree) {
    if (tree) {
        printf("%d\n",tree->value);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(NODE *tree) {
    if(tree) {
        inorder(tree->left);
        printf("%d\n", tree->value);
        inorder(tree->right);
    }
}

void postorder(NODE *tree) {
    if (tree) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\n", tree->value);
    }
}

int main() {
    NODE *tree = (NODE *)malloc(sizeof(NODE));
    printf("0");
    tree->value = 10;
    printf("1");
    insert(&tree, 6);
    printf("2");
    insert(&tree, 12);
    printf("3");
    insert(&tree, 2);
    printf("4");
    insert(&tree, 8);
    printf("5");
    insert(&tree, 0);
    printf("6");
    insert(&tree, 4);
    printf("7");
    insert(&tree, 7);
    printf("8");
    insert(&tree, 9);
    printf("9\n");
    
    preorder(tree);
    printf("====================\n");
    inorder(tree);
    printf("====================\n");
    postorder(tree);
    delete_all(tree);
    return 0;
}
