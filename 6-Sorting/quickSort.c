#include <stdio.h>

void display(int *arr, int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];

    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr, i, j);
    }

    swap(arr, low, j);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main()
{
    int arr[] = {6, 3, 9, 5, 2, 8};
    int n = sizeof(arr)/sizeof(int);

    quickSort(arr, 0, n-1);
    display(arr, n);

    return 0;
}