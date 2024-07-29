class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> letterCount;
        
        for (char ch: magazine) {
            letterCount[ch]++;
        }
        
        for (char ch: ransomNote) {
            if (letterCount[ch] == 0) {
                return false;
            }
            letterCount[ch]--;
        }
        return true;
    }
};