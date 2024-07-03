use std::collections::VecDeque;

impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        if nums.is_empty() || k == 0 {
            return vec![];
        }

        let k = k as usize;
        let mut dq: VecDeque<usize> = VecDeque::new();
        let mut result: Vec<i32> = Vec::with_capacity(nums.len() - k + 1);

        for i in 0..nums.len() {
            if let Some(&front) = dq.front() {
                if front ==  i - k {
                    dq.pop_front();
                }
            }
            
            while let Some(&back) = dq.back() {
                if nums[back] < nums[i] {
                    dq.pop_back();
                } else {
                    break;
                }
            }

            dq.push_back(i);

            if i >= k - 1 {
                if let Some(&front) = dq.front() {
                    result.push(nums[front]);
                }
            }
        }
        result
    }
}