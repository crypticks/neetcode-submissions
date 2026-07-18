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
class BSTIterator {
private:
    vector<TreeNode*> inorder;
    int ptr;

    void in_trav(TreeNode* root)
    {
        if(!root) return;
        in_trav(root->left);
        inorder.push_back(root);
        in_trav(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        in_trav(root);
        ptr = -1;
    }
    
    int next() {
        return inorder[++ptr]->val;
    }
    
    bool hasNext() {
        return ptr == -1 || ptr < (inorder.size() - 1);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */