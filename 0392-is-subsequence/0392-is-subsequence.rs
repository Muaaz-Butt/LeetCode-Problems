impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let mut s_iter = s.chars();
        let mut t_iter = t.chars();
        let mut s_char = s_iter.next();

        while let Some(t_char) = t_iter.next() {
            if Some(t_char) == s_char {
                s_char = s_iter.next();
            }
        }
        s_char.is_none()
    }    
}