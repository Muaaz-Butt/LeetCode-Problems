use std::collections::HashMap;
impl Solution {
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        let mut result = Vec::new();
        if words.is_empty() || s.is_empty() {
            return result;
        }
        
        let word_len = words[0].len();
        let num_words = words.len();
        let total_len = word_len * num_words;
        if s.len() < total_len {
            return result;
        }
        
        let mut word_count = HashMap::new();
        for word in &words {
            *word_count.entry(word.clone()).or_insert(0) += 1;
        }
        
        for i in 0..word_len {
            let mut seen_words = HashMap::new();
            let mut left = i;
            let mut count = 0;
            
            for j in (i..=s.len() - word_len).step_by(word_len) {
                let word = s[j..j + word_len].to_string();
                if let Some(&word_count_val) = word_count.get(&word) {
                    *seen_words.entry(word.clone()).or_insert(0) += 1;
                    count += 1;
                    
                    while seen_words[&word] > word_count_val {
                        let left_word = s[left..left + word_len].to_string();
                        *seen_words.get_mut(&left_word).unwrap() -= 1;
                        count -= 1;
                        left += word_len;
                    }
                    
                    if count == num_words {
                        result.push(left as i32);
                    }
                } else {
                    seen_words.clear();
                    count = 0;
                    left = j + word_len;
                }
            }
        }
        
        result           
    }
}