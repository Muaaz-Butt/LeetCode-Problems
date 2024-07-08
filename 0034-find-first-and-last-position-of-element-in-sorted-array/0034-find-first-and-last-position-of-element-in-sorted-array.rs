impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut left = 0;
        let mut right = nums.len() as i32 - 1;
        let mut first = -1;
        let mut last = -1;

        while left <= right {
            let mid = left + (right - left) / 2;
            if nums[mid as usize] == target {
                first = mid;
                last = mid;
                break;
            } else if target > nums[mid as usize] {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if first != -1 {
            while first > 0 && nums[(first - 1) as usize] == target {
                first -= 1;
            }

            while last < nums.len() as i32 - 1 && nums[(last + 1) as usize] == target {
                last += 1;
            }
        }

        vec![first, last]
    }
}
