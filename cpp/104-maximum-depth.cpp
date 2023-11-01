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
    int mx=0;
public:
    void depth(TreeNode* root, int d)
    {
        if(!root) return;

        if(d > mx) mx = d;
        if(root->right != NULL) depth(root->right, d+1);
        if(root->left != NULL) depth(root->left, d+1);
    }
    int maxDepth(TreeNode* root) {
        depth(root, 1);
        return mx;
    }
};