use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut count = HashMap::new();
        
        for ch in s.chars() {
            *count.entry(ch).or_insert(0) += 1;
        }
        
        for ch in t.chars() {
            *count.entry(ch).or_insert(0) -= 1;
        }

        count.values().all(|&v| v == 0)
    }
}