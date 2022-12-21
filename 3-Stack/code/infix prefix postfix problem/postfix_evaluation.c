#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s) {
    if(s->top == -1) {
        return 1;
    }
    return 0;
}

int isFull(struct stack *s) {
    if(s->top == s->size-1) {
        return 1;
    }
    return 0;
}

void push(struct stack *s, int value) {
    if(isFull(s)) {
        printf("stack overflow");
    } else {
        s->top++;
        s->arr[s->top] = value;
    }
}

void pop(struct stack *s) {
    if(isEmpty(s)) {
        printf("stack underflow");
    } else {
        s->top--;
    }
}

int postfix(char exp[]) {

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    for(int i=0; exp[i] != '\0'; i++) {
        if(exp[i] >= '0' && exp[i] <= '9') {
            push(s, exp[i]-'0');
        } 
        else {
            int op2 = s->arr[s->top];
            pop(s);
            int op1 = s->arr[s->top];
            pop(s);

            switch(exp[i])
            {
                case '+' :
                    push(s, op1+op2);
                    break;
                case '-' :
                    push(s, op1-op2);
                    break;
                case '*' :
                    push(s, op1*op2);
                    break;
                case '/' :
                    push(s, op1/op2);
                    break;
            }
        }
    }

    return s->arr[s->top];
}

int main()
{
    char exp[] = "42*3+";

    printf("Postfix evaluation = %d", postfix(exp));

    return 0;
}