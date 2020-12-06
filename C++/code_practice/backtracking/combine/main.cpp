// CPP program to find all combine by backtracking.
#include <bits/stdc++.h>
using namespace std;

void combineUtils(int n, int k, int index, vector<vector<int>> &res, vector<int> &track)
{
    if (track.size() == k)
    {
        res.push_back(track);
        return;
    }

    for (int i = index; i <= n; i++)
    {
        track.push_back(i);
        combineUtils(n, k, i + 1, res, track);
        track.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> track;
    combineUtils(n, k, 1, res, track);
    return res;
}

// Driver Code.
int main()
{
    int n = 4;
    int k = 2;
    vector<vector<int>> res = combine(n, k);

    // Print result
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}