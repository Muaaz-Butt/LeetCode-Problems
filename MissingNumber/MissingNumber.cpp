class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        int sum = (n * (n - 1)) / 2;
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
        }
        return sum - s;
    }
};