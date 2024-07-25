impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let mut last_index = nums1.len() - 1;
        let mut n: usize = n as usize;
        let mut m: usize = m as usize; 
        while n > 0 && m > 0 {
            if nums1[m - 1] > nums2[n - 1] {
                nums1[last_index] = nums1[m - 1];
                m -= 1;
                last_index -= 1;
            } else {
            nums1[last_index] = nums2[n - 1];
            n -= 1;
            last_index-= 1;
            }
        }
        while n > 0 {
            nums1[last_index] = nums2[n - 1];
            last_index -= 1;
            n -= 1;
        }
    }
}