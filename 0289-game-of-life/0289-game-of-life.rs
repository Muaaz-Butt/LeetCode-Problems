impl Solution {
    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        let rows = board.len();
        let cols = board[0].len();
        
        let directions = vec![
            (-1, -1), (-1, 0), (-1, 1), 
            (0, -1),          (0, 1), 
            (1, -1), (1, 0), (1, 1)
        ];
        
        let count_live_neighbors = |board: &Vec<Vec<i32>>, row: isize, col: isize| -> i32 {
            let mut live_neighbors = 0;
            for direction in &directions {
                let neighbor_row = row + direction.0;
                let neighbor_col = col + direction.1;
                if neighbor_row >= 0 && neighbor_row < rows as isize && neighbor_col >= 0 && neighbor_col < cols as isize 
                    && board[neighbor_row as usize][neighbor_col as usize].abs() == 1 {
                    live_neighbors += 1;
                }
            }
            live_neighbors
        };
        
        let mut changes = vec![];
        
        for row in 0..rows {
            for col in 0..cols {
                let live_neighbors = count_live_neighbors(board, row as isize, col as isize);
                if board[row][col] == 1 && (live_neighbors < 2 || live_neighbors > 3) {
                    changes.push((row, col, 0));
                }
                if board[row][col] == 0 && live_neighbors == 3 {
                    changes.push((row, col, 1));
                }
            }
        }
        
        for (row, col, state) in changes {
            board[row][col] = state;
        }
    }
}