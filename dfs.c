#include <stdio.h>
#include <stdlib.h>

// initialization code
typedef struct pNODE_LS {
    struct pNODE *value;
    struct pNODE_LS *next;
} LL_NODE;

typedef struct pNODE {
    //int value; <- don't need to use it for this
    struct pNODE_LS *neighbors;        // will do neighbors as a linked list
    int discovered;
    int id;
} GRAPH_NODE;

static struct pNODE *pRoot;
static struct pNODE *pA;
static struct pNODE *pB;
static struct pNODE *pC;
static struct pNODE *pD;
static struct pNODE *pE;

void addEdge(GRAPH_NODE *pNode1, GRAPH_NODE *pNode2) {
    LL_NODE *llnode1 = (LL_NODE *) malloc(sizeof(LL_NODE));
    llnode1->value = pNode1;
    llnode1->next = NULL;
    LL_NODE *llnode2 = (LL_NODE *) malloc(sizeof(LL_NODE));
    llnode2->value = pNode2;
    llnode2->next = NULL;
    
// gonna try putting them at end instead
    LL_NODE *neighbors2 = pNode2->neighbors;
    LL_NODE *neighbors1 = pNode1->neighbors;
    
    while (neighbors2->next != NULL) neighbors2 = neighbors2->next;
    while (neighbors1->next != NULL) neighbors1 = neighbors1->next;

    neighbors2->next = llnode1;
    neighbors1->next = llnode2;
}

void freeNode(GRAPH_NODE *pNode) {
    LL_NODE *temp;
    while (pNode->neighbors != NULL) {
        temp = pNode->neighbors;
        pNode->neighbors = pNode->neighbors->next;
        free(temp);
    }
    free(pNode);
}

// dfs search
void dfs(GRAPH_NODE *pNode) {
    pNode->discovered = 1;
    LL_NODE *neighbor = pNode->neighbors;
    while (neighbor->next != NULL) {
        neighbor = neighbor->next;
        if (!neighbor->value->discovered) {
            neighbor->value->discovered = 1;
            printf("traversed node %d\n", neighbor->value->id);
            dfs(neighbor->value);
        }
    }
}

int main() {
    // initialize test graph
    pRoot = (GRAPH_NODE *) malloc(sizeof(GRAPH_NODE));
    pRoot->neighbors = (LL_NODE *)malloc(sizeof(LL_NODE));
    pRoot->neighbors->next = NULL;

    pA = (GRAPH_NODE *) malloc(sizeof(GRAPH_NODE));
    pB = (GRAPH_NODE *) malloc(sizeof(GRAPH_NODE));
    pC = (GRAPH_NODE *) malloc(sizeof(GRAPH_NODE));
    pD = (GRAPH_NODE *) malloc(sizeof(GRAPH_NODE));
    pE = (GRAPH_NODE *) malloc(sizeof(GRAPH_NODE));

    pA->neighbors = (LL_NODE *) malloc(sizeof(LL_NODE));
    pA->neighbors->next = NULL;
    pB->neighbors = (LL_NODE *) malloc(sizeof(LL_NODE));
    pB->neighbors->next = NULL;
    pC->neighbors = (LL_NODE *) malloc(sizeof(LL_NODE));
    pC->neighbors->next = NULL;
    pD->neighbors = (LL_NODE *) malloc(sizeof(LL_NODE));
    pD->neighbors->next = NULL;
    pE->neighbors = (LL_NODE *) malloc(sizeof(LL_NODE));
    pE->neighbors->next = NULL;

    pRoot->discovered = 0;
    pA->discovered = 0;
    pB->discovered = 0;
    pC->discovered = 0;
    pD->discovered = 0;
    pE->discovered = 0;

    pRoot->id = 0;
    pA->id = 1;
    pB->id = 2;
    pC->id = 3;
    pD->id = 4;
    pE->id = 5;

    addEdge(pRoot, pA);
    addEdge(pRoot, pB);
    addEdge(pRoot, pC);
    addEdge(pA, pB);
    addEdge(pC, pD);
    addEdge(pA, pE);

    LL_NODE *blah = pRoot->neighbors;
    while (blah!= NULL) {
        printf("hey %p\n", blah->value);
        blah = blah->next;
    }
    // do bfs and print result
    dfs(pRoot);

/*
    printf("root: %d\n", pRoot->distance);
    printf("A: %d\n", pA->distance);
    printf("B: %d\n", pB->distance);
    printf("C: %d\n", pC->distance);
    printf("D: %d\n", pD->distance);
*/

    // free everything
    freeNode(pRoot);
    freeNode(pA);
    freeNode(pB);
    freeNode(pC);
    freeNode(pD);
    freeNode(pE);
    
    return 0;
}

