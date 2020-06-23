#include <cstdio>

void countSort(int arr[], int n)
{
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        while (count[i] > 0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {9, 9, 8, 8, 7, 7, 6, 6, 5, 5, 4, 4, 4, 3, 3, 3, 2, 2, 2, 1, 1, 1, 9, 9, 8, 8, 7, 7, 6, 6, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    countSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("sorted arr is : %d\n", arr[i]);
    }
    return 0;
}
