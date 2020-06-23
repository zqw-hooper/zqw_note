#include <cstdio>

void merge(int arr[], int left, int right, int right_bound)
{
    int mid = right - 1;
    int temp_arr[right_bound - left + 1];
    for (int m = 0; m < (right_bound - left + 1); m++)
    {
        temp_arr[m] = arr[m];
    }

    int i = left;
    int j = right;
    int k = 0;
    while (i <= mid && j <= right_bound)
    {
        if (temp_arr[i] <= temp_arr[j])
        {
            arr[k] = temp_arr[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = temp_arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        arr[k] = temp_arr[i];
        k++;
        i++;
    }

    while (j <= right_bound)
    {
        arr[k] = temp_arr[j];
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
