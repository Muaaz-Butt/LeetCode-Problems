#include <iostream>

using namespace std;

int reverse(int x) {
	int result = 0;
	int rem = 0;
	while (x) {
		if (result > INT_MAX / 10 || result < INT_MIN / 10) {
			return 0;
		}
		rem = x % 10;
		result = result * 10 + rem;
		x /= 10;
	}
	return result;
}
