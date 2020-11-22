#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int minCoins(vector<int> &coins, int size, int value)
{
    if (coins.empty())
    {
        return -1;
    }

    if (coins.size() == 1 && (value % coins[0] != 0))
    {
        return -1;
    }

    int dp[value + 1];
    for (int i = 1; i <= value; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    for (int i = 1; i <= value; i++)
    {
        for (int j = 0; j < size; j++)
            if (coins[j] <= i)
            {
                int temp = dp[i - coins[j]];
                if (temp != INT_MAX && temp + 1 < dp[i])
                {
                    dp[i] = temp + 1;
                }
            }
    }

    for(int i = 0; i < sizeof(dp)/sizeof(int); i++)
    {
        std::cout << "dp table value " << i << " is : " << dp[i] << std::endl;
    }

    return dp[value];
}

int main()
{
#if 1
    vector<int> coins = {1, 5, 2};
    int size = sizeof(coins) / sizeof(int);
    int val = 7;

    cout << "The min numbers coins make " << val << " is : " << minCoins(coins, size, val) << endl;
#elif 0
    vector<int> coins = {2};
    int size = sizeof(coins) / sizeof(int);
    int val = 3;

    cout << "The min numbers coins make " << val << " is : " << minCoins(coins, size, val) << endl;
#endif
    return 0;
}