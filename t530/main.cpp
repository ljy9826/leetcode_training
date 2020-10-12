/*
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        int ans = INT_MAX, prev = -1;
        dfs(root, ans, prev);
        return ans;
    }

private:
    void dfs(TreeNode *root, int &ans, int &prev)
    {
        if (root == nullptr)
            return;
        dfs(root->left, ans, prev);
        if (prev != -1)
        {
            int k = abs(root->val - prev);
            if (ans > k)
            {
                ans = k;
            }
        }
        prev = root->val;
        dfs(root->right, ans, prev);
    }
};

int main()
{

    vector<int> target = {1, 2, 5};
    Solution s1;
    bool ans = s1.canPartition(target);
    cout << ans << endl;
    getchar();
    return 0;
}