#include <iostream>

using namespace std;

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    int x = 1;
    int y = 2;
    int result = 0;
    for (int i = 3; i <= n; i++) {
        result = x + y;
        x = y;
        y = result;
    }
    return result;
}