class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> set;
        for (auto x : s) {
            set[x]++;
        }
        for (auto x : t) {
            set[x]--;
        }
        for (auto x : set) {
            if (x.second != 0) {
                return false;
            }
        }
        return true;
    }
};