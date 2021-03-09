// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

// 示例 1:
// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.size() == 0)
    {
        return 0;
    }

    unordered_set<char> lookup;
    int maxStr = 0;
    int left = 0;
    for (int i = 0; i < s.size(); i++)
    {
        while (lookup.find(s[i]) != lookup.end())
        {
            lookup.erase(s[left]);
            left++;
        }
        maxStr = max(maxStr, i - left + 1);
        lookup.insert(s[i]);
    }
    return maxStr;
}

int main()
{

    return 0;
}
