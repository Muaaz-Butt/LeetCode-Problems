class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> r(min(numRows, static_cast<int>(s.size())));
        int currentRow = 0;
        bool flag = false;

        for (char c : s) {
            r[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) {
                flag= !flag;
            }
            currentRow += flag ? 1 : -1;
        }

    string result;
    for (const string& row : r) {
        result += row;
    }

    return result;
    }
};