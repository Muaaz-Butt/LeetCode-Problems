impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut candidate = 0;
        let mut count = 0;
        for i in 0..nums.len() {
            if count == 0 {
                candidate = nums[i]
            }
            if candidate == nums[i] {
                count += 1;
            }
            if candidate != nums[i]{
                count -= 1;
            }
        }
        candidate
    }
}