/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
int f[1005][1005] = {0};
class Solution
{
public:
    string longestPalindrome(string s)
    {
        
        string ans;
        for (int l = 0; l < s.size(); l++)
        {
            for (int i = 0; i + l < s.size(); i++)
            {
                int j = i + l;
                if (l <= 1)
                {
                    f[i][j] = (s[i] == s[j]);
                }
                else
                {
                    f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
                }
                if (f[i][j] && l + 1 > ans.length())
                {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};

int main()
{
    string target = "babad";
    Solution s1;
    string ans = s1.longestPalindrome(target);
    cout << ans << endl;
    getchar();
    return 0;
}