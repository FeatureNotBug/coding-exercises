#include <stdio.h>
#include <stdlib.h>

// initialization code
typedef struct pNODE_LS {
    struct pNODE *value;
    struct pNODE_LS *next;
} LL_NODE;

typedef struct pNODE {
    int id;
    int distance;
    struct pNODE_LS *neighbors;        // will do neighbors as a linked list
} GRAPH_NODE;

static struct pNODE *pRoot;
static struct pNODE *pA;
static struct pNODE *pB;
static struct pNODE *pC;
static struct pNODE *pD;

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

// bfs search
void bfs(GRAPH_NODE *pRoot) {
    LL_NODE *temp;

    LL_NODE *pQ = (LL_NODE *) malloc(sizeof(LL_NODE));
    LL_NODE *pQinit = (LL_NODE *) malloc(sizeof(LL_NODE));
    pQinit->next = NULL;
    pQinit->value = pRoot;
    pQ->next = pQinit;
    LL_NODE *pQCopy; 

    GRAPH_NODE *pCurrNode;
    LL_NODE *pLLNeighbor;
    LL_NODE *toAdd;
    int currDist;

    int qSize = 1;
    while (qSize > 0) {
        // dequeue
        temp = pQ;
        pQ = pQ->next;
        pCurrNode = pQ->value;
        currDist = pCurrNode->distance;
        pLLNeighbor = pCurrNode->neighbors;
        free(temp);
        qSize--;
        
        while (pLLNeighbor->next != NULL) {
            pLLNeighbor = pLLNeighbor->next;
            if (pLLNeighbor->value->distance < 0) {
                pLLNeighbor->value->distance = currDist + 1;
                // add currAdj to pQ
                pQCopy = pQ;
                while (pQCopy->next != NULL) 
                    pQCopy = pQCopy->next;
                toAdd = (LL_NODE *)malloc(sizeof(LL_NODE));
                toAdd->value = pLLNeighbor->value;
                toAdd->next = NULL;
                pQCopy->next = toAdd;
                qSize++;
            }
        }
    }

    // free I guess everything in Q
    while (pQ != NULL) {
        temp = pQ;
        pQ = pQ->next;
        free(temp);
    }
}

int main() {
    // initialize test graph
    pRoot = (GRAPH_NODE *) malloc(sizeof(GRAPH_NODE));
    pRoot->distance = 0;
    pRoot->neighbors = (LL_NODE *)malloc(sizeof(LL_NODE));
    pRoot->neighbors->next = NULL;

    pA = (GRAPH_NODE *) malloc(sizeof(GRAPH_NODE));
    pB = (GRAPH_NODE *) malloc(sizeof(GRAPH_NODE));
    pC = (GRAPH_NODE *) malloc(sizeof(GRAPH_NODE));
    pD = (GRAPH_NODE *) malloc(sizeof(GRAPH_NODE));

    pA->neighbors = (LL_NODE *) malloc(sizeof(LL_NODE));
    pA->neighbors->next = NULL;
    pB->neighbors = (LL_NODE *) malloc(sizeof(LL_NODE));
    pB->neighbors->next = NULL;
    pC->neighbors = (LL_NODE *) malloc(sizeof(LL_NODE));
    pC->neighbors->next = NULL;
    pD->neighbors = (LL_NODE *) malloc(sizeof(LL_NODE));
    pD->neighbors->next = NULL;

    pRoot->id = 0;
    pA->id = 1;
    pB->id = 2;
    pC->id = 3;
    pD->id = 4;

    pA->distance = -1;
    pB->distance = -1;
    pC->distance = -1;
    pD->distance = -1;

    addEdge(pRoot, pA);
    addEdge(pRoot, pB);
    addEdge(pRoot, pC);
    addEdge(pA, pB);
    addEdge(pC, pD);

    // do bfs and print result
    bfs(pRoot);

    printf("root: %d\n", pRoot->distance);
    printf("A: %d\n", pA->distance);
    printf("B: %d\n", pB->distance);
    printf("C: %d\n", pC->distance);
    printf("D: %d\n", pD->distance);

    // free everything
    freeNode(pRoot);
    freeNode(pA);
    freeNode(pB);
    freeNode(pC);
    freeNode(pD);
    
    return 0;
}
