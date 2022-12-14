#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *arr, int tSize, int uSize)
{
    arr->total_size = tSize;
    arr->used_size = uSize;
    arr->ptr = (int *)malloc(tSize*sizeof(int));
}

void setValues(struct myArray *arr)
{
    for(int i=0; i<arr->used_size; i++){
        printf("Enter value at index %d: ", i);
        scanf("%d", &arr->ptr[i]);
    }
}

void display(struct myArray *arr)
{
    for(int i=0; i<arr->used_size; i++){
        printf("%d ", arr->ptr[i]);
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 5);

    printf("Enter elements of array: \n");
    setValues(&marks);

    printf("Display the elments of array: ");
    display(&marks);

    return 0;
}