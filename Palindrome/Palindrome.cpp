#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int original = x;
    long long int reverse = 0;
    int digit;
    while (x) {
        digit = x % 10;
        reverse = reverse * 10 + digit;
        x /= 10;
    }
    return original == reverse;
}
