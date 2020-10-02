/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while ((l < r) && (nums[l] == nums[l - 1]))
                        l++;
                    while ((l < r) && (nums[r] == nums[r + 1]))
                        r--;
                }
                else if (sum > 0)
                    r--;
                else
                    l++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> target = {-1, 0, 1, 2, -1, -4};
    Solution s1;
    vector<vector<int>> ans = s1.threeSum(target);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl;
    }
    // cout << ans << endl;
    getchar();
    return 0;
}