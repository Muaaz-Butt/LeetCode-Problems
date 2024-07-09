class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

    unordered_map<char, int> t_freq, window_freq;
    
    for (char c : t) {
        t_freq[c]++;
    }
    
    int required = t_freq.size();
    int formed = 0;
    
    int left = 0, right = 0;
    int min_len = INT_MAX, start_idx = 0;

    while (right < s.size()) {
        char c = s[right];
        window_freq[c]++;
        
        if (t_freq.find(c) != t_freq.end() && window_freq[c] == t_freq[c]) {
            formed++;
        }
        
        while (left <= right && formed == required) {
            c = s[left];
            
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                start_idx = left;
            }
            
            window_freq[c]--;
            if (t_freq.find(c) != t_freq.end() && window_freq[c] < t_freq[c]) {
                formed--;
            }
            
            left++;
        }
        
        right++;
    }

    return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};