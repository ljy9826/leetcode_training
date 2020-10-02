/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
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
    int maxArea(vector<int> &height)
    {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        while (l < r)
        {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] > height[r])
                r--;
            else
                l++;
        }
        return ans;
    }
};

int main()
{
    vector<int> target = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s1;
    int ans = s1.maxArea(target);
    cout << ans << endl;
    getchar();
    return 0;
}