class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, 
                                             {0, -1},          {0, 1}, 
                                             {1, -1}, {1, 0}, {1, 1}};
        
        auto count_live_neighbors = [&](int row, int col) {
            int live_neighbors = 0;
            for (const auto& direction : directions) {
                int neighbor_row = row + direction.first;
                int neighbor_col = col + direction.second;
                if (neighbor_row >= 0 && neighbor_row < rows && neighbor_col >= 0 && neighbor_col < cols 
                    && abs(board[neighbor_row][neighbor_col]) == 1) {
                    live_neighbors += 1;
                }
            }
            return live_neighbors;
        };
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int live_neighbors = count_live_neighbors(row, col);
                if (board[row][col] == 1 && (live_neighbors < 2 || live_neighbors > 3)) {
                    board[row][col] = -1;
                }
                if (board[row][col] == 0 && live_neighbors == 3) {
                    board[row][col] = 2;
                }
            }
        }
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == -1) {
                    board[row][col] = 0;
                }
                if (board[row][col] == 2) {
                    board[row][col] = 1;
                }
            }
        }
    }
};