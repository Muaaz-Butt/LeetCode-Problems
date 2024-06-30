class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int left = 0;
        int right = nums.size() - 1;
        while(i <= right){
            if (nums[i] == 0){
                int temp = nums[i];
                nums[i] = nums[left];
                nums[left] = temp;
                i++;
                left++;  
            }
            else if (nums[i] == 2){
                int temp = nums[i];
                nums[i] = nums[right];
                nums[right] = temp;
                right--;
            }
            else{
                i++;
            }
        } 
    }
};