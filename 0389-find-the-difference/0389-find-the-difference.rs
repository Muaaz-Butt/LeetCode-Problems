impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        let mut char_sum_s = 0;
        let mut char_sum_t = 0;

        for ch in s.chars() {
            char_sum_s += ch as u8;
        }

        for ch in t.chars() {
            char_sum_t += ch as u8;
        }

        (char_sum_t - char_sum_s) as char
    }
}