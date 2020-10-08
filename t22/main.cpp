/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
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
    vector<string> generateParenthesis(int n)
    {

    }

private:
    void dfs(vector<string>& ans,int dep,int p,int q)
};

int main()
{
    int n = 3;
    vector<string> ans;
    Solution s1;
    ans = s1.generateParenthesis(n);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    getchar();
    return 0;
}