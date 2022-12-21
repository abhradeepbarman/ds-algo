#include<stdio.h>
#include<stdlib.h>

struct circularQueue {
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct circularQueue *q) {
    if(q->front == q->rear) {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q) {
    if((q->rear+1)%q->size == q->front) {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int value) {
    if(isFull(q)) {
        printf("Queue overflow.\n");
    } else {
        q->rear = (q->rear+1) % q->size;
        q->arr[q->rear] = value;
        printf("Enqueue element = %d\n", value);
    }
}

void dequeue(struct circularQueue *q) {
    if(isEmpty(q)) {
        printf("Queue underflow.\n");
    } else {
        q->front = (q->front+1) % q->size;
        printf("Dequeue element = %d\n", q->arr[q->front]);
    }
}

void traversal(struct circularQueue *q) {
    for(int i=q->front+1; i != q->rear; i = (i+1) % q->size) {
        printf("%d ", q->arr[i]);
    }
    printf("%d", q->arr[q->rear]);
}

int main()
{
    struct circularQueue *q;
    q->size = 5;
    q->front = q->rear = 0;
    q->arr = (int *) malloc(q->size * sizeof(int));

    enqueue(q, 14);
    enqueue(q, 15);
    enqueue(q, 16);
    enqueue(q, 17);
    dequeue(q);
    enqueue(q, 18);

    traversal(q);

    return 0;
}