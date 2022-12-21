#include<stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for(int i=0; i<size; i++){
        if(arr[i] == element)
            return 1;
    }
    return 0;
}

int main()
{
    int arr[] = {1, 5, 9, 14, 20};
    int size = sizeof(arr)/sizeof(int);

    int n = linearSearch(arr, size, -2);

    if(n == 1)
        printf("element is present");
    else 
        printf("element is absent");

    return 0;
}