class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> skip(rows, vector<bool>(cols, false));
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if((i == 0 || j == 0 || i == rows - 1 || j == cols-1) && !skip[i][j] && board[i][j] == 'O')
                {
                    skip[i][j] = true;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        skip[r][c] = true;
                        for(auto dir : dirs)
                        {
                            int nr = r + dir.first;
                            int nc = c + dir.second;
                            if(nr >= 0 && nc >=0 && nr < rows && nc < cols && board[nr][nc] == 'O' && !skip[nr][nc]) {
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }
        for(int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(!skip[i][j]) board[i][j] = 'X';
            }
        }



    }
};
