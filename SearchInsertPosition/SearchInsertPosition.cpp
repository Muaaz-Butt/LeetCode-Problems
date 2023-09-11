class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int startingIndex = 0;
        int endingIndex = nums.size() - 1;
        if (nums[endingIndex] < target) {
            return endingIndex + 1;
        }
        if (nums[startingIndex] > target) {
            return 0;
        }
        int mid;
        bool flag = true;
        while (startingIndex <= endingIndex && flag) {
            mid = startingIndex + (endingIndex - startingIndex) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                endingIndex = mid - 1;
            }
            else {
                startingIndex = mid + 1;
            }
        }
        return startingIndex;
    }
};