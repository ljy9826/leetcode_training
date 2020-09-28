/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mhash;
        int ans = 0, len = 0;
        int p = 0, q = 0;

        while (q < s.length())
        {
            char kchar = s[q];
            if (mhash.find(kchar) != mhash.end() && mhash[kchar] >= p)
            {
                p = mhash[kchar] + 1;
                len = q - p;
            }
            mhash[kchar] = q;
            len++;
            ans = max(ans, len);
            q++;
        }
        return ans;
    }
};

int main()
{
    string target = "pwwkew";
    Solution s1;
    int ans = s1.lengthOfLongestSubstring(target);
    cout << ans << endl;
    getchar();
    return 0;
}