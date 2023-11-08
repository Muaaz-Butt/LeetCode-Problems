class Solution {
public:
    char findTheDifference(string s, string t) {
        int tSum = 0;
        int sSum = 0;
        for (int i = 0; i < t.length(); i++) {
            sSum += s[i];
            tSum += t[i];
        }
        return tSum - sSum;
    }
};