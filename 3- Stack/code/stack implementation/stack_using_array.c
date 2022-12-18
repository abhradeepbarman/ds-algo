#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

// check if Array is empty or not
int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}


// check if array is full or not
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}



int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    struct stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // pushing element manually
    // s->arr[0] = 7;
    // s->top++;


    // check if stack is empty
    if(isEmpty(s)){
        printf("Stack is Empty!!!");
    }
    else {
        printf("Stack is not empty.");
    }

    return 0;
}