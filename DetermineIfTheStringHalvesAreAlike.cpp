class Solution {
public:
    bool isVowel(char ch) {
        ch = std::toupper(ch);
        return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
    bool halvesAreAlike(string s) {
        int left = 0;
        int right = s.length() - 1;
        int vowelCount = 0;
        while (left < right) {
            if (isVowel(s[left])) vowelCount++;
            if (isVowel(s[right])) vowelCount--;
            left++;
            right--;
        }
        return vowelCount == 0;
    }
};