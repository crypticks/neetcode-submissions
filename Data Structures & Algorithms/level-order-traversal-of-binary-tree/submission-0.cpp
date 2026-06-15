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
private:
    int depth(TreeNode* root)
    {
        if(!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }

    void helper(TreeNode* root, vector<vector<int>>& res, int depth)
    {
        if(!root) return;
        res[depth].push_back(root->val);
        helper(root->left, res, depth + 1);
        helper(root->right, res, depth + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res(depth(root));
        helper(root, res, 0);
        return res;
        
    }
};
