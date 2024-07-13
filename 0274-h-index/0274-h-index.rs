impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let mut citations = citations;
        citations.sort_by(|a, b| b.cmp(a));
        let mut index = 0;
        for i in 0..citations.len() {
            if citations[i] as usize >= i + 1 {
                index += 1;
            } else {
                break;
            }
        }
        index
    }
}