impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        if matrix.is_empty() {
        return;
        }

        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut row_zero = false;
        let mut col_zero = false;

        for i in 0..rows {
            if matrix[i][0] == 0 {
                col_zero = true;
            }
        }

        for j in 0..cols {
            if matrix[0][j] == 0 {
                row_zero = true;
            }
        }

        for i in 1..rows {
            for j in 1..cols {
                if matrix[i][j] == 0 {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for i in 1..rows {
            if matrix[i][0] == 0 {
                for j in 1..cols {
                    matrix[i][j] = 0;
                }
            }
        }

        for j in 1..cols {
            if matrix[0][j] == 0 {
                for i in 1..rows {
                    matrix[i][j] = 0;
                }
            }
        }

        if row_zero {
            for j in 0..cols {
                matrix[0][j] = 0;
            }
        }

        if col_zero {
            for i in 0..rows {
                matrix[i][0] = 0;
            }
        }
    }   
}