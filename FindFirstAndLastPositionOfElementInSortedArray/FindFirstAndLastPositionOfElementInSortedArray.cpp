class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        int first = -1;
        int last = -1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                first = mid;
                last = mid;
                break;
            }
            else if (target > nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        while (first > 0 && nums[first - 1] == target) {
            first--;
        }
        while (last < nums.size() - 1 && nums[last + 1] == target) {
            last++;
        }
        return { first, last };
    }
};