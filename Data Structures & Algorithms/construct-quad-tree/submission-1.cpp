/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node* construct(vector<vector<int>>& grid, int r, int c, int n) {
        int sum = 0;
        if (n <= 0)
            return nullptr;
        for (int i = r; i < r + n; i++) {
            for (int j = c; j < c + n; j++) {
                sum += grid[i][j];
            }
        }
        Node* ans;
        if (sum == 0 || sum == n *n) {
            ans = new Node(sum > 0, true);
            return ans;
        }
        ans = new Node(0, false);
        n /= 2;
        ans->topLeft = construct(grid, r, c, n);
        ans->topRight = construct(grid, r, c + n, n);
        ans->bottomLeft = construct(grid, r + n, c, n);
        ans->bottomRight = construct(grid, r + n, c + n, n);
        return ans;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return construct(grid, 0, 0, n);
    }
};