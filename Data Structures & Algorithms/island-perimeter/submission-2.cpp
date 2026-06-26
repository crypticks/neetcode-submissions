class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    int islandPerimeter(vector<vector<int>>& grid) {
        this->grid = grid;
        int rows = grid.size();
        int cols = grid[0].size();
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < rows; i++)
        { 
            for(int j = 0; j < cols; j++)
            {
                if (grid[i][j]) return dfs(i, j);
            }
        }
        
        
        return 0;
    }

    int dfs(int r, int c)
    {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || !grid[r][c])
        {
            return 1;
        }
        if(visited[r][c]) return 0;
        visited[r][c] = true;
        return dfs(r+1, c) + dfs(r, c+1) + dfs(r-1, c) + dfs(r, c-1);
    }
};