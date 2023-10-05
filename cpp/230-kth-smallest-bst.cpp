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
    int kthSmallest(TreeNode* root, int k) {
        // implementation using a vector and a stack
        // time complexity o(n) space complexity o(n)
        if(root->left == NULL && root->right == NULL) return root->val;

        std::vector<int> num;
        std::stack<TreeNode*> stack;
        stack.push(root);

        while(!stack.empty()) {
            TreeNode * curr = stack.top();
            stack.pop();

            num.push_back(curr->val);
            
            if(curr->left != 0) stack.push(curr->left);
            if(curr->right != 0) stack.push(curr->right);
        }

        sort(num.begin(), num.end());
        return num[k - 1];
    }
};