#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Node *ptr)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));

    if (n == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node * push(struct Node *top, int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));

    if (isFull(n))
    {
        printf("Stack Overflow");
    }
    else
    {
        n->data = value;
        n->next = top;
        top = n;
    }
    return top;
}

struct Node * pop(struct Node * top)
{
    if(isEmpty(top)) {
        printf("Stack Underflow");
    }
    else {
        struct Node *n = top;
        top = top->next;
        free(n);
    }
    return top;
}

void peek(struct Node *top, int pos) 
{
    struct Node *ptr = top;

    for(int i=0; (i<pos-1 && ptr != NULL); i++) {
        ptr = ptr->next;
    }

    if(ptr != NULL) {
        printf("\nelement at position %d = %d", pos, ptr->data);
    } else {
        printf("\ninvalid position!!!");
    }
    
}

void stackTop (struct Node * top)
{
    printf("\nstackTop = %d", top->data);
}

void stackBottom(struct Node *ptr)
{
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    printf("\nstackBottom = %d", ptr->data);
}

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *top = NULL;

    top = push(top, 6);
    top = push(top, 9);
    top = push(top, 2);
    
    top = pop(top);
    top = push(top, 12);

    traversal(top);
    
    peek(top, 2);

    stackTop(top);
    stackBottom(top);

    return 0;
}