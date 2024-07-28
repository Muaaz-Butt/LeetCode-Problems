class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        rows, cols = len(board), len(board[0])
    
        directions = [(-1, -1), (-1, 0), (-1, 1), 
                  (0, -1),         (0, 1), 
                  (1, -1), (1, 0), (1, 1)]
    
        def count_live_neighbors(board, row, col):
            live_neighbors = 0
            for direction in directions:
                neighbor_row, neighbor_col = row + direction[0], col + direction[1]
                if 0 <= neighbor_row < rows and 0 <= neighbor_col < cols and abs(board[neighbor_row][neighbor_col]) == 1:
                    live_neighbors += 1
            return live_neighbors
    
        for row in range(rows):
            for col in range(cols):
                live_neighbors = count_live_neighbors(board, row, col)
                if board[row][col] == 1 and (live_neighbors < 2 or live_neighbors > 3):
                    board[row][col] = -1  
                if board[row][col] == 0 and live_neighbors == 3:
                    board[row][col] = 2   
    
        for row in range(rows):
            for col in range(cols):
                if board[row][col] == -1:
                    board[row][col] = 0  
                if board[row][col] == 2:
                    board[row][col] = 1
        