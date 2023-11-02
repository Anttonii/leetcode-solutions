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
class Solution {
public:
    void dfs(TreeNode* n, vector<vector<int>>& v, int d)
    {
        if(!n) return;

        if(d >= v.size()) v.push_back(vector<int>{});
        v[d].push_back(n->val);

        dfs(n->left, v, d+1);
        dfs(n->right, v, d+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        v.reserve(8);
        dfs(root, v, 0);
        return v;
    }
};