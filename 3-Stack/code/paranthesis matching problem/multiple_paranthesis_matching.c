#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    char *ch;
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
        printf("Stack overflow.");
    } else {
        s->top++;
        s->ch[s->top] = value;
    }
}

void pop(struct stack *s) {
    if(isEmpty(s)) {
        printf("Stack undreflow");
    } else {
        s->top--;
    }
}

int match(char a, char b) {
    if(a == '{' && b == '}') {
        return 1;
    }
    if(a == '(' && b == ')') {
        return 1;
    }
    if(a == '[' && b == ']') {
        return 1;
    }
    return 0;
}

int multiParanthesisMatching(char *exp) {
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->ch = (char *) malloc(s->size * sizeof(char));


    for(int i=0; exp[i] != '\0'; i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(s, exp[i]);
        } 
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(isEmpty(s)) {
                return 0;
            }
            else {
                if(match(s->ch[s->top], exp[i])) {
                    pop(s);
                } else {
                    return 0;
                }
            }
        }
    }

    if(isEmpty(s)) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    char exp[] = "{7-(3-2)+[8+(99-11)]}";

    if(multiParanthesisMatching(exp)) {
        printf("Balanced expression");
    } else {
        printf("Unbalanced expression");
    }

    return 0;
}