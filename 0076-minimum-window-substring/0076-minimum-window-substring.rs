use std::collections::HashMap;

impl Solution {
    pub fn min_window(s: String, t: String) -> String {
        let s_chars: Vec<char> = s.chars().collect();
        let t_chars: Vec<char> = t.chars().collect();
        
        if t_chars.len()  > s_chars.len() {
            return "".to_string();
        }
        
        let mut t_freq: HashMap<char, i32> = HashMap::new();
        let mut window_freq: HashMap<char, i32> = HashMap::new();

        for &c in &t_chars {
            *t_freq.entry(c).or_insert(0) += 1;
        }

        let required = t_freq.len();
        let mut formed = 0;
        let mut left = 0;
        let mut right = 0;
        let mut min_len = usize::MAX;
        let mut start_idx = 0;

        while right < s_chars.len() {
            let c = s_chars[right];
            *window_freq.entry(c).or_insert(0) += 1;

            if t_freq.contains_key(&c) && window_freq[&c] == t_freq[&c] {
                formed += 1;
            }

            while left <= right && formed == required {
                let c = s_chars[left];

                if right - left + 1 < min_len {
                    min_len = right - left + 1;
                    start_idx = left;
                }

                *window_freq.entry(c).or_insert(0) -= 1;
                if t_freq.contains_key(&c) && window_freq[&c] < t_freq[&c]{
                    formed -= 1;
                }

                left += 1;
            }
            right += 1;
        }
        if min_len == usize::MAX {
            "".to_string()
        } else {
            s_chars[start_idx..start_idx + min_len].iter().collect()
        }
    }
}