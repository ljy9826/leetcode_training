/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        if (n == 0)
        {
            return "";
        }
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        string s2 = strs[n - 1];
        string ans;
        for (int i = 0; i < min(s1.length(), s2.length()); i++)
        {
            if (s1[i] == s2[i])
                ans += s1[i];
            else
                break;
        }
        return ans;
    }
};

int main()
{
    vector<string> target;
    Solution s1;
    string ans = s1.longestCommonPrefix(target);
    cout << ans << endl;
    getchar();
    return 0;
}