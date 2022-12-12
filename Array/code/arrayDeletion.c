#include<stdio.h>

void display(int arr[], int size)
{
    for(int i=0; i<size-1; i++){
        printf("%d ", arr[i]);
    }
}

void indDeletion(int arr[], int size, int index)
{
    for(int i=index; i<size-1; i++){
        arr[i] = arr[i+1];
    }
}


int main()
{
    int arr[10] = {1, 5, 8, 9, 13, 15};
    int size = 6;

    printf("After deletion: ");
    indDeletion(arr, size, 2);
    display(arr, size);

    return 0;
}