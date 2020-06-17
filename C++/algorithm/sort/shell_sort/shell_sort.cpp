#include <iostream>
#include <cstdio>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void shellSort(int arr[], int n)
{
    for (int gap = 2; gap > 0; gap--)
    {
        for (int j = gap; j < n; j++)
        {
            int temp = arr[j];
            if (arr[j] < arr[j - gap])
            {
                swap(arr[j], arr[j - gap]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {5, 3, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("sorted arr is : %d\n", arr[i]);
    }

    return 0;
}
