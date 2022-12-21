#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node * prev;
    int data;
    struct Node * next;
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
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 5;
    head->next = second;

    second->prev = head;
    second->data = 9;
    second->next = third;

    third->prev = second;
    third->data = 12;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 25;
    fourth->next = NULL;

    traversal(head);

    return 0;
}