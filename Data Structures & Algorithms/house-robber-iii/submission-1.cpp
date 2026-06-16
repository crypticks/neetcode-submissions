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
    pair<int, int> help(TreeNode* root)
    {
        if(!root) return {0, 0};
        auto left = help(root->left);
        auto right = help(root->right);
        return {root->val + left.second + right.second, max(left.first, left.second) + max(right.first, right.second)};
        
    }
public:
    int rob(TreeNode* root) {
        auto t = help(root);
        return max(t.first, t.second);
    }
};