class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9, vector<int>(9, 0));
        vector<vector<int>> columns(9, vector<int>(9, 0));
        vector<vector<int>> grid(9, vector<int>(9, 0));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int k = i / 3 * 3 + j / 3;
                    if (rows[i][num - 1]++|| columns[j][num - 1]++ || grid[k][num - 1]++)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};