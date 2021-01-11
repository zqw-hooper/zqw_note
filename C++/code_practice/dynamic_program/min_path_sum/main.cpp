#include <bits/stdc++.h> 
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    if (0 == grid.size() || 0 == grid[0].size())
    {
        return 0;
    }
    int rows = grid.size();
    int cols = grid[0].size();
    int dp[rows][cols];
    memset(dp, 0, rows * cols);
    dp[0][0] = grid[0][0];
    for (int i = 1; i < rows; i++)
    {
        dp[i][0] = grid[i][0] + dp[i - 1][0];
    }

    for (int i = 1; i < cols; i++)
    {
        dp[0][i] = grid[0][i] + dp[0][i - 1];
    }

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[rows - 1][cols - 1];
}

int main()
{
    vector<vector<int>> cost = {{1, 2, 7},
                                {4, 8, 2},
                                {1, 5, 3}};
    cout << minPathSum(cost) << endl;
    return 0;
}