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
class BSTIterator {
    vector<int> v;
    int start = 0;

    void build(TreeNode* n)
    {
        if(!n) return;
        build(n->left);
        v.push_back(n->val);
        build(n->right);
    }
public:
    BSTIterator(TreeNode* root) {
        build(root);
    }
    
    int next() {
        return v[start++];
    }
    
    bool hasNext() {
        return start != v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */