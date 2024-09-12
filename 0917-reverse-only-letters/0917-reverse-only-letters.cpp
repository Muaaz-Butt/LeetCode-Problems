class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (isalpha(s[left]) && isalpha(s[right])){
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left += 1;
                right -= 1;
            }
            else if  (!isalpha(s[left]))
                left += 1;
            else 
                right -= 1;
        }
        return s;
    }
};