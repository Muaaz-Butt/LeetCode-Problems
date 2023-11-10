class Solution {
public:
    string trim(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') s.erase(i, i);
            else break;
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') s.erase(i, i);
            else break;
        }
        return s;
    }
    string reverseWords(string s) {
        bool flag = false;
        std::string temp = "";
        std::string result = "";
        int i = s.length() - 1;
        while (i >= 0) {
            if (isalnum(s[i])) {
                temp += s[i];
                flag = true;
            }
            else if (s[i] == ' ' && flag && i != s.length() - 1) {
                reverse(temp.begin(), temp.end());
                result += temp;
                temp = "";
                result += " ";
                flag = false;
            }
            if (i == 0 && temp != "") {
                reverse(temp.begin(), temp.end());
                result += temp;
            }
            i--;
        }
        result = trim(result);
        return result;
    }
};