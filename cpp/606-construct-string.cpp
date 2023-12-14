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
    string build(TreeNode* n, string& s)
    {
        s += to_string(n->val);
        if(n->left != NULL)
        {
            s += "(";
            build(n->left, s);
            s += ")";
        }
        else if (n->left == NULL && n->right != NULL)
            s += "()";
        if(n->right != NULL)
        {
            s += "(";
            build(n->right, s);
            s += ")";
        }
        
        return s;
    }

    string tree2str(TreeNode* root) {
        string s;
        build(root, s);
        return s;
    }
};