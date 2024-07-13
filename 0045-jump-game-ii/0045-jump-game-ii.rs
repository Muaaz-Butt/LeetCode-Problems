impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        if nums.len() == 1 {
            return 0;
        }
        let mut jump = 0;
        let mut current_end = 0;
        let mut farthest = 0;

        for i in 0..nums.len() {
            let temp = nums[i] as usize + i;
            if temp > farthest {
                farthest = temp;
            }
            if i == current_end {
                current_end = farthest;
                jump += 1;
            }
            if current_end >= nums.len() - 1 {
                break;
            }
        }
        jump
    }
}