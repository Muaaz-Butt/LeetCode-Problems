class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int count = nums.size();
        int j = count - 1;
        while (i <= j) {
            if (nums[i] == val) {
                count--;
                if (nums[j] != val) {
                    nums[i] = nums[j];
                    j--;
                    i++;
                }
                else {
                    j--;
                }
            }
            else {
                i++;
            }
        }
        return count;
    }
};