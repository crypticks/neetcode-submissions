class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        // i = x / n    , j = x % n

        int l = 0, u = m * n;
        while(l < u)
        {
            int k = (l + u) / 2;
            if(matrix[k/n][k%n] > target) u = k;
            else if(matrix[k/n][k%n] < target) l = k + 1;
            else return true;
        }
        return false;
        
    }
};
