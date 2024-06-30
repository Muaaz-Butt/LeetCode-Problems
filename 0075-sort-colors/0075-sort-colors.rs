impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        if nums.is_empty() {  
            return;
        }
        
        let mut i: usize = 0;
        let mut left: usize = 0;
        let mut right: usize = nums.len() - 1;
        
        while i <= right {
            if nums[i] == 0 {
                nums.swap(i, left);
                i += 1;
                left += 1;
            } else if nums[i] == 2 {
                nums.swap(i, right);
                if right == 0 { 
                    break;
                }
                right -= 1;
            } else {
                i += 1;
            }
        }
    }
}