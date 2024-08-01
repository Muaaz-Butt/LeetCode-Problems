use std::collections::HashMap;
impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let mut index_map: HashMap<i32, usize> = HashMap::new();

        for (i, &num) in nums.iter().enumerate() {
            if let Some(&prev_index) = index_map.get(&num) {
                if i - prev_index <= k as usize {
                    return true;
                }
            }
            index_map.insert(num, i);
        }

        false
    }
}