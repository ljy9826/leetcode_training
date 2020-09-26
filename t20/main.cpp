/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> q;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                q.push(s[i]);
            else
            {
                if (q.size() == 0)
                    return false;
                char k = q.top();
                q.pop();
                if (s[i] == ')' && k != '(')
                    return false;
                if (s[i] == '}' && k != '{')
                    return false;
                if (s[i] == ']' && k != '[')
                    return false;
            }
        }
        if (q.size() != 0)
            return false;
        return true;
    }
};

int main()
{
    string target = "{";
    Solution s1;
    bool ans = s1.isValid(target);
    cout << ans << endl;
    getchar();
    return 0;
}