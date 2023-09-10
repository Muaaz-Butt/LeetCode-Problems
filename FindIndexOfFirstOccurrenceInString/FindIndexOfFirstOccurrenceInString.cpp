class Solution {
public:
    int strStr(string haystack, string needle) {
        bool flag = true;
        for (int i = 0; i < haystack.length(); i++)
        {
            if (haystack[i] == needle[0]) {
                flag = true;
                for (int j = 0; j < needle.length() && flag; j++) {
                    if (needle[j] != haystack[i + j]) {
                        flag = false;
                    }
                }
                if (flag) {
                    return i;
                }
            }
        }
        return -1;
    }
};