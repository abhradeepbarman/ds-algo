#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node *n; // creating a Node pointer
    n = (struct Node *) malloc(sizeof(struct Node));  // allocating memory in the heap
    n->data = data;   
    n->left = NULL;
    n->right = NULL;

    return n; // finally reaturning the created Node
}

int main()
{
    /*

    // Constructing the root Node
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    // Constructing the second Node
    struct Node *p1 = malloc(sizeof(struct Node));
    p->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    // Constructing the third Node
    struct Node *p2 = (struct Node *) malloc(sizeof(struct Node));
    p->data = 4;
    p2->left = NULL;
    p2->right = NULL;

    */


    // creating the nodes -- using functions (recommended)
    struct Node *p = createNode(2);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(4);

    // linking the root Node with left & right children
    p->left = p1;
    p->right = p2;

    return 0;
}