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
    string buildPath(vector<int>& p)
    {
        stringstream ss;
        for(int i : p)
            ss << i << "->";
        return ss.str().substr(0, ss.str().length() - 2);
    }

    void dfs(TreeNode* n, vector<string>& v, vector<int>& p)
    {
        if(!n) return;

        p.push_back(n->val);
        if(n->left == NULL && n->right == NULL)
            v.push_back(buildPath(p));
        
        dfs(n->right, v, p);
        dfs(n->left, v, p);
        p.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> paths;
        dfs(root, res, paths);
        return res;
    }
};