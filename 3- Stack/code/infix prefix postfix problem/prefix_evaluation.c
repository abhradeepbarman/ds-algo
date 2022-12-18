#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    int *ch;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack overflow");
    }
    else
    {
        s->top++;
        s->ch[s->top] = value;
    }
}

void pop(struct stack *s)
{
    if(isEmpty(s)) {
        printf("stack underflow");
    } else {
        s->top--;
    }

}

int prefix(char exp[])
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->ch = (int *)malloc(s->size * sizeof(int));

    for (int i = strlen(exp) - 1; i >= 0; i--)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            push(s, exp[i] - '0');
        }
        else
        {
            int op1 = s->ch[s->top];
            pop(s);
            int op2 = s->ch[s->top];
            pop(s);

            switch (exp[i])
            {
            case '+':
                push(s, op1 + op2);
                break;
            case '-':
                push(s, op1 - op2);
                break;
            case '*':
                push(s, op1 * op2);
                break;
            case '/':
                push(s, op1 / op2);
                break;
            }
        }
    }

    return s->ch[s->top];
}

int main()
{
    char exp[] = "-5/63";

    printf("prefix evaluation: %d", prefix(exp));

    return 0;
}