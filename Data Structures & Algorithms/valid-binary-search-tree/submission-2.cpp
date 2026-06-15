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
    void inorder(TreeNode* root, vector<int>& res)
    {
        if(!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> inordered;
        inorder(root, inordered);
        for(int i = 1; i < inordered.size(); i++)
        {
            if(inordered[i] <= inordered[i-1]) return false;
        }
        return true;
    }
};
