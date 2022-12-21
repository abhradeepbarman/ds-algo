#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *ch;
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

void push(struct stack *s, char bracket)
{

    if (isFull(s))
    {
        printf("stack overflow.");
    }
    else
    {
        s->top++;
        s->ch[s->top] = bracket;
    }
}

void pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("stack underflow");
    }
    else
    {
        s->top--;
    }
}

int paranthesisMatching(char *arr, struct stack *s)
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == '(')
        {
            push(s, '(');
        }
        if (arr[i] == ')')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            else
            {
                pop(s);
            }
        }
    }

    if (isEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // creating the stack
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->ch = (char *)malloc(s->size * sizeof(char));

    // Expression
    char arr[] = "7-(8(3*9)+11+12))-8)";

    // Paranthesis checking
    if(paranthesisMatching(arr, s)) {
        printf("Balanced expression");
    } else {
        printf("unbalanced expression");
    }


    return 0;
}