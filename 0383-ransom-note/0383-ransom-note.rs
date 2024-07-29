use std::collections::HashMap;

impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut letter_count = HashMap::new();

        for char in magazine.chars() {
            *letter_count.entry(char).or_insert(0) += 1;
        }

        for char in ransom_note.chars() {
            let count = letter_count.entry(char).or_insert(0);

            if *count == 0 {
                return false;
            }
            *count -= 1;
        }

        true
    }
}