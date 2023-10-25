class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        if (nums[left] < nums[right]) {
            return nums[left];
        }
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if (nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return nums[mid];
    }
};