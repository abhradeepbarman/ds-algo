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


void bubbleSort(int arr[], int n)
{
    int swapped = 0;

    // for (n-1) passes
    for(int i=1; i<=n-1; i++) {

        // for swapping elements
        for(int j=0; j<n-i; j++) {

            if(arr[j] > arr[j+1]) {

                // swapping
                swap(arr, j, j+1);

                swapped++;
            }

        }

        if(swapped == 0) {
            printf("Already sorted!\n");
            break;
        }
    }
}

int main()
{
    int arr[] = {1, 3, 4, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    // printing the array before sorting
    printArray(arr, n);
    
    // sorting
    bubbleSort(arr, n);

    // printing the array after sorting
    printArray(arr, n);

    return 0;
}