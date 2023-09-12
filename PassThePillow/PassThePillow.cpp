class Solution {
public:
	int passThePillow(int n, int time) {
		int index = 1;
		bool flag = true;
		for (int i = 1; i < time; i++) {
			if (flag) {
				if (index == n) {
					index--;
					flag = false;
				}
				else {
					index++;
				}
			}
			else {
				if (index == 1) {
					index++;
					flag = true;
				}
				else {
					index--;
				}
			}
		}
		return index;
	}
};