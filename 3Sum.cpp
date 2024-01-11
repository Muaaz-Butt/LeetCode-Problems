class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                }
                else {
                    set.insert({ nums[i], nums[left], nums[right] });
                    left++;
                    right--;
                }
            }
        }
        for (auto i : set) {
            result.push_back(i);
        }
        return result;
    }
};