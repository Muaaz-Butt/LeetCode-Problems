class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = n - 1;
        int sum = 0;
        int result;
        for (int i = 0; i < n - 2; i++) {
            left = i + 1;
            right = n - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == target) return target;
                else if (sum > target) right--;
                else left++;
                if (abs(sum - target) < abs(result - target)) result = sum;
            }
        }
        return result;
    }
};