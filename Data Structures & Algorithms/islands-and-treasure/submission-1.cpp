class Solution {
public:
    vector<vector<bool>> visited;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 0) 
                {
                    visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
                    bfs(grid, i, j);
                }
            }
        }
        
    }

    void bfs(vector<vector<int>>& grid, int r, int c)
    {
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{r,c}, 0});
        while(!q.empty())
        {
            auto [first, k] = q.front();
            int i = first.first;
            int j = first.second;
            q.pop();
            if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()
            || visited[i][j] || grid[i][j] == -1)
            {
                continue;
            }
            grid[i][j] = min(k, grid[i][j]);
            visited[i][j] = true;
            q.push({{i+1, j}, k+1});
            q.push({{i-1, j}, k+1});
            q.push({{i, j+1}, k+1});
            q.push({{i, j-1}, k+1});


        }
    }
};
