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
    void findRows(TreeNode * n, vector<int>& r, int d)
    {
        if(r.size() <= d) r.push_back(n->val);
        if(r[d] < n->val) r[d] = n->val;

        if(n->left != NULL)
            findRows(n->left, r, d+1);
        if(n->right != NULL)
            findRows(n->right, r, d+1);
    }

    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return vector<int>();

        vector<int> rows;
        findRows(root, rows, 0);

        return rows;
    }
};