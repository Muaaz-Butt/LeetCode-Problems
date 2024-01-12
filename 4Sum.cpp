class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int left = j + 1, right = n - 1;
                while (left < right) {
                    if (nums[left] + nums[right] < newTarget) left++;
                    else if (nums[left] + nums[right] > newTarget) right--;
                    else {
                        result.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        int temp1 = left;
                        int temp2 = right;
                        while (left < right && nums[left] == nums[temp1])
                            left++;
                        while (left < right && nums[right] == nums[temp2])
                            right--;
                    }
                }
                while (j + 1 < n && nums[j] == nums[j + 1]) j++;
            }
            while (i + 1 < n && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }
};