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

void insertionSort(int arr[], int n) 
{
    int swapped = 0;
    for(int i=1; i<=n-1; i++) {

        for(int j=i; j>=1; j--) {

            if(arr[j-1] > arr[j]) {

                // swapping
                swap(arr, j, j-1);

                swapped++;
            } 

            if(swapped == 0) 
                break;
        }
    }   

    if(swapped == 0) 
        printf("Already sorted!\n"); 
}

int main()
{
    int arr[] = {1, 3, 4, 7, 12};
    int n = sizeof(arr) / sizeof(int);

    // printing the array before sorting
    printArray(arr, n);
    
    // sorting
    insertionSort(arr, n);

    // printing the array after sorting
    printArray(arr, n);

    return 0;
}