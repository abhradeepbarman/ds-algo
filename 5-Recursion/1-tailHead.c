#include<stdio.h>

void counting(int n)
{
    // Base case
    if(n == 0) {
        return;
    }

    // processing
    printf("%d ", n);

    // recursive call
    counting(n-1);
}

int main()
{
    counting(5);

    return 0;
}