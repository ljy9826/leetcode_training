/*
请你来实现一个 atoi 函数，使其能将字符串转换成整数。
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
    int myAtoi(string str)
    {
        long long _INT_MAX = ((long long)1 << 31) - 1;
        long long _INT_MIN = ((long long)1 << 31);
        long long ans = 0;
        int zflag = 1; //正负
        int i = 0;
        while (str[i] == ' ')
            i++;
        if (i == str.length())
            return 0;
        if (str[i] == '+')
        {
            zflag = 1;
            i++;
        }

        else if (str[i] == '-')
        {
            zflag = 0;
            i++;
        }
        if (str[i] <= '9' && str[i] >= '0')
        {
            for (; i < str.length(); i++)
            {
                if (str[i] <= '9' && str[i] >= '0')
                {
                    ans = ans * 10 + (str[i] - '0');
                    if (zflag == 1 && ans > _INT_MAX)
                        return _INT_MAX;
                    else if (zflag == 0 && ans > _INT_MIN)
                        return _INT_MIN;
                }
                else
                    break;
            }
        }
        else
            return 0;
        if (zflag == 0)
            ans *= -1;
        return ans;
    }
};

int main()
{
    string target = "   -42";
    Solution s1;
    int ans = s1.myAtoi(target);
    cout << ans << endl;
    getchar();
    return 0;
}