/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
/*
1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
L  E  E  T  C  O  D  E  I  S  H  I  R  I  N  G

L   C   I   R
E T O E S I I G
E   D   H   N

L     D     R
E   O E   I I
E C   I H   N
T     S     G
*/
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        string ans;
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j + i < s.length(); j += cycleLen)
            {
                ans += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < s.length())
                    ans += s[j + cycleLen - i];
            }
        }
        return ans;
    }
};

int main()
{
    string target = "LEETCODEISHIRING";
    int numRows = 3;
    Solution s1;
    string ans = s1.convert(target, numRows);
    cout << ans << endl;
    getchar();
    return 0;
}