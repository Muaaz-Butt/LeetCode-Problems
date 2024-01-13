class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int robCurrent = nums[0];
        int skipCurrent = 0;
        for (int i = 1; i < nums.size(); i++) {
            int temp = robCurrent;
            robCurrent = skipCurrent + nums[i];
            skipCurrent = max(skipCurrent, temp);
        }
        return max(robCurrent, skipCurrent);
    }
};