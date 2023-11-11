/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    int d = INT_MAX;

public:
    void dfs(TreeNode *n, int dp)
    {
        if (!n)
            return;
        if (dp + 1 > d)
            return;
        if (n->right == NULL && n->left == NULL)
            d = min(d, dp);

        dfs(n->left, dp + 1);
        dfs(n->right, dp + 1);
    }

    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        dfs(root, 1);
        return d;
    }
};