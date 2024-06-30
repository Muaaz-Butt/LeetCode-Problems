use std::usize;

impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let mut sum: i32 = 0;
        let mut left= 0;
        let mut right = 0;
        let mut n = nums.len();
        let mut result = usize::MAX;

        while left < n || right < n {
            if sum < target && right < n {
                sum += nums[right];
                right += 1;
            } else if (sum >= target && left < n) {
                result = result.min(right - left);
                sum -= nums[left];
                left += 1;
            } else { 
                break;
            }
        }
        if result == usize::MAX {
            return 0;
        }
        result as i32
    }
}