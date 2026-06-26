class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<char>> grid;
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        int rows = grid.size();
        int cols = grid[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        int res = 0;
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                if(!visited[r][c] && grid[r][c] == '1')
                {
                    res++;
                    dfs(r,c);
                }
            }
        }
        return res;
        
    }

    void dfs(int r, int c)
    {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0' || visited[r][c])
            return;
        visited[r][c] = true;
        dfs(r+1, c);
        dfs(r-1, c);
        dfs(r, c+1);
        dfs(r, c-1);
    }
};
