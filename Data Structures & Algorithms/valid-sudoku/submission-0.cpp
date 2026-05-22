
#define bit(x) 1 << (x)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int boxs[9] = {0};

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;
                if (rows[i] & bit(board[i][j])) return false;
                    rows[i] |= bit(board[i][j]);
                if (cols[j] & bit(board[i][j])) return false;
                    cols[j] |= bit(board[i][j]);
                if (boxs[(i/3) * 3 + (j/3)] & bit(board[i][j])) return false;
                    boxs[(i/3) * 3 + (j/3)] |= bit(board[i][j]);
            }
        }
        return true;
    }
};
