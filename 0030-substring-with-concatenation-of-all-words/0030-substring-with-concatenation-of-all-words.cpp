class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;
        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        if (s.length() < totalLen) return result;
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }
        for (int i = 0; i < wordLen; ++i) {
            unordered_map<string, int> seenWords;
            int left = i, count = 0;
            for (int j = i; j <= s.length() - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);
                if (wordCount.find(word) != wordCount.end()) {
                    seenWords[word]++;
                    count++;          
                    while (seenWords[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLen;
                    }          
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    seenWords.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        return result;
    }
};