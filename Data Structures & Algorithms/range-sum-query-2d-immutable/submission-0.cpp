class NumMatrix {
private:
    vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix) :  mat(matrix.size()+1, vector<int>(matrix[0].size()+1, 0)) {
        
        for(int i = matrix.size()-1; i >= 0; i--)
        {
            for(int j = matrix[0].size()-1; j >= 0; j--)
            {
                int s1 = this->mat[i][j+1];
                int s2 = this->mat[i+1][j];
                int s3 = this->mat[i+1][j+1];
                this->mat[i][j] = s1 + s2 - s3 + matrix[i][j];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return this->mat[row1][col1] + this->mat[row2+1][col2+1] - this->mat[row1][col2+1] - this->mat[row2+1][col1];
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */