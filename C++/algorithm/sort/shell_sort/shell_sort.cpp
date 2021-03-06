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
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            for (int j = i; j > gap - 1; j -= gap)
            {
                if (arr[j] < arr[j - gap])
                {
                    swap(arr[j], arr[j - gap]);
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {12, 34, 54, 2, 3, 4, 56, 78};
    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("sorted arr is : %d\n", arr[i]);
    }
    return 0;
}
