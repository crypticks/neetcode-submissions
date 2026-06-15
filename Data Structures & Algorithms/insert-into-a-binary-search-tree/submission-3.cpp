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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode *copy = root;
        while(copy)
        {
            if(val <= copy->val) 
            {
                if(copy->left) copy = copy->left;
                else
                {
                    copy->left = new TreeNode(val);
                    break;
                }
            }
            else 
            {
                if(copy->right) copy = copy->right;
                else
                {
                    copy->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root; 
    }
};