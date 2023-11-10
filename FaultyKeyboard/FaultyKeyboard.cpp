class Solution {
public:
    string finalString(string s) {
        string result = "";
        int i = 0;
        while (i < s.length()) {
            if (s[i] == 'i') {
                reverse(result.begin(), result.end());
            }
            else {
                result += s[i];
            }
            i++;
        }
        return result;
    }
};