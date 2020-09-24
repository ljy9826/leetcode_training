/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long long MAX_VALUE = (((long long)1 << 31) - 1);
        long long MIN_VALUE = -(((long long)1 << 31) - 1);
        long long ans = 0;
        while (x != 0)
        {
            int k = x % 10;
            x /= 10;
            ans = ans * 10 + k;
        }
        // cout << ans << endl;
        // cout << MAX_VALUE << endl;
        if (ans >= MAX_VALUE || ans <= MIN_VALUE)
            ans = 0;
        return (int)ans;
    }
};

int main()
{
    int target = -1236469;
    Solution s1;
    int ans = s1.reverse(target);
    cout << ans << endl;
    getchar();
    return 0;
}