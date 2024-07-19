impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if (num_rows <= 1 || num_rows >= s.len() as i32) {
            return s;
        }
        
        let mut r: Vec<String> = vec![String::new(); num_rows as usize];
        let mut flag = false;
        let mut current_row: usize = 0;

        for c in s.chars() {
            if current_row == 0 || current_row==(num_rows - 1) as usize {
                flag = !flag;
            } 
            r[current_row].push(c);
            if flag {
                current_row += 1;
            } else {
                current_row -= 1;
            }
        }
        r.concat()
    }
}