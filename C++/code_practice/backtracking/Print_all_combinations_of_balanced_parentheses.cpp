// C program to Print all combinations 
// of balanced parentheses
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

void backtracking(vector<string> &result, string &cur, int n, int open, int close)
{
    if (cur.size() == 2 * n)
    {
        result.push_back(cur);
        return;
    }
    if (open < n)
    {
        cur.push_back('(');
        backtracking(result, cur, n, open + 1, close);
        cur.pop_back();
    }
    if (close < open)
    {
        cur.push_back(')');
        backtracking(result, cur, n, open, close + 1);
        cur.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;
    string s;
    backtracking(result, s, n, 0, 0);
    return result;
}
