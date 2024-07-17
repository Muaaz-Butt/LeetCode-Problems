impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let mut i = 0;
        let mut j = height.len() - 1;
        let mut left_max = height[0];
        let mut right_max = height[j];
        let mut trapped_water = 0;

        while i < j {
            if left_max <= right_max {
                trapped_water += (left_max - height[i]);
                i += 1;
                left_max = std::cmp::max(left_max, height[i]);
            } else { 
                trapped_water += (right_max - height[j]);
                j -= 1;
                right_max = std::cmp::max(right_max, height[j]);
            }
        }
        trapped_water
    }
}