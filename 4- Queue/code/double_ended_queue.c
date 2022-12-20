#include<stdio.h>
#include<stdlib.h>

struct dequeue {
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct dequeue *q) {
    if(q->r == q->size -1) {
        return 1;
    }
    return 0;
}

int isEmpty(struct dequeue *q) {
    if(q->f == q->r) {
        return 1;
    }
    return 0;
}

void insertRear(struct dequeue *q, int value) {
    if(isFull(q)) {
        printf("Queue overflow");
    } else {
        q->r++;
        q->arr[q->r] = value;
    }
}

void deleteRear(struct dequeue *q) {
    if(isEmpty(q)) {
        printf("Queue underflow");
    } else {
        q->r--;
    }
}


void insertFront(struct dequeue *q, int value) {
    if(q->f == -1) {
        printf("Queue overflow");
    } else {
        q->arr[q->f] = value;
        q->f--;
    }
}

void deleteFront(struct dequeue *q) {
    if(isEmpty(q)) {
        printf("Queue underflow");
    } else {
        q->f++;
    }
}

void getFirst(struct dequeue *q) {
    if(q->f == q->size-1) {
        printf("\nno element");
    } else {
        printf("\nfirst element = %d", q->arr[q->f + 1]);
    }
}

void getLast(struct dequeue *q) {
    if(q->r == -1 || q->r == q->size-1) {
        printf("\nno element");
    } else {
        printf("\nlast element = %d", q->arr[q->r]);
    }
}

void traversal(struct dequeue *q) {
    for(int i=q->f+1 ; i<=q->r; i++) {
        printf("%d ", q->arr[i]);
    }
}


int main()
{
    struct dequeue *q = (struct dequeue *) malloc(sizeof(struct dequeue));
    q->size = 10;
    q->f = -1;
    q->r = -1;
    q->arr = (int *) malloc(q->size * sizeof(int));

    insertRear(q, 2);
    insertRear(q, 9);
    insertRear(q, 4);
    insertRear(q, 6);
    insertRear(q, 5);

    deleteRear(q);

    deleteFront(q);
    deleteFront(q);

    insertFront(q, 7);


    traversal(q);
    getFirst(q);
    getLast(q);

    return 0;
}