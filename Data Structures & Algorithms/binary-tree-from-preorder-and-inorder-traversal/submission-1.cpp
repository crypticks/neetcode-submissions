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
    TreeNode* build(vector<int>& preorder, int ptr, unordered_map<int, int>preorderpos,
                    vector<int>& inorder, int l, int r, unordered_map<int, int>& inorderpos)
    {
        if(l == r) return new TreeNode(inorder[l]);
        if(l > r) return nullptr;
        TreeNode *curr = new TreeNode(preorder[ptr]);
        curr->left = build(preorder, ptr+1, preorderpos, 
                            inorder, l, inorderpos[preorder[ptr]] - 1, inorderpos);
        curr->right = build(preorder, ptr + inorderpos[preorder[ptr]] + 1 - l, 
                preorderpos, inorder, inorderpos[preorder[ptr]] + 1, r, inorderpos);

        return curr;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> preorderpos;
        unordered_map<int, int> inorderpos;
        for(int i = 0; i < inorder.size(); i++)
        {
            preorderpos[preorder[i]] = i;
            inorderpos[inorder[i]] = i;
        }
        return build(preorder, 0, preorderpos, inorder, 0, inorder.size()-1, inorderpos);
        
    }
};
