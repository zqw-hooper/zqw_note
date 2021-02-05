#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void maxheapify(int arr[], int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if(l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if(r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        swap(&arr[largest], &arr[i]);
        maxheapify(arr, n, largest);
    }
}

int kthLargest(int arr[], int n, int k)
{
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        maxheapify(arr, n, i);
    }

    

    for(int i = n - 1; i >= k - 1; i--)
    {
        swap(&arr[i], &arr[0]);
        maxheapify(arr, i, 0);
    }

    // for(int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    return arr[n - k];
}

int main()
{
    int arr[] = { 11, 3, 2, 1, 15, 5, 4,
                           45, 88, 96, 50, 45 };

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;
    cout << kthLargest(arr,n,k) << "\n";
    return 0;
}
