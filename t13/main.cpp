/*
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}}; //初始化哈希表

        int ans = 0;

        for (int i = 0; i < s.size() - 1; i++)
        {
            if (m[s[i]] < m[s[i + 1]])
                ans -= m[s[i]];
            else
                ans += m[s[i]];
        }
        ans += m[s[s.size() - 1]];

        return ans;
    }
};

int main()
{
    string target = "IX";
    Solution s1;
    int ans = s1.romanToInt(target);
    cout << ans << endl;
    getchar();
    return 0;
}