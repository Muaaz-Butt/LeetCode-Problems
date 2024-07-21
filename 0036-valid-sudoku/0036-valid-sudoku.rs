impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut rows: Vec<Vec<i32>> = vec![vec![0; 9]; 9];
        let mut columns: Vec<Vec<i32>> = vec![vec![0; 9]; 9];
        let mut grid: Vec<Vec<i32>> = vec![vec![0; 9]; 9];

        for i in 0..board.len() {
            for j in 0..board[0].len() {
                if board[i][j] != '.' {
                    let num = (board[i][j] as u8 - b'0') as usize;
                    let k = i / 3 * 3 + j / 3;

                if rows[i][num - 1] > 0 || columns[j][num - 1] > 0 || grid[k][num - 1] > 0 {
                    return false;
                }
                
                rows[i][num - 1] += 1;
                columns[j][num - 1] += 1;
                grid[k][num - 1] += 1;
                }
            }
        }
        true
    }
}