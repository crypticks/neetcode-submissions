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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return (1 + max(maxDepth(root->left), maxDepth(root->right)));
    }
    int helper(TreeNode *root, int depth)
    {
        if (!root) return 0;
        int leftdepth = maxDepth(root->left);
        int rightdepth = maxDepth(root->right);
        int currmax = max(depth + leftdepth, depth + rightdepth);
        currmax = max(currmax, leftdepth + rightdepth);
        int left = helper(root->left, depth + 1);
        int right = helper(root->right, depth + 1);
        int temp = max(currmax, left);
        return max(temp, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root, 0);
    }
};
