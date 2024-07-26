use std::mem;

impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        for i in 0..matrix.len() {
            for j in 0..i {
                let temp = mem::take(&mut matrix[i][j]);
                matrix[i][j] = mem::replace(&mut matrix[j][i], temp);
            }
        }
        for row in matrix.iter_mut() {
            row.reverse();
        }
    }
}
