#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

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
    // Allocate memory for Nodes in Heap
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    // Link first & second nodes
    head->data = 7;
    head->next = second;

    // Link sceond & third nodes
    second->data = 11;
    second->next = third;

    // terminate the list at the third Node
    third->data = 9;
    third->next = NULL;

    traversal(head);

    return 0;
}