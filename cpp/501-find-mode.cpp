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
    void dfs(TreeNode* n, unordered_map<int, int>& m, int * mx)
    {
        m[n->val]++;
        if(m[n->val] > *mx) *mx = m[n->val]; 

        if(n->left != NULL) dfs(n->left, m, mx);
        if(n->right != NULL) dfs(n->right, m, mx);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> m;
        vector<int> res;

        int mx = 0;
        dfs(root, m, &mx);

        for(auto const& v : m)
            if(v.second == mx) res.push_back(v.first);

        return res;
    }
};