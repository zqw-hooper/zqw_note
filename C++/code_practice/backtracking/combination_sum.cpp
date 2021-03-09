// 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的数字可以无限制重复被选取。

// 说明：
// 所有数字（包括 target）都是正整数。
// 解集不能包含重复的组合。 
// 示例 1：
// 输入：candidates = [2,3,6,7], target = 7,
// 所求解集为：
// [
//   [7],
//   [2,2,3]
// ]

#include <vector>
#include <algorithm>
using namespace std;

void combinationSumUtil(vector<int> candidates, int index, int target, vector<vector<int>> &res, vector<int> &backtracking)
{
    if (0 == target)
    {
        res.push_back(backtracking);
        return;
    }
    if (0 > target)
    {
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        backtracking.push_back(candidates[i]);
        combinationSumUtil(candidates, i, target - candidates[i], res, backtracking);
        backtracking.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> backtracking;
    sort(candidates.begin(), candidates.end());

    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    combinationSumUtil(candidates, 0, target, res, backtracking);
    return res;
}