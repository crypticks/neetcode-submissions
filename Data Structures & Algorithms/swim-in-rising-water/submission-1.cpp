class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n,false));

        auto cmp = [](pair<vector<int>,int>& a, pair<vector<int>,int>& b){ return a.second > b.second; };
        priority_queue<pair<vector<int>,int>, vector<pair<vector<int>,int>>, decltype(cmp)> minheap(cmp);

        minheap.push({{0,0}, grid[0][0]});

        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        while(!minheap.empty())
        {
            auto curr = minheap.top();
            minheap.pop();
            int r = curr.first[0];
            int c = curr.first[1];
            visited[r][c] = true;
            for(auto& dir : dirs)
            {
                int nr = r + dir.first;
                int nc = c + dir.second;
                if(nr < 0 || nc < 0 || nr >= n || nc >= n || visited[nr][nc]) continue;
                if(nr == n-1 && nc == n-1) return max(grid[nr][nc], curr.second);
                minheap.push({{nr,nc}, max(grid[nr][nc], curr.second)});
            }

        }
        return 0;
    }
};
