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
    int sum = 0;
    int dfs(vector<TreeNode*>& v)
    {
        if(v.size() == 0) return sum;

        TreeNode* curr = v.back();
        if(curr->left == NULL && curr->right == NULL)
        {
            string s = "";
            for(int i = 0; i < v.size(); i++)
            {
                s = s + to_string(v[i]->val);
            }
            sum += atoi(s.c_str());
        }
        if (curr->left != NULL)
        {
            v.push_back(curr->left);
            dfs(v);
            v.pop_back();
        } 
        if(curr->right != NULL)
        {
            v.push_back(curr->right);
            dfs(v);
            v.pop_back();
        }

        return sum;
    }

    int sumNumbers(TreeNode* root) {
        vector<TreeNode*> v;
        v.push_back(root);
        return dfs(v); 
    }
};