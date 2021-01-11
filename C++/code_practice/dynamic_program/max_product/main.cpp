// C++ program to print largest contiguous array sum
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(int a[], int size)
{
    vector<int> maxF(size), minF(size);
    for (int i = 1; i < size; ++i)
    {
        maxF[i] = max(maxF[i - 1] * a[i], max(a[i], minF[i - 1] * a[i]));
        minF[i] = min(minF[i - 1] * a[i], min(a[i], maxF[i - 1] * a[i]));
    }
    return *max_element(maxF.begin(), maxF.end());
}

/*Driver program to test maxProduct*/
int main()
{
    int a[] = {1, -2, -3, 0, 7, -8, -2 };
    int n = sizeof(a) / sizeof(a[0]);
    int max_product = maxProduct(a, n);
    cout << "Maximum contiguous product is " << max_product;
    return 0;
}