// CPP program to find all combine by backtracking.
#include <bits/stdc++.h>
using namespace std;

int houseRob(int nums[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

// Driver Code.
int main()
{
    int nums[] = {5, 3, 4, 11, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << "Maximum loot possible : "
         << houseRob(nums, n);

    return 0;
}