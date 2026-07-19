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
    TreeNode* convertBST(TreeNode* root) {
        int x = sum(root, 0);
        return root;
    }
    int sum(TreeNode* root, int abovesum)
    {
        if(!root) return 0;
        int rightsum = sum(root->right, abovesum);
        int leftsum = sum(root->left, abovesum + root->val + rightsum);
        int res = root->val + leftsum + rightsum;
        root->val += rightsum + abovesum;
        return res;
    }
};