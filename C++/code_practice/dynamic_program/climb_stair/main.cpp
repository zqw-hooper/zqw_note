#include <iostream>

#if 0 // dynamic program method
int climbStairs(int n)
{
    if (n <= 2)
    {
        return n;
    }

    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = -1;
    }

    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
#elif 0 // dynamic program method
int climbStairs(int n)
{
    if (n <= 2)
    {
        return n;
    }

    int current;
    int prev = 1;
    int prev_prev = 1;
    int temp;
    for (int i = 2; i < n + 1; i++)
    {
        current = prev + prev_prev;
        prev_prev = prev;
        prev = current;
    }

    return current;
}
#elif 1 //  Fibonacci numbers
int climbStairs(int n)
{
    if (n <= 2)
    {
        return n;
    }

    return climbStairs(n - 1) + climbStairs(n - 2);
}
#endif

int main()
{
    std::cout << climbStairs(5) << std::endl;
    return 0;
}