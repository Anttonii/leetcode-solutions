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
    int avg(int sum, int n)
    {
        return (int) floor(sum / n);
    }

    pair<int, int> dfs(TreeNode* node, int * c)
    {
        // keep track of number of children and sum of children
        if(!node) return pair {0, 0};
        pair<int, int> l = dfs(node->left, c);
        pair<int, int> r = dfs(node->right, c);
        pair<int, int> res = pair {l.first + r.first + 1, node->val + l.second + r.second};
        if(avg(res.second, res.first) == node->val) (*c)++;
        return res;
    }


    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        auto c = dfs(root, &count);
        return count;
    }
};