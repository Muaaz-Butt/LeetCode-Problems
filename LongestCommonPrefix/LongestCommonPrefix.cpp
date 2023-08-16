class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string a;
		bool flag = true;
		int arrayLength = strs.size(), j = 0;
		int i;
		while (j < strs[0].length() && flag) {
			i = 0;
			flag = true;
			while (i < arrayLength && flag) {
				if (i == arrayLength - 1) {
					a += strs[0][j];
					//cout << a << "\n";
					i++;
				}
				else if (strs[0][j] == strs[i + 1][j] && j < strs[i + 1].length()) {
					i++;
				}
				else {
					flag = false;
				}
			}
			j++;
		}
		return a;
	}
};