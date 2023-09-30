class Solution {
public:
	int search(vector<int>& nums, int target) {
		int start = 0;
		int end = nums.size() - 1;
		int mid;
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			if (nums[start] <= nums[mid]) {
				if (nums[mid] > target && nums[start] <= target) {
					end = mid - 1;
				}
				else {
					start = mid + 1;
				}
			}
			else {
				if (nums[mid] < target && target <= nums[end]) {
					start = mid + 1;
				}
				else {
					end = mid - 1;
				}
			}
		}
		return -1;
	}
};