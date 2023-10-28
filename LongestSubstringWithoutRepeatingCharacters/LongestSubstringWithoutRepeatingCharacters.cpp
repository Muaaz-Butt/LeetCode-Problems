class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int count = 0;
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = k; j < i; j++) {
                if (s[j] == s[i]) {
                    k = j + 1;
                    break;
                }
            }
            count = max(count, i - k + 1);
        }
        return count;
    }
};