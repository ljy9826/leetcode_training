/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int x_cp = x;
        long long rev = 0;
        while (x != 0)
        {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        // cout << rev << ' ' << x << endl;
        return x_cp == rev;
    }
};

int main()
{
    int target = 121;
    Solution s1;
    bool ans = s1.isPalindrome(target);
    cout << ans << endl;
    getchar();
    return 0;
}