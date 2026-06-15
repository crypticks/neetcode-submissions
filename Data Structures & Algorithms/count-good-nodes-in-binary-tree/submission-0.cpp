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
    int helper(TreeNode* root, int maxsofar)
    {
        if(!root) return 0;
        return (maxsofar <= root->val?1:0) + helper(root->left, max(maxsofar, root->val))
                                        + helper(root->right, max(maxsofar, root->val));

    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return 1 + helper(root->right, root->val) + helper(root->left, root->val);
        
    }
};
