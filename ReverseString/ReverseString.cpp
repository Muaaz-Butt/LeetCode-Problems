class Solution {
public:
    void reverseString(vector<char>& s) {
        int j = s.size() - 1;
        for (int i = 0; i < (j % 2 == 0 ? j : j + 1); i++) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            j--;
        }
    }
};