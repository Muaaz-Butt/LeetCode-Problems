class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        while (left < right) {
            int minimum = min(height[left], height[right]);
            int max = (right - left) * minimum;
            if (max > result) {
                result = max;
            }
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return result;
    }
};