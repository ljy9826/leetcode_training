/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                int k = nums[i] + nums[j];
                // if (k > target)
                //     break;
                if (j > (i + 1) && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1, r = n - 1;
                while (l < r)
                {
                    int sum = k + nums[l] + nums[r];
                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while ((l < r) && (nums[l] == nums[l - 1]))
                            l++;
                        while ((l < r) && (nums[r] == nums[r + 1]))
                            r--;
                    }
                    else if (sum > target)
                        r--;
                    else
                        l++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> target = {1, -2, -5, -4, -3, 3, 3, 5};
    int a = -11;
    Solution s1;
    vector<vector<int>> ans = s1.fourSum(target, a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << endl;
    }
    // cout << ans << endl;
    getchar();
    return 0;
}