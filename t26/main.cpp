/*
给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int p = 0, q = 1;
        while (q < nums.size())
        {
            if (nums[q] != nums[p])
            {
                nums[p + 1] = nums[q];
                p++;
            }
            q++;
        }
        return p + 1;
    }
};

int main()
{
    vector<int> target = {1, 1, 2};
    Solution s1;
    int ans = s1.removeDuplicates(target);
    cout << ans << endl;
    getchar();
    return 0;
}