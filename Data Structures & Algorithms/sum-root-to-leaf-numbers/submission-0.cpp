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
    int dfs(TreeNode *root, int cursum){
        if(!root) return 0;
        if(!root->left && !root->right) return cursum * 10 + root->val;
        return dfs(root->left, cursum * 10 + root->val) + dfs(root->right, cursum*10 + root->val);

    }
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};