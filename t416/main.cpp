/*
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;
        bool dp[10005] = {0};

        dp[0] = true;

        for (int i = 0; i < nums.size(); i++)
        {
            int k = nums[i];
            for (int j = target; j >= k; j--)
            {
                dp[j] |= dp[j - k];
            }
        }
        return dp[target];
    }
};

int main()
{

    vector<int> target = {1, 2, 5};
    Solution s1;
    bool ans = s1.canPartition(target);
    cout << ans << endl;
    getchar();
    return 0;
}