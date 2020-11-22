#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &num)
{
    int size = num.size();
    sort(num.begin(), num.end());
    vector<vector<int>> result;

    for (int i = 0; i < size; i++)
    {
        if (num[i] > 0)
        {
            break;
        }
        if (i > 0 && num[i] == num[i - 1])
        {
            continue;
        }
        int head = i + 1;
        int end = size - 1;

        while (head < end)
        {
            int sum = num[i] + num[head] + num[end];

            if (sum > 0)
            {
                end--;
            }
            else if (sum < 0)
            {
                head++;
            }
            else
            {
                vector<int> temp;
                temp.push_back(num[i]);
                temp.push_back(num[head]);
                temp.push_back(num[end]);
                result.push_back(temp);

                while (head + 1 < end && num[head + 1] == num[head])
                {
                    head++;
                }

                while (end - 1 > head && num[end - 1] == num[end])
                {
                    end--;
                }

                head++;
                end--;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> in = {-1, 0, 1, 2, -1, 4};
    vector<vector<int>> result;

    result = threeSum(in);

    int size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << "output result is : ";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << std::endl;
    }
    return 0;
}