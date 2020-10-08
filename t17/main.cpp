/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.empty())
        {
            return ans;
        }
        string now;
        dfs(ans, digits, 0, now);
        return ans;
    }

private:
    string Map[10] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(vector<string> &ans, const string &digits, int dep, string &now)
    {
        if (dep == digits.length())
        {
            ans.push_back(now);
            return;
        }
        int k = digits[dep] - '2';
        for (int i = 0; i < Map[k].length(); i++)
        {
            now.push_back(Map[k][i]);
            dfs(ans, digits, dep + 1, now);
            now.pop_back();
        }
    }
};

int main()
{
    string target = "23";
    Solution s1;
    vector<string> ans = s1.letterCombinations(target);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    getchar();
    return 0;
}