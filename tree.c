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
    NODE *temp = NULL;     
    if (!(*tree)) {
        temp = (NODE *)malloc(sizeof(NODE));
        temp->left = temp->right = NULL;
        temp->value = value;
        *tree = temp;
        return;
    }

    if (value < (*tree)->value) {
        insert(&(*tree)->left, value);
    } else if (value > (*tree)->value) {
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


/* need delete for single node. I just remembered it's horrible */

// NEED: postorder, 
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
    return 0;
}
