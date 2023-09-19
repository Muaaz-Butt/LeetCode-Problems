class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> nums3(size1 + size2);
        int i = 0;
        int j = 0;
        while (i < nums3.size()) {
            if (i < size1) {
                nums3[i] = nums1[i];
            }
            else {
                nums3[i] = nums2[j];
                j++;
            }
            i++;
        }
        sort(nums3.begin(), nums3.end());
        int mid = nums3.size() / 2;
        if (nums3.size() % 2 == 1) {
            return nums3[mid];
        }
        return (nums3[mid - 1] + nums3[mid]) / 2.0;
    }
};