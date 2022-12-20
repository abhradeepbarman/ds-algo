#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void *enqueue(int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));

    if (n == NULL){
        printf("Queue overflow.");
    } else {
        n->data = value;
        n->next = NULL;

        if(f == NULL) {
            f = r = n;
        } else {
            r->next = n;
            r = n;
        } 
    }
}

void dequeue() {
    if(f == NULL & r == NULL) {
        printf("Queue underflow.");
    } 
    else {
        struct Node *ptr = f;
        f = f->next;
        free(ptr);
    }
}

void linkedListTraversal(struct Node * ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(9);
    enqueue(14);
    enqueue(10);
    
    dequeue();
    dequeue();
    
    linkedListTraversal(f);
    return 0;
}