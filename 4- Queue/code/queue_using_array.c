#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *q) {
    if(q->rear == q->size-1) {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q) {
    if(q->front == q->rear) {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int value) {
    if(isFull(q)) {
        printf("Queue overflow.");
    } else {
        q->rear++;
        q->arr[q->rear] = value;
    }
}

void dequeue(struct queue *q) {
    if(isEmpty(q)) {
        printf("Queue underflow.");
    } else {
        q->front++;
    }
}

void traversal(struct queue *q) {
    for(int i = q->front+1; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
}

int main()
{
    struct queue *q = (struct queue *) malloc(sizeof(struct queue));
    q->size = 10;
    q->front = q->rear = -1;
    q->arr = (int *) malloc(q->size * sizeof(int));

    enqueue(q, 7);
    enqueue(q, 14);
    enqueue(q, 21);

    dequeue(q);
    enqueue(q, 28);

    traversal(q);

    return 0;
}