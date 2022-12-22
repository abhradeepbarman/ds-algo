#include<stdio.h>

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void selectionSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++) {
        int min = i;

        for(int j=i; j<n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        // swapping
        swap(arr, min, i);
    }
}


int main()
{
    int arr[] = {4, 3, 5, 7, 0};
    int n = sizeof(arr) / sizeof(int);

    // printing the array before sorting
    printArray(arr, n);
    
    // sorting
    selectionSort(arr, n);

    // printing the array after sorting
    printArray(arr, n);

    return 0;
}