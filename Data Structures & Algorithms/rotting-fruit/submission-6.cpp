class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int depth = 0;
        while(fresh > 0 && !q.empty())
        {
            int size = q.size();
            for(int p = 0; p < size; p++)
            {
                auto [r, c] = q.front();
                q.pop();
                for(auto dir:dirs)
                {
                    int nr = r + dir.first;
                    int nc = c + dir.second;
                    if(nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()
                    || grid[nr][nc] != 1) 
                        continue;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh--;
                }

            }
            depth++;
        }

        return fresh == 0? depth : -1;
    }
};
