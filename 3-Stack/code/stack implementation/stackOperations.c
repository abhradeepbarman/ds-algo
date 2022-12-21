#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    return 0;
}

void push(struct stack *s, int value)
{
    if(isFull(s)){
        printf("Stack Overflow.");
    }
    else {
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop(struct stack *s)
{
    if(isEmpty(s)){
        printf("Stack Underflow.");
        return -1;
    }
    else {
        int value = s->arr[s->top];
        s->top--;
        return value;
    }
}

void peek(struct stack *s, int i) 
{
    int arrayIndex = s->top-i+1;
    if(arrayIndex < 0) {
        printf("\nnot a valid position");
    }
    else {
        printf("\nElement at position %d = %d", i, s->arr[arrayIndex]);
    }
}

int stackTop(struct stack *s) {
    return s->arr[s->top];
}

int stackBottom(struct stack *s) {
    return s->arr[0];
}

void traversal(struct stack *s)
{
    for(int i=0; i<=s->top; i++){
        printf("%d ", s->arr[i]);
    }
}


int main()
{   
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // push & pop
    push(s, 5);
    push(s, 7);
    push(s, 2);
    push(s, 9);
    pop(s);
    push(s, 14);

    // traversal
    traversal(s);

    // peek --> value at position
    peek(s, 3);

    // stackTop & stackBottom
    printf("\nstackTop = %d", stackTop(s));
    printf("\nstackBottom = %d", stackBottom(s));


    return 0;
}