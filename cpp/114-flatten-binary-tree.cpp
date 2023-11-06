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
    void dfs(TreeNode* n, TreeNode* l)
    {
        if(!n) return;
        l->right = new TreeNode(n->val);

        dfs(n->left, l->right);
        while(l->right != NULL) l = l->right;
        dfs(n->right, l);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* list = new TreeNode(root->val);
        dfs(root, list);
        list = list->right;
        while(list->right != NULL)
        {
            root->right = list->right;
            root->left = NULL;
            list = list->right;
            root = root->right;
        }
    }
};