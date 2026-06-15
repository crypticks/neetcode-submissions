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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *dummy = new TreeNode(-1);
        dummy->right = root;
        TreeNode *copy = dummy;
        while(copy)
        {
            if(!copy->left && !copy->right) return root;
            if((copy->left && copy->left->val == key) || (copy->right && copy->right->val == key)) break;
            if(copy->val >= key) copy = copy->left;
            else copy = copy->right;
        }
        bool rorl = copy->left && copy->left->val == key;
        TreeNode *toDelete = (rorl)? copy->left :
                                copy->right; 
        if(!toDelete->right)(rorl?copy->left : copy->right) = toDelete->left;
        if(!toDelete->left) (rorl?copy->left : copy->right) = toDelete->right;
        if(toDelete->right && toDelete->left)
        {
            TreeNode *addpoint = toDelete->left;
            while(addpoint->right) addpoint = addpoint->right;
            addpoint->right = toDelete->right->left;
            toDelete->right->left = toDelete->left;
            (rorl?copy->left : copy->right) = toDelete->right;
        }
        return dummy->right;
        
    }
};