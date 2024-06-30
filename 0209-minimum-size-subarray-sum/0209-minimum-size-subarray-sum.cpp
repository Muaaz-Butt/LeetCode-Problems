class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        int result = INT_MAX;
        while(left < n || right < n) {
            if (sum < target && right < n) {
                sum += nums[right];
                right++;
            } else if (sum >= target && left < n){
                result = min(result, right - left);
                sum -= nums[left];
                left++;
            } else{
                break;
            }
        }
        if (result == INT_MAX)
            return 0;
        
        return result;
    }
};