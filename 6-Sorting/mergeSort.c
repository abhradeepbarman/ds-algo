#include <stdio.h>

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int *arr, int low, int mid, int high)
{
    int c[50];

    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            c[k++] = arr[i++];
        }
        else
        {
            c[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        c[k++] = arr[i++];
    }

    while (j <= high)
    {
        c[k++] = arr[j++];
    }

    // copying c to arr
    for (int i = low; i <= high; i++)
    {
        arr[i] = c[i];
    }
}

// Time complexity --> O(nlogn)
// space complexity --> O(n)

void mergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {6, 3, 9, 5, 2, 8};
    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n - 1);
    display(arr, n);

    return 0;
}