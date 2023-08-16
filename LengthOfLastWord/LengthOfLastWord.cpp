#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
	int lengthOfLastWord(string s) {
		int i = 0, count = 0;
		while (i < s.length()) {
			if (!isalpha(s[i])) {
				i++;
			}
			else if (i > 0 && s[i - 1] == ' ') {
				count = 0;
				count++;
				i++;
			}
			else {
				count++;
				i++;
			}
		}
		return count;
	}
};
