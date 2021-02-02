#include <cstdio>
#include <iostream>

void merge(int arr[], int left, int right, int right_bound)
{
    int n1 = right - left;
    int n2 = right_bound - right + 1;

    int L[n1];    
    int R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[right + j];

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = R[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = L[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m + 1, r);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {3, 1, 5, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int l = 0;
    int r = n - 1;
    mergeSort(arr, l, r);
    for (int i = 0; i < n; i++)
    {
        printf("sorted array is : %d\n", arr[i]);
    }
    return 0;
}
