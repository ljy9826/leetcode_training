/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
*/
#include <iostream>
#include <vector>
#include <map>
#include <hash_map>
#include <algorithm>
using namespace std;

//二分查找，复杂度nlogn
class Solution1
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int pos1 = -1, pos2 = -1;
        vector<int> nums_cp(nums);
        sort(nums_cp.begin(), nums_cp.end());
        for (int i = 0; i < nums_cp.size() - 1; i++)
        {
            int a = nums_cp[i];
            int b = target - a;
            if (a == b)
            {
                if (nums_cp[i + 1] != nums_cp[i])
                    continue;
                else
                {
                    for (int j = 0; j < nums.size(); j++)
                    {
                        if (pos1 == -1 && nums[j] == a)
                        {
                            pos1 = j;
                            continue;
                        }
                        if (pos1 != -1 && nums[j] == b)
                        {
                            pos2 = j;
                            break;
                        }
                    }
                    break;
                }
            }
            int k = lower_bound(nums_cp.begin(), nums_cp.end(), b) - nums_cp.begin();
            if (k < nums_cp.size() && nums_cp[k] == b)
            {
                for (int j = 0; j < nums.size(); j++)
                {
                    if (nums[j] == a)
                    {
                        pos1 = j;
                        break;
                    }
                }
                for (int j = 0; j < nums.size(); j++)
                {
                    if (nums[j] == b)
                    {
                        pos2 = j;
                        break;
                    }
                }
                break;
            }
        }
        // vector<int> ans(pos1, pos2);
        vector<int> ans = {pos1, pos2};
        return ans;
    }
};

//哈希表，复杂度n
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int pos1 = 0, pos2 = 0;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            int b = target - a;
            if (m.count(b) > 0)
            {
                pos1 = m[b];
                pos2 = i;
                break;
            }
            m[a] = i;
        }
        vector<int> ans = {pos1, pos2};
        return ans;
    }
};

int main()
{
    vector<int> nums = {3, 2, 3};
    int target = 6;
    Solution s1;
    vector<int> ans = s1.twoSum(nums, target);
    cout << ans[0] << ' ' << ans[1] << endl;
    getchar();
    return 0;
}