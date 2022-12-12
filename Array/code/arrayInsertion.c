#include<stdio.h>

void indInsertion(int arr[], int size, int index, int element){
    for(int i=size-1; i>=index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
}

void display(int arr[], int size){
    for(int i=0; i<size+1; i++){
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[10] = {1, 5, 8, 9, 13};
    int size = 5;

    indInsertion(arr, size, 2, 6);
    printf("\nAfter insertion: ");
    display(arr, size);

    return 0;
}