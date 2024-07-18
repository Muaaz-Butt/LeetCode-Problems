impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        if nums.len() == 1{
            return nums[0];
        }

        let mut rob_current = nums[0];
        let mut skip_current = 0;

        for i in 1.. nums.len() {
            let temp = rob_current;
            rob_current = skip_current + nums[i];
            skip_current = std::cmp::max(skip_current, temp);
        }
        std::cmp::max(rob_current, skip_current)
    }
}