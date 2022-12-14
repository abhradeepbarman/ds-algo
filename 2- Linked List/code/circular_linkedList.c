#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void traversal(struct Node * head)
{
    struct Node *p = head;

    // --- Approach 1 ---
    // while(p->next != head)
    // {
    //     printf("%d ", p->data);
    //     p = p->next;
    // }
    // printf("%d ", p->data);


    // Approach 2 :
    do {
        printf("%d ", p->data);
        p = p->next;
    } while(p != head);
}


struct Node * insertAtFirst(struct Node * head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));

    struct Node *p =head->next;

    while(p->next != head){
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list

    p->next = ptr;
    ptr->next = head;
    ptr->data = data;
    head = ptr;
    return head;
}


struct Node * insertAtLast(struct Node * head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));

    struct Node *p =head->next;

    while(p->next != head){
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list

    ptr->next = head;
    p->next = ptr;
    ptr->data = data;
    return head;
}


struct Node * insertAtIndex(struct Node * head, int index, int data)
{
    struct Node *p = head;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    for(int i=0; i<index-1; i++)
    {
        p = p->next;
    }

    ptr->next = p->next;
    p->next = ptr;
    return head;
}



int main()
{
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 11;
    third->next = fourth;

    fourth->data = 22;
    fourth->next = head;

    head = insertAtFirst(head, 5);
    head = insertAtFirst(head, 5);
    head = insertAtFirst(head, 5);
    traversal(head);

    return 0;
}