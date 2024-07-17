class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int leftMax = height[0];
        int rightMax = height[j];
        int trappedWater = 0;
        
        while (i < j) {
            if (leftMax <= rightMax) {
                trappedWater += leftMax - height[i];
                i++;
                leftMax = std::max(leftMax, height[i]);
            } else {
                trappedWater += rightMax - height[j];
                j--;
                rightMax = std::max(rightMax, height[j]);
            }
        }
        return trappedWater;
    }
};