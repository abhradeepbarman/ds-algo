#include<stdio.h>

int binarySearch(int arr[], int size, int element)
{
    int s=0;
    int e=size-1;

    while(s<=e)
    {
        int mid = s+(e-s)/2;

        if(element == arr[mid])
            return 1;
        else if(element < arr[mid])
            e = mid-1;
        else
            s = mid+1;
        
    }
    return 0;
}

int main()
{
    int arr[] = {1, 3, 5, 9, 14, 20};
    int size = sizeof(arr)/sizeof(int);

    int n = binarySearch(arr, size, 5);

    if(n == 1)
        printf("element is present");
    else
        printf("element is absent");

    return 0;
}