use std::collections::HashMap;
impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut s_to_t = HashMap::new();
        let mut t_to_s = HashMap::new();

        for (char_s, char_t) in s.chars().zip(t.chars()){
            if let Some(&mapped_char_t) = s_to_t.get(&char_s) {
                if mapped_char_t != char_t{
                    return false;
                }
            } else {
                s_to_t.insert(char_s, char_t);
            }

            if let Some(&mapped_char_s) = t_to_s.get(&char_t) {
                if mapped_char_s != char_s {
                    return false;
                } 
            } else {
                    t_to_s.insert(char_t, char_s);
                }
        }
        true
    }
}