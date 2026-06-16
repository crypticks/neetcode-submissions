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
    bool subtree(TreeNode* root, int target, unordered_map<TreeNode*, int>& m)
    {
        if(!root) return true;
        bool left = subtree(root->left, target, m);
        bool right = subtree(root->right, target, m);
        if(root->val == target && left && right) return true;
        else if(left) m[root]++;
        else if(right) m[root]+=2;
        return false;


    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        unordered_map<TreeNode*, int> m; // node -> deletable (1 -> left, 2 ->right, 3 -> both)
        bool f = subtree(root, target, m);
        if (f) return nullptr;
        for(auto& [node, key] : m)
        {
            if(key == 3)
            {
                node->left = nullptr;
                node->right = nullptr;
            }
            else if(key == 2)
            {
                node->right = nullptr;
            }
            else if(key == 1)
            {
                node->left = nullptr;
            }
        }
        return root;
    }
};