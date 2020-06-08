#include <iostream>
#include <cstdio>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("n is : %d\n", n);
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("selection sort result is : %d\n", arr[i]);
    }
    return 0;
}
